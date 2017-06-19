#pragma once
#include <string>

using namespace std;

class Tic_Tac_Toe{
private:
	string board[3][3];
	
	string whoTurn = "O"; // first is O's turn

public:
	Tic_Tac_Toe();
	bool checkWinner();
	bool isFull();

	void addMove(int);
	void clearBoard();
	void printBoard();

	void aiGaLogic();
	int gameLogic();

	int getInput();
	
	~Tic_Tac_Toe();
};