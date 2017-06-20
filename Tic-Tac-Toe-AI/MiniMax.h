#pragma once
#include <string>
using namespace std;

string switchuser(string Turn) {
	if (Turn == "X") return "O";
	else if (Turn == "O") return "X";
}

int minimax(string board[3][3], string player) {
	int bestmove[2] = { -1,-1 };
	int Score = -100;
	for (int i; i < 3; i++) {
		for (int j; j < 3; j++) {
			if (board[i][j] == " ") {
				board[i][j] = player;
				int thisScore = -minimax(board, switchuser(player));
				if (thisScore > Score) {
					Score = thisScore;
					bestmove[0] = i;
					bestmove[1] = j;
				}
				board[i][j] = " ";
			}
		}
	}
	if (bestmove[0] == -1 && bestmove[1] == -1) return 0;
	return Score;
}