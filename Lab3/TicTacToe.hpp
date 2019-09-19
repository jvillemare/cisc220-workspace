/*
 * TicTacToe.hpp
 *
 *  Created on: Sep 17, 2019
 *      Author: jvillemarette
 */

#include<iostream>
#include<string> // for string class
using namespace std;

#ifndef TICTACTOE_HPP_
#define TICTACTOE_HPP_

class TicTacToe {

	char **board;
	string playerX;
	string playerY;
	int dimensions;

public:
	TicTacToe(string playerX, string playerY);

	void resetBoard();
	void printBoard();
	bool isBoardFull();
	bool isPlayerWinner(char player);
	void playTurn(char player);
	void playGame();

	~TicTacToe(); // destructor
};

#endif /* TICTACTOE_HPP_ */
