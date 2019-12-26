#include "Ball.h"
#include <stdlib.h>

Ball::Ball()
{
	_x = 0;
	_y = 0;
	randomDirection();
}

Ball::Ball(int x, int y)
{
    _x = x;
    _y = y;
	randomDirection();
}

void Ball::randomDirection()
{
	_direction = ((Direction) (rand() % 8));
	while (_direction == TOP || _direction == BOTTOM)
		_direction = ((Direction)(rand() % 8));
}

void Ball::updatePosition()
{
	switch (_direction)
	{
	case TOP_LEFT:
		_x--;
		_y--;
		break;
	case TOP:
		_y--;
		break;
	case TOP_RIGHT:
		_y--;
		_x++;
		break;
	case RIGHT:
		_x++;
		break;
	case BOTTOM_RIGHT:
		_x++;
		_y++;
		break;
	case BOTTOM:
		_y++;
		break;
	case BOTTOM_LEFT:
		_y++;
		_x--;
		break;
	case LEFT:
		_x--;
		break;
	default:
		break;
	}
}

int *Ball::getPosition()
{
    return new int[2]{_x, _y};
}
