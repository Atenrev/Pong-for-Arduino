#ifndef Board_h
#define Board_h

#include "Ball.h"
#include "Player.h"

#include "Arduino.h"

class Board
{
public:
    Board() : _x(0), _y(0), _board(nullptr) {}
    Board(int x, int y);
    ~Board();

    void setChar(int x, int y, int type);
    void clear();
	void draw();
	void reset(bool resetScores);
    int update(int y1, int y2);

	int* getBoard() { return _board; }
  Player getPlayer1() { return _player1; }
  Player getPlayer2() { return _player2; }
	int getCoordinate(int x, int y);

private:
    int _x,
        _y;
    int *_board;
    Ball _ball;
	Player _player1, _player2;
};

#endif
