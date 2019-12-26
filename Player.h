class Player
{
public:
	Player();
	Player(int length, int x, int y);
	~Player() {}

	void moveUp();
	void moveDown();
	void addScore();
	void resetScore();

	void setPosition(int x, int y);
	int getLength() { return _length; }
	int getX() { return _x; }
	int getY() { return _y; }
	int getScore() { return _score; }

private:
	int _x, _y, _length, _score;
};