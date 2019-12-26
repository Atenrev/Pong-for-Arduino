enum Direction 
{
	TOP_LEFT = 0,
	TOP = 1,
	TOP_RIGHT = 2,
	RIGHT = 3,
	BOTTOM_RIGHT = 4,
	BOTTOM = 5,
	BOTTOM_LEFT = 6,
	LEFT = 7
};

class Ball
{
public:
	Ball();
    Ball(int x, int y);
	~Ball() {}

	void randomDirection();
    void updatePosition();

    int *getPosition();
    int getX() { return _x; }
    int getY() { return _y; }
	void setDirection(Direction newDirection) { _direction = newDirection; }
	Direction getDirection() { return _direction; }

private:
	int _x, _y;
	Direction _direction;
};
