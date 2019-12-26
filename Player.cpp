#include "Player.h"

Player::Player()
{
	_length = 0;
	_x = 0;
	_y = 0;
	_score = 0;
}

Player::Player(int length, int x, int y)
{
	_length = length;
	_score = 0;
	setPosition(x, y);
}

void Player::moveUp()
{
	_y--;
}

void Player::moveDown()
{
	_y++;
}

void Player::addScore()
{
	_score++;
}

void Player::resetScore()
{
	_score = 0;
}

void Player::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}
