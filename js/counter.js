var FlipFlop = function() {
  var ff = {};
  ff.prevQ = 0;
  ff.nextQ = 0;

  ff.process = function(j, k, triggered) {
    var temp = ff.prevQ;
    ff.prevQ = ff.nextQ;
    if (j === 0 && k === 0) {
      ff.nextQ = temp;
    }
    else if (j === 0 && k === 1) {
      ff.nextQ = 0;
    }
    else if (j === 1 && k === 0) {
      ff.nextQ = 1;
    }
    else if (j === 1 && k === 1 && triggered === true) {
      ff.nextQ = !ff.prevQ;
    }
    return Number(ff.nextQ);
  };
  return ff;
};

var ff0 = new FlipFlop();
var ff1 = new FlipFlop();

var clear = function() {
  J = 0;
  K = 1;
  isTriggered = true;
  justCleared = true;
  prevContents = state.textContent = '';
};

var stateElem = document.getElementById('state');
var isTriggered = false;

document.getElementById('trigger').addEventListener('mousedown', function() {
  isTriggered = true;
});
document.getElementById('up').addEventListener('mousedown', function() {
  clear();
  countingDown = false;
});
document.getElementById('down').addEventListener('mousedown', function() {
  clear();
  countingDown = true;
});
document.getElementById('clear').addEventListener('mousedown', clear);

var justCleared = false;
var prevQ0 = 0;
var Q0 = 0;
var J = 1;
var K = 1;
var prevContents = '';
var countingDown = false;
var loop = function() {
  if (isTriggered && !justCleared) {
    prevContents = state.textContent + ', ';
  }
  
  prevQ0 = Q0;
  Q0 = ff0.process(J, K, isTriggered);
  if (prevQ0 > Q0) {
    console.log('ff1 triggered');
    ff1.isTriggered = true;
  }
  Q1 = ff1.process(J, K, ff1.isTriggered);
  
  var o1 = Q1;
  var o0 = Q0;
  
  if (countingDown) {
    o1 = Number(!o1);
    o0 = Number(!o0);
  }
  
  state.textContent = prevContents + o1 + '' + o0;
  if (isTriggered) {
    isTriggered = false;
  }
  if (ff1.isTriggered) {
    ff1.isTriggered = false;
  }
  
  if (justCleared) {
    J = K = 1;
    justCleared = false;
  }
  
  setTimeout(loop, 100);
};

loop();