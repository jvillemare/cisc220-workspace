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

}

void LL::printLL() {
	/*
	 * Prints all the nodes in the linked list.
	 *
	 * @returns		nothing.
	 */

	if(first == last) {
		first->printNode();
		cout << endl;
	} else {
		SNode *currentAddress = first;

		while(currentAddress != NULL) {
			//if(currentAddress->rating != 0)
				currentAddress->printNode();
			currentAddress = currentAddress->next;
		}

		cout << endl;
	}

}

void LL::insertInOrder(int r, string c) {
	/*
	 * Inserts a new node with a rating r in the proper order where the
	 * previous node's r is < passed r and < next node's r.
	 *
	 * @param	int		r		Rating to initialize node with.
	 * @param	string	c		Comment to initialize node with.
	 *
	 * @returns		nothing.
	 */

	if(first == NULL) { // if SLL empty
		addFirst(r, c);
	} else if(r < first->rating) {
		addAtFront(r, c);
	} else if(r > last->rating) {
		push(r, c);
	} else {
		SNode *currentAddress = first;

		while(currentAddress->next != NULL) {

			if(r < currentAddress->next->rating) {

				SNode *newNode = new SNode(r, c);
				newNode->next = currentAddress->next;
				currentAddress->next = newNode;
				size++;

				return;

			}

			currentAddress = currentAddress->next;

		}
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

	SNode *newNode = new SNode(c);
	last->next = newNode;
	last = newNode;
	size++;

}

void LL::addAtFront(string c) {
	/*
	 * Add a node to the front of a linked list. If there's no first
	 * node, then addFirst(...) is called.
	 *
	 * @param	int		r		Rating to initialize node with.
	 * @param	string	c		Comment to initialize node with.
	 *
	 * @returns		nothing.
	 */

	if(first == NULL) {
		addFirst(r, c);
	} else {
		SNode *newNode = new SNode(c);
		newNode->next = first;
		first = newNode;
		size++;
	}

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

	first = new SNode(c);
	last = first;
	size++;

}

int LL::pop() {
	/*
	 * Removes last node from the linked list and returns its comments.
	 *
	 * @returns		The rating from the last SNode in the SLL.
	 */

	cout << last->comments << endl;

	string comment = last->comments;

	delete last;

	SNode *currentAddress = first;

	while(currentAddress->next->next != NULL) {
		currentAddress = currentAddress->next;
	}

	last = currentAddress;
	last->next = NULL;

	size--;

	return comment;

}

LL::~LL() {
	/*
	 * Destructor.
	 *
	 * @returns		nothing.
	 */

	SNode *previousNode = first;

	if(previousNode->next == NULL) {
		delete previousNode;
		return;
	}

	SNode *currentAddress = previousNode->next;

	while(currentAddress->next != NULL) {

		cout << "deleting " << previousNode->rating << ", "
				<< previousNode->comments << endl;

		delete previousNode;
		previousNode = currentAddress;
		currentAddress = currentAddress->next;

	}

	cout << "deleted each node in l1" << endl;

}
