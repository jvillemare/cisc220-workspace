/*
 * SNode.cpp
 *
 *  Created on: Sep 19, 2019
 *      Author: jvillemarette
 */

// (4 pts) Write the accompanying SNode.cpp

#include "SNode.hpp"

SNode::SNode() {
	/*
	 * Default no-arg Constructor.
	 *
	 * WARNING: Prompts user to input a rating and a comment.
	 *
	 * @returns		nothing.
	 */

	next = NULL;

	string c;

	cout << "SNode Requires a Comment (String): ";
	cin >> c;

	comments = c;

}

SNode::SNode(string c) {
	/*
	 * Constructor initializing rating and comments to input parameters.
	 *
	 * @param	int		r		Rating to initialize node with.
	 * @param	string	c		Comment to initialize node with.
	 *
	 * @returns		nothing.
	 */

	next = NULL;
	comments = c;

}

void SNode::printNode() {
	/*
	 * Prints the contents of this node.
	 *
	 * @returns		nothing.
	 */

	cout << "Word: " << comments << endl;

}

SNode::~SNode() {
	/*
	 * Destructor.
	 *
	 * @returns		nothing.
	 */

	// NOTE: Yarrington said we could comment this out.
	//if(next != NULL)
		//cout << "Deleting may cause a memory leak." << endl;

}

