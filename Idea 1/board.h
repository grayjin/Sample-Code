#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>

class Board {
	char **board;
	int *columnHeights;
	const int WIDTH = 7;
	const int HEIGHT = 7;

	bool checkHorizontal(int x, int y, char c);
	bool checkVertical(int x, int y, char c);
	bool checkLeftDiagonal(int x, int y, char c);
	bool checkRightDiagonal(int x, int y, char c);
public:
	Board();
	bool playerMove(int player, int x);
	bool checkFull();
	bool checkVictory(int x);
	~Board();

	friend std::ostream& operator << (std::ostream& out, Board& b);
};

#endif