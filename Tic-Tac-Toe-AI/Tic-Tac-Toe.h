#pragma once
#include <string>

using namespace std;

class Tic_Tac_Toe{
private:
	string board[3][3];
	
	string whoTurn = "O"; // first is true

public:
	Tic_Tac_Toe();
	bool checkWinner();
	bool isFull();

	void addMove(int);
	void clearBoard();
	void printBoard();
	void aiGaLogic();
	void gameLogic();

	int getInput();
};