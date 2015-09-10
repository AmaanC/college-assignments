var FlipFlop = function() {
    var ff = {};
    ff.prevQ = 0;
    ff.nextQ = 0;
    ff.isTriggered = false;
    ff.connection = {};

    ff.process = function(j, k) {
        var prevOutput = ff.prevQ;
        ff.prevQ = ff.nextQ;
        if (j === 0 && k === 0) {
            ff.nextQ = prevOutput;
        }
        else if (j === 0 && k === 1) {
            ff.nextQ = 0;
        }
        else if (j === 1 && k === 0) {
            ff.nextQ = 1;
        }
        else if (j === 1 && k === 1 && ff.isTriggered === true) {
            ff.nextQ = !ff.prevQ;
        }
        if (ff.isTriggered === true) {
            ff.isTriggered = false;
        }

        if (ff.connection && ff.prevQ > ff.nextQ) { // Negative edge triggered
            ff.connection.isTriggered = true;
        }
        return Number(ff.nextQ);
    };

    ff.trigger = function() {
        ff.isTriggered = true;
    }

    ff.connectTo = function(obj) {
        ff.connection = obj;
    };
    return ff;
};

var ff0 = new FlipFlop();
var ff1 = new FlipFlop();
ff0.connectTo(ff1);

var clear = function() {
    ff0.nextQ = 0;
    ff1.nextQ = 0;
    justCleared = true;
    prevContents = state.textContent = '';
    q0History = [];
    q1History = [];
    clockHistory = [];
    tick();
};

var stateElem = document.getElementById('state');

document.getElementById('trigger').addEventListener('mousedown', function() {
    ff0.trigger();
    tick();
});
document.getElementById('up').addEventListener('mousedown', function() {
    countingDown = false;
    clear();
});
document.getElementById('down').addEventListener('mousedown', function() {
    countingDown = true;
    clear();
});
document.getElementById('clear').addEventListener('mousedown', clear);

var justCleared = false;
var prevQ0 = 0;
var Q0 = 0;
var J = 1;
var K = 1;
var prevContents = '';
var countingDown = false;

var clockHistory = [];
var q0History = [];
var q1History = [];

var tick = function() {
    if (!justCleared && ff0.isTriggered) {
        prevContents = state.textContent + ', ';
    }
    if (ff0.isTriggered) {
        clockHistory.push(1);
    }
    
    prevQ0 = Q0;
    Q0 = ff0.process(J, K);
    Q1 = ff1.process(J, K);
    
    var o1 = Q1;
    var o0 = Q0;
    
    if (countingDown) {
        o1 = Number(!o1);
        o0 = Number(!o0);
    }

    clockHistory.push(0);
    q1History.push(o1);
    q1History.push(o1);
    q0History.push(o0);
    q0History.push(o0);
    
    state.textContent = prevContents + o1 + '' + o0;
    
    if (justCleared) {
        J = K = 1;
        justCleared = false;
    }

};



var canvas = document.getElementById('waveforms');
var ctx = canvas.getContext('2d');
var STEP_SIZE = 30;
var HIGH_HEIGHT = 20;

var drawWaveform = function(x, y, historyArr) {
    // Draws a waveform given a history array and positions
    if (historyArr.length <= 0) {
        return;
    }
    ctx.beginPath();
    ctx.moveTo(x, y - HIGH_HEIGHT * historyArr[0]);
    for (var i = 0; i < historyArr.length; i++) {
        ctx.lineTo(x + STEP_SIZE * i, y - HIGH_HEIGHT * historyArr[i]);
        ctx.lineTo(x + STEP_SIZE * (i + 1), y - HIGH_HEIGHT * historyArr[i]);
    }
    ctx.stroke();
};

var drawLoop = function() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    ctx.fillText('Clock', 0, 30);
    drawWaveform(30, 30, clockHistory);

    ctx.fillText('Q0', 0, 70);
    drawWaveform(30, 70, q0History);

    ctx.fillText('Q1', 0, 110);
    drawWaveform(30, 110, q1History);

    requestAnimationFrame(drawLoop);
};

tick();
drawLoop();