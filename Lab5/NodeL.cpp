/*
 * SNode.cpp
 *
 *  Created on: Sep 19, 2019
 *      Author: jvillemarette
 */

// (4 pts) Write the accompanying SNode.cpp

#include "NodeL.hpp"

NodeL::NodeL() {
	/*
	 * Default no-arg Constructor.
	 *
	 * WARNING: Prompts user to input a rating and a comment.
	 *
	 * @returns		nothing.
	 */

	next = NULL;

	string w;

	cout << "SNode Requires a Comment (String): ";
	cin >> w;

	word = w;

	wscore = 0; // TODO: What should this be?

}

NodeL::NodeL(string w) {
	/*
	 * Constructor initializing rating and comments to input parameters.
	 *
	 * @param	int		r		Rating to initialize node with.
	 * @param	string	c		Comment to initialize node with.
	 *
	 * @returns		nothing.
	 */

	next = NULL;
	word = w;

	wscore = 0; // TODO: What should this be?

}

void NodeL::printNode() {
	/*
	 * Prints the contents of this node.
	 *
	 * @returns		nothing.
	 */

	cout << "Word: " << word << endl;

}

NodeL::~NodeL() {
	/*
	 * Destructor.
	 *
	 * @returns		nothing.
	 */

	// NOTE: Yarrington said we could comment this out.
	//if(next != NULL)
		//cout << "Deleting may cause a memory leak." << endl;

}

