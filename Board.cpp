#include "Board.h"

Board::Board(int x, int y)
{
    _x = x;
    _y = y;
    _board = new int[_x * _y];
	_ball = *(new Ball(x / 2, y / 2));
	_player1 = *(new Player(y/3, 1, y / 2 - y / 3));
	_player2 = *(new Player(y/3, x-2, y / 2 - y / 3));
	clear();
	draw();
}

Board::~Board()
{
    delete _board;
}

void Board::setChar(int x, int y, int type)
{
    _board[y * _x + x] = type;
}

void Board::clear()
{
    for (int i = 0; i < _y * _x; i++)
        _board[i] = 0;
}

void Board::draw()
{
	setChar(_ball.getX(), _ball.getY(), 1);
	for (int i = 0; i < _player1.getLength(); i++)
	{
		setChar(_player1.getX(), _player1.getY() + i, 2);
	}
	for (int i = 0; i < _player2.getLength(); i++)
	{
		setChar(_player2.getX(), _player2.getY() + i, 2);
	}
}

void Board::reset(bool resetScores)
{
	if (_board != nullptr)
		delete _board;

	_board = new int[_x * _y];
	_ball = *(new Ball(_x / 2, _y / 2));
	_player1.setPosition(1, _y / 2 - _y / 4);
	_player2.setPosition(_x - 2, _y / 2 - _y / 4);

	if (resetScores)
	{
		_player1.resetScore();
		_player2.resetScore();
	}

	clear();
	draw();
}

int Board::update(int y1, int y2)
{
	// Players movement
	if (y1 == 1)
	{
		if (_player1.getY() > 0)
			_player1.moveUp();
	}
	else if (y1 == -1)
	{
		if ((_player1.getY() + _player1.getLength()) < _y)
			_player1.moveDown();
	}

	if (y2 == 1)
	{
		if (_player2.getY() > 0)
			_player2.moveUp();
	}
	else if (y2 == -1)
	{
		if ((_player2.getY() + _player2.getLength()) < _y)
			_player2.moveDown();
	}


	// Ball movement
	_ball.updatePosition();
	int* curPosition = _ball.getPosition();

	// Collision with players
	if (curPosition[0] == (_player1.getX()+1)
		&& curPosition[1] <= (_player1.getY() + _player1.getLength())
		&& curPosition[1] >= _player1.getY()-1)
	{
		if (curPosition[1] > (_player1.getY() + _player1.getLength() / 2))
			_ball.setDirection(BOTTOM_RIGHT);
		else if (curPosition[1] < (_player1.getY() + _player1.getLength() / 2))
			_ball.setDirection(TOP_RIGHT);
		else
			_ball.setDirection(RIGHT);
	}
	else if (curPosition[0] == (_player2.getX() - 1)
		&& curPosition[1] <= (_player2.getY() + _player2.getLength())
		&& curPosition[1] >= _player2.getY()-1)
	{
		if (curPosition[1] > (_player2.getY() + _player2.getLength() / 2))
			_ball.setDirection(BOTTOM_LEFT);
		else if (curPosition[1] < (_player2.getY() + _player2.getLength() / 2))
			_ball.setDirection(TOP_LEFT);
		else
			_ball.setDirection(LEFT);
	}

	// Collision with walls
	if (curPosition[0] == _x - 1)
	{
		_player2.addScore();
		return 2;
	}
	else if (curPosition[0] == 0)
	{
		_player1.addScore();
		return 1;
	}
	else if (curPosition[1] == 0)
	{
		switch (_ball.getDirection())
		{
		case TOP_LEFT:
			_ball.setDirection(BOTTOM_LEFT);
			break;
		case TOP_RIGHT:
			_ball.setDirection(BOTTOM_RIGHT);
			break;
		default:
			break;
		}
	}
	else if (curPosition[1] == _y - 1)
	{
		switch (_ball.getDirection())
		{
		case BOTTOM_LEFT:
			_ball.setDirection(TOP_LEFT);
			break;
		case BOTTOM_RIGHT:
			_ball.setDirection(TOP_RIGHT);
			break;
		default:
			break;
		}
	}

	clear();
	draw();

    return 0;
}

int Board::getCoordinate(int x, int y)
{
	return _board[y * _x + x];
}
