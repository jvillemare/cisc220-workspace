/*
 * SNode.hpp
 *
 *  Created on: Sep 19, 2019
 *      Author: jvillemarette
 */

#ifndef NODEL_HPP_
#define NODEL_HPP_

#include <iostream>
using namespace std;

class NodeL {
	friend class LL;
	friend class Game;

	string word;
		/*
		 * instead of int data, now the data is both the rating
		 * and the accompanying comments – think of when you rate
		 * a book or a song, and then are asked to share comments
		 * about the book. Both are the data in this node.
		 */

	int wscore;
		/*
		 * What is this? It's anyone's guess
		 */

	NodeL *next;

public:

	NodeL(string w);
	/*
	 * this constructor takes as input an integer and a string, and
	 * initializes the rating field to the integer, and the comment
	 * field to the string.
	 */

	void printNode();

	~NodeL();

};

#endif /* NODEL_HPP_ */
