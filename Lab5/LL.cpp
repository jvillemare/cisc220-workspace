/*
 * SLL.cpp
 *
 *  Created on: Sep 19, 2019
 *      Author: jvillemarette
 */

#include "LL.hpp"

LL::LL() {
	/*
	 * Constructor.
	 *
	 * @returns		nothing.
	 */

	first = NULL;
	last = NULL;
	size = 0;
	score = 0;

}

void LL::getScore() {
	/*
	 * Keeps a running total of wscore across LinkedList
	 *
	 * @returns		nothing.
	 */


}

void LL::printList() {
	/*
	 * Prints all the nodes in the linked list.
	 *
	 * @returns		nothing.
	 */

	if(first == last) {
		first->printNode();
		cout << endl;
	} else {
		NodeL *currentAddress = first;

		while(currentAddress != NULL) {
			//if(currentAddress->rating != 0)
				currentAddress->printNode();
			currentAddress = currentAddress->next;
		}

		cout << endl;
	}

}

void LL::push(string c) {
	/*
	 * Add a node to end of this SLL.
	 *
	 * @param	int		r		Rating to initialize node with.
	 * @param	string	c		Comment to initialize node with.
	 *
	 * @returns		nothing.
	 */

	NodeL *newNode = new NodeL(c);
	last->next = newNode;
	last = newNode;
	size++;

}

void LL::addFirst(string c) {
	/*
	 * Adds an node to the first of the linked list.
	 *
	 * @param	int		r		Rating to initialize node with.
	 * @param	string	c		Comment to initialize node with.
	 *
	 * @returns		nothing.
	 */

	first = new NodeL(c);
	last = first;
	size++;

}

LL::~LL() {
	/*
	 * Destructor.
	 *
	 * @returns		nothing.
	 */

	NodeL *previousNode = first;

	if(previousNode->next == NULL) {
		delete previousNode;
		return;
	}

	NodeL *currentAddress = previousNode->next;

	while(currentAddress->next != NULL) {

		cout << "deleting " << previousNode->word << endl;

		delete previousNode;
		previousNode = currentAddress;
		currentAddress = currentAddress->next;

	}

	cout << "deleted each node in l1" << endl;

}
