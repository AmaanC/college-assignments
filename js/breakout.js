var canvas = document.getElementById('c');
var ctx = canvas.getContext('2d');
var BLOCK_WIDTH = 30;
var BLOCK_HEIGHT = 10;
var blocks = [];
var paddle = {};
paddle.x = canvas.width / 2;
paddle.y = 350;
paddle.width = 30;
paddle.height = 10;
var ball = {};
ball.x = canvas.width / 2;
ball.y = canvas.height / 2;
ball.width = ball.height = 10;
ball.dx = 5;
ball.dy = 5;


var randColor = function() {
	return Math.floor(Math.random() * 255);
};

var createBlock = function(row, column) {
	var obj = {};
	obj.x = column * BLOCK_WIDTH;
	obj.y = row * BLOCK_HEIGHT;
	obj.width = BLOCK_WIDTH;
	obj.height = BLOCK_HEIGHT;
	obj.color = 'rgb(' + randColor() + ',' + randColor() + ',' + randColor() + ')';
	return obj;
};

var makeBlocks = function(rows, columns) {
	if (!rows) {
		rows = 4;
	}
	if (!columns) {
		columns = Math.floor(canvas.width / BLOCK_WIDTH);
	}
	for (var i = 0; i < columns; i++) {
		blocks[i] = [];
		for (var j = 0; j < rows; j++) {
			blocks[i][j] = createBlock(j, i);
		}
	}
};

var logicBlocks = function() {
	for (var i = 0; i < blocks.length; i++) {
		for (var j = 0; j < blocks[i].length; j++) {
			if (!blocks[i][j].dead && colliding(ball, blocks[i][j])) {
				blocks[i][j].dead = true;
				ball.dy *= -1;
			}
		}
	}
};

var drawBlocks = function() {
	for (var i = 0; i < blocks.length; i++) {
		for (var j = 0; j < blocks[i].length; j++) {
			block = blocks[i][j];
			if (block.dead) {
				continue;
			}
			ctx.fillStyle = block.color;
			ctx.fillRect(block.x, block.y, BLOCK_WIDTH, BLOCK_HEIGHT);
		}
	}
};

var drawPaddle = function() {
	ctx.fillStyle = 'red';
	ctx.fillRect(paddle.x - paddle.width / 2, paddle.y, paddle.width, paddle.height);
};

var drawBall = function() {
	ctx.fillStyle = 'blue';
	ctx.fillRect(ball.x, ball.y, ball.width, ball.height);
};

var colliding = function(one, two) {
	if (
		(one.x + one.width >= two.x && one.x <= two.x + two.width) &&
		(one.y + one.height >= two.y && one.y <= two.y + two.height)
	) {
		return true;
	}
	return false;
};

var logicBall = function() {
	ball.x += ball.dx;
	ball.y += ball.dy;

	if (ball.x >= canvas.width || ball.x <= 0) {
		ball.dx *= -1;
	}
	if (ball.y >= canvas.height || ball.y <= 0) {
		ball.dy *= -1;
	}

	if (colliding(ball, paddle)) {
		ball.y = paddle.y - ball.height;
		ball.dy *= -1;
	}
};

var draw = function() {
	var block;
	ctx.clearRect(0, 0, canvas.width, canvas.height);
	logicBlocks();
	drawBlocks();
	drawPaddle();
	logicBall();
	drawBall();
};

var loop = function() {
	draw();
	requestAnimationFrame(loop);
};

var init = function() {
	makeBlocks();
	document.body.addEventListener('mousemove', function(e) {
		paddle.x = e.pageX;
	}, false);
};

init();
loop();