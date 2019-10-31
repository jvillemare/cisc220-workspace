/*
 * SNode.cpp
 *
 *  Created on: Sep 19, 2019
 *      Author: jvillemarette
 */

// (4 pts) Write the accompanying SNode.cpp

#include "NodeL.hpp"

NodeL::NodeL(string word) {
	/*
	 * Constructor initializing rating and comments to input parameters.
	 *
	 * @param	int		r		Rating to initialize node with.
	 * @param	string	c		Comment to initialize node with.
	 *
	 * @returns		nothing.
	 */

	this->word = word;
	this->next = NULL;

	this->wscore = 0; // TODO: If wanting Extra Credit, make this count each letter's
	// differently for points whatever.

}

void NodeL::printNode() {
	/*
	 * Prints the contents of this node.
	 *
	 * @returns		nothing.
	 */

	cout << "Word: " << word << endl;

}

