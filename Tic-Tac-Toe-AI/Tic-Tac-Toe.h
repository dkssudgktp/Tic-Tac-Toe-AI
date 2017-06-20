#pragma once
#include <string>

using namespace std;

class Tic_Tac_Toe{
private:
	string board[9];
	
	string whoTurn = "O"; // first is O's turn

public:
	Tic_Tac_Toe(); // constructor
	bool checkWinner();
	bool isFull();

	void addMove(int);
	void clearBoard();
	void printBoard();

	void aiGaLogic();

	string switchuser(string);

	int gameLogic();
	int getInput();

	
	~Tic_Tac_Toe(); //destructor
};