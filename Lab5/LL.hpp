/*
 * SLL.hpp
 *
 *  Created on: Sep 19, 2019
 *      Author: jvillemarette
 */

#ifndef LL_HPP_
#define LL_HPP_

#include "NodeL.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

class LL {
	friend class Game;

public:
	NodeL *first;
	NodeL *last;
	int size;
	int score;

	LL();
	~LL();

	void printList();
	/*
	 * (4 pts for working) write a method that prints out the linked list
	 */

	void push(string c);
	/*
	 * (4 pts for working) pushes a new node (with rating r and c comments)
	 * onto the end of the linked list (remember to reset the last pointer)
	 * – I called this from the insertInOrder() method.
	 */

	void addFirst(string c);
	/*
	 * (3 pts for working) adds the very first node (made from r and c) to
	 * an empty list I called this from insertInOrder
	 */

	void getScore(); /* This is the new method — each word already has a score.
	This method just traverses the linked list from the first to the last node
	and keeps a running total of the wscore of each node. Then the score field
	is set to that total. */

};

#endif /* LL_HPP_ */
