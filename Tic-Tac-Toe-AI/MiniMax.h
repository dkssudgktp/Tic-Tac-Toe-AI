#pragma once
#include <string>
using namespace std;

string switchuser(string Turn) {
	if (Turn == "X") return "O";
	else if (Turn == "O") return "X";
}

int minimax(string board[9], string player) {
	int bestmove = -1;
	int Score = -100;
	for (int i; i < 9; i++) {
			if (board[i] == " ") {
				board[i] = player;
				int thisScore = -minimax(board, switchuser(player));
				if (thisScore > Score) {
					Score = thisScore;
					bestmove = i;
				}
				board[i] = " ";
			}
		
	}
	if (bestmove == -1) return 0;
	return Score;
}