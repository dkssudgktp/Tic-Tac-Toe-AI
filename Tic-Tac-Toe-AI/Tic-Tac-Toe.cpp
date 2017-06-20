#include <iostream>
#include <stdlib.h>
#include <ctype.h>
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
	for (int i = 0,size = 9; i < size; i++) {
		board[i] = " ";
	}
}


void Tic_Tac_Toe::printBoard(void) { // print board 
	cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "---------" << endl;
	cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "---------" << endl;
	cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

bool Tic_Tac_Toe::isFull(void) { // check board is full
	for (int i = 0, size = 9; i < size; i++) {
		if (board[i] == " ") return false;
	}
	return true;
}

bool Tic_Tac_Toe::checkWinner(void) { // game winner check
	if (board[0] == board[1] && board[0] == board[2] && board[0] != " ")
		return true;
	else if (board[3] == board[4] && board[3] == board[5] && board[3] != " ")
		return true;
	else if (board[6] == board[7] && board[6] == board[8] && board[6] != " ")
		return true;

	else if (board[0] == board[3] && board[0] == board[6] && board[0] != " ")
		return true;
	else if (board[1] == board[4] && board[1] == board[7] && board[1] != " ")
		return true;
	else if (board[2] == board[5] && board[2] == board[8] && board[2] != " ")
		return true;

	else if (board[0] == board[4] && board[0] == board[8] && board[0] != " ")
		return true;
	else if (board[2] == board[4] && board[2] == board[6] && board[2] != " ")
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
	if (getNumber == 1 && board[0] == " ") board[0] = whoTurn;
	else if(getNumber == 2 && board[1] == " ") board[1] = whoTurn;
	else if (getNumber == 3 && board[2] == " ") board[2] = whoTurn;
	else if (getNumber == 4 && board[3] == " ") board[3] = whoTurn;
	else if (getNumber == 5 && board[4] == " ") board[4] = whoTurn;
	else if (getNumber == 6 && board[5] == " ") board[5] = whoTurn;
	else if (getNumber == 7 && board[6] == " ") board[6] = whoTurn;
	else if (getNumber == 8 && board[7] == " ") board[7] = whoTurn;
	else if (getNumber == 9 && board[8] == " ") board[8] = whoTurn;
}

string Tic_Tac_Toe::switchuser(string Turn) {
	if (Turn == "X") return "O";
	else if (Turn == "O") return "X";
}

void Tic_Tac_Toe::aiGaLogic(void) { //ai game logic
	int score = -1;
	int move = -1;
	for (int i; i < 9; i++) {
			if (board[i] == " ") {
				board[i] = whoTurn;
				int TempScore = -minimax(board, switchuser(whoTurn));
				board[i] = " ";
				if (TempScore > score) {
					score = TempScore;
					move = i;
				}
			
		}
	}
	board[move]= whoTurn;
}

int Tic_Tac_Toe::gameLogic(void) { // basic game logic
	int i = 1;
	while (!isFull()){
		printBoard();
		//int get = getInput();
		addMove(getInput());
		/*if (board[get] == " " && addMove(get)){
			continue;
		}
		
		aiGaLogic();
		if (i%1 == 0){
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
