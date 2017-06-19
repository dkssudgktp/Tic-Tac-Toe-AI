#pragma once
#include <string>

using namespace std;

class Tic_Tac_Toe{
private:
	string board[3][3];
public:
	Tic_Tac_Toe();
	bool checkWinner();


	void clearBoard();
	void printBoard();
	void gameLogic();

	int getInput();
};