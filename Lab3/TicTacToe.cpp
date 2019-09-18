/*
 * TicTacToe.cpp
 *
 *  Created on: Sep 17, 2019
 *      Author: jvillemarette
 */

#include "TicTacToe.hpp"

TicTacToe::TicTacToe(string playerX, string playerY) {
	/*
	 * Constructor
	 *
	 * @param	string	playerX		Name of the player with the symbol X.
	 * @param	string	playerY		Name of the player with the symbol O.
	 *
	 * @returns		nothing.
	 */

	this->playerX = playerX;
	this->playerY = playerY;

	this->dimensions = 3;

	this->board = new char*[dimensions];

	for (int row = 0; row < dimensions; row++)
		board[row] = new char[dimensions];

	resetBoard();

} // constructor

void TicTacToe::resetBoard() {
	/*
	 * Sets every spot on the board to an empty character.
	 *
	 * @returns		nothing.
	 */

	for (int row = 0; row < dimensions; row++)
		for (int col = 0; col < dimensions; col++)
			board[row][col] = '_';

}

void TicTacToe::printBoard() {
	/*
	 * Prints the board in a tab-separated fashion.
	 *
	 * @returns		nothing.
	 */

	for (int row = 0; row < dimensions; row++) {
		for (int col = 0; col < dimensions; col++) {
			cout << board[row][col] << "\t";
		}
		cout << endl;
	}

}

bool TicTacToe::isBoardFull() {
	/*
	 * Determines if the board has no empty spots.
	 *
	 * @returns		TRUE if the board is full,
	 * 				FALSE if not.
	 */

	for (int row = 0; row < dimensions; row++) {
		for (int col = 0; col < dimensions; col++) {
			if (board[row][col] == '_')
				return false;
		}
	}

	return true;

}

bool TicTacToe::isPlayerWinner(char player) {
	/*
	 * Checks to see if the player has 3 horizontal, 3 vertical, or
	 * 3 diagonal spots occupied.
	 *
	 * @param	char	player		'X' or 'O'.
	 *
	 * @returns		TRUE if the player has satisfied the win conditions,
	 * 				FALSE if not.
	 */

	for (int row = 0; row < dimensions - 2; row++) {
		for (int col = 0; col < dimensions - 2; col++) {
			// 3 diagonal
			if (board[row][col] == player && board[row + 1][col + 1] == player
					&& board[row + 2][col + 2] == player)
				return true;
		}
	}

	for (int row = 0; row < dimensions; row++) {
		for (int col = 0; col < dimensions; col++) {
			// 3 horizontal
			if (board[row][col] == player && board[row][col + 1] == player
					&& board[row][col + 2] == player)
				return true;

			// 3 vertical
			if (board[row][col] == player && board[row + 1][col] == player
					&& board[row + 1][col] == player)
				return true;
		}
	}

	return false;

}

void TicTacToe::playTurn(char player) {
	/*
	 * Prompts a player for an X and Y, validates that the spot is
	 * valid and empty, and then fills that X and Y with their player
	 * symbol, then prints the board.
	 *
	 * @param	char	player	'X' or 'O'.
	 *
	 * @returns		nothing.
	 */

	cout << player << "'s turn:" << endl;

	int row, col;
	bool turnActive = true;

	while (turnActive) {
		cout << player << ": Enter x: ";
		cin >> row;
		cout << player << ": Enter y: ";
		cin >> col;
		cout << endl;

		if (row < dimensions && col < dimensions && row >= 0 && col >= 0
				&& board[row][col] == '_') {
			board[row][col] = player;
			turnActive = false;
		} else {
			cout << "Error, that spot is already occupied." << endl;
			cout << "Select again." << endl;
		}
	}

	printBoard();

}

void TicTacToe::playGame() {
	/*
	 * Play a game of TicTacToe, stopping when a player is a winner
	 * or the board is full.
	 *
	 * @returns		nothing.
	 */

	char currentPlayer = 'X';

	while (true) {

		playTurn(currentPlayer);

		if (isPlayerWinner(currentPlayer)) {
			if (currentPlayer == 'X')
				cout << currentPlayer << " (" << playerX << ") has won!" << endl
						<< endl;
			else
				cout << currentPlayer << " (" << playerY << ") has won!"
						<< endl;

			resetBoard();

			break;
		}

		if (isBoardFull()) {
			cout << "It's a tie";
			resetBoard();
			break;
		}

		if (currentPlayer == 'X')
			currentPlayer = 'O';
		else
			currentPlayer = 'X';

	}

}

TicTacToe::~TicTacToe() {
	/*
	 * Destructor.
	 *
	 * @returns		Nothing.
	 */

	for (int row = 0; row < dimensions; row++)
		delete[] board[row];

	delete[] board;

	cout << "Board has been destroyed." << endl;

} // destructor
