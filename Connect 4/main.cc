#include <iostream>
#include <string>
#include "board.h"
using namespace std;

int main() {
	int player = 1;
	int size = 0;
	
	cout << "Welcome to Connect 4!" << endl;
	
	Board b;
	cout << b << endl;

	while (true) {
		cout << "Player "<< player << "'s move:" << endl;
		int column;

		while (true) {
			cin >> column;
			--column;
			if (b.playerMove(player, column)) {
				break;
			}
			cout << "Invalid Move! Try Again!" << endl;
		}
		cout << endl;
		cout << b << endl;

		if (b.checkVictory(column)) {
			cout << "Player " << player << " wins!" << endl;
			break;
		}
		if (b.checkFull()) {
			cout << "Game ends in a draw!" << endl;
			break;
		}

		if (player == 1) {
			player = 2;
		} 
		else {
			player = 1;
		}
	}
	int l;
	cin >> l;
}