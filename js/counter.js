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
    J = 0;
    K = 1;
    ff0.trigger();
    justCleared = true;
    prevContents = state.textContent = '';
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
var tick = function() {
    if (!justCleared && ff0.isTriggered) {
        prevContents = state.textContent + ', ';
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
    
    state.textContent = prevContents + o1 + '' + o0;
    
    if (justCleared) {
        J = K = 1;
        justCleared = false;
    }
    
};

tick();