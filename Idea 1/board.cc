#include "board.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

Board::Board() {
	board = new char*[HEIGHT];

	for (int i = 0; i < HEIGHT; i++) {
		board[i] = new char[WIDTH];
		for (int j = 0; j < WIDTH; j++) {
			if (i == 0) {
				board[i][j] = '0' + (j + 1);
			}
			else {
				board[i][j] = '.';
			}
		}
	}

	columnHeights = new int[WIDTH];

	for (int i = 0; i < HEIGHT; i++) {
		columnHeights[i] = 6;
	}
}

bool Board::playerMove(int player, int x) {
	int &n = columnHeights[x];

	if (x < 0 || x >= 7 || n == 0) {
		return false;
	}
	else {
		char c = 'X';
		if (player == 2) {
			c = 'O';
		}
		board[n][x] = c;
		n -= 1;
		return true;
	}
}

bool Board::checkHorizontal(int x, int y, char c) {
	int n = 0;

	for (int i = x; i < WIDTH; i++) {
		if (board[y][i] != c) {
			break;
		}
		n += 1;
	}

	for (int i = x-1; i >= 0; i--) {
		if (board[y][i] != c) {
			break;
		}
		n += 1;
	}

	return (n >= 4);
}

bool Board::checkVertical(int x, int y, char c) {
	int n = 0;

	for (int i = y; i < HEIGHT; i++) {
		if (board[i][x] != c) {
			break;
		}
		n += 1;
	}

	return (n >= 4);
}

bool Board::checkLeftDiagonal(int x, int y, char c) {
	int n = 0;

	for (int i = y, j = x; i < WIDTH && j < HEIGHT; i++, j++) {
		if (board[i][j] != c) {
			break;
		}
		n += 1;
	}

	for (int i = y-1, j = x-1; i >= 0 && i >= 0; i--, j--) {
		if (board[i][j] != c) {
			break;
		}
		n += 1;
	}

	return (n >= 4);
}

bool Board::checkRightDiagonal(int x, int y, char c) {
	int n = 0;

	for (int i = y, j = x; i >= 0 && j < WIDTH; i--, j++) {
		if (board[i][j] != c) {
			break;
		}
		n += 1;
	}

	for (int i = y + 1, j = x - 1; i < HEIGHT && i >= 0; i++, j--) {
		if (board[i][j] != c) {
			break;
		}
		n += 1;
	}

	return (n >= 4);
}

bool Board::checkVictory(int x) {
	int y = columnHeights[x] + 1;
	char c = board[y][x];
	return (checkHorizontal(x, y, c) || checkVertical(x, y, c) || 
		checkLeftDiagonal(x, y, c) || checkRightDiagonal(x, y, c));
}

bool Board::checkFull() {
	bool isFull = true;

	for (int i = 0; i < WIDTH; i++) {
		if (columnHeights != 0) {
			isFull = false;
			break;
		}
	}

	return isFull;
}

ostream& operator<<(ostream& out, Board& b) {
	for (int i = 0; i < b.HEIGHT; i++) {
		for (int j = 0; j < b.WIDTH; j++) {
			out << b.board[i][j];
		}
		out << endl;
	}

	return out;
}

Board::~Board() {
	for (int i = 0; i < HEIGHT; i++) {
		delete[] board[i];
	}

	delete[]columnHeights;
}