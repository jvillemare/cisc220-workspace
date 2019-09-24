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

	int r; string c;

	cout << "SNode Requires a Rating (0 to 10): ";
	cin >> r;

	cout << "SNode Requires a Comment (String): ";
	cin >> c;

	rating = r;
	comments = c;

}

SNode::SNode(int r, string c) {
	/*
	 * Constructor initializing rating and comments to input parameters.
	 *
	 * @param	int		r		Rating to initialize node with.
	 * @param	string	c		Comment to initialize node with.
	 *
	 * @returns		nothing.
	 */

	next = NULL;
	rating = r;
	comments = c;

}

void SNode::printNode() {
	/*
	 * Prints the contents of this node.
	 *
	 * @returns		nothing.
	 */

	cout << "Rating: " << rating << ", Comments: " << comments << endl;

}

SNode::~SNode() {
	/*
	 * Destructor.
	 *
	 * @returns		nothing.
	 */

	// Note: Yarrington said we could comment this out.
	//if(next != NULL)
		//cout << "Deleting may cause a memory leak." << endl;

}

