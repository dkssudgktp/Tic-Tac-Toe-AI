#include <iostream>
#include <stdlib.h>
#include "Tic-Tac-Toe.h"
#include "MiniMax.h"

#define CLS system("cls");

using namespace std;

Tic_Tac_Toe::Tic_Tac_Toe() { // constructor
	clearBoard();
}

Tic_Tac_Toe::~Tic_Tac_Toe() {
	cout << "END Game" << endl;
}

void Tic_Tac_Toe::clearBoard(void) { // reset game board
	for (int i = 0,size = 3; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = " ";
		}
	}
}


void Tic_Tac_Toe::printBoard(void) { // print board 
	cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "---------" << endl;
	cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "---------" << endl;
	cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool Tic_Tac_Toe::isFull(void) { // check board is full
	for (int i = 0, size = 3; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == " ") return false;
		}
	}
	return true;
}

bool Tic_Tac_Toe::checkWinner(void) { // game winner check
	if (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != " ")
		return true;
	else if (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != " ")
		return true;
	else if (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != " ")
		return true;

	else if (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != " ")
		return true;
	else if (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != " ")
		return true;
	else if (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != " ")
		return true;

	else if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != " ")
		return true;
	else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != " ")
		return true;
	else
		return false;
}

int Tic_Tac_Toe::getInput(void) { // input user number
	int number;
	cout<< whoTurn << "'s Turn input number [1~0] : ";
	cin >> number;
	return number;
}
void Tic_Tac_Toe::addMove(int getNumber) { // board add user
	if (getNumber == 1 && board[0][0] == " ") board[0][0] = whoTurn;
	else if(getNumber == 2 && board[0][1] == " ") board[0][1] = whoTurn;
	else if (getNumber == 3 && board[0][2] == " ") board[0][2] = whoTurn;
	else if (getNumber == 4 && board[1][0] == " ") board[1][0] = whoTurn;
	else if (getNumber == 5 && board[1][1] == " ") board[1][1] = whoTurn;
	else if (getNumber == 6 && board[1][2] == " ") board[1][2] = whoTurn;
	else if (getNumber == 7 && board[2][0] == " ") board[2][0] = whoTurn;
	else if (getNumber == 8 && board[2][1] == " ") board[2][1] = whoTurn;
	else if (getNumber == 9 && board[2][2] == " ") board[2][2] = whoTurn;
}

string Tic_Tac_Toe::switchuser(string Turn) {
	if (Turn == "X") return "O";
	else if (Turn == "O") return "X";
}

void Tic_Tac_Toe::aiGaLogic(void) { //ai game logic
	int score = -1;
	int move[2] = { -1, -1 };
	for (int i; i < 3; i++) {
		for (int j; j < 3; j++) {
			if (board[i][j] == " ") {
				board[i][j] = whoTurn;
				int TempScore = -minimax(board, switchuser(whoTurn));
				board[i][j] = " ";
				if (TempScore > score) {
					score = TempScore;
					move[0] = i;
					move[1] = j;
				}
			}
		}
	}
	board[move[0]][move[1]]= whoTurn;
}

int Tic_Tac_Toe::gameLogic(void) { // basic game logic
	int i = 1;
	while (!isFull()){
		printBoard();
		aiGaLogic();
		/*if (i%1 == 0){
			addMove(getInput());
		}
		else{
			aiGaLogic();
		}
		i++;*/
		if (checkWinner()){
			CLS;
			cout << whoTurn << " is Winner" << endl;
			return 0;
		}
		else{
			whoTurn = switchuser(whoTurn);
		}
		CLS;
	}
	CLS;
	cout << "DRAW" << endl;
}
