/*
 * SLL.cpp
 *
 *  Created on: Sep 19, 2019
 *      Author: jvillemarette
 */

#include "SLL.hpp"

SLL::SLL() {
	/*
	 * Constructor.
	 *
	 * @returns		nothing.
	 */

	first = NULL;
	last = NULL;
	size = 0;

}

void SLL::printSLL() {
	/*
	 * Prints all the nodes in the linked list.
	 *
	 * @returns		nothing.
	 */

	SNode *currentAddress = first;

	while(currentAddress->next != NULL) {
		currentAddress->printNode();
		currentAddress = currentAddress->next;
	}

	cout << endl;

}

void SLL::insertInOrder(int r, string c) {
	/*
	 * TODO: ...
	 *
	 * @param	int		r		Rating to initialize node with.
	 * @param	string	c		Comment to initialize node with.
	 *
	 * @returns		nothing.
	 */

	if(first == NULL && last == NULL && size == 0) {
		addFirst(r, c);
		return;
	}

	if(r < first->rating) {
		addAtFront(r, c);
	} else if(r > last->rating) {
		push(r, c);
	} else {
		SNode *currentAddress = first;

		while(currentAddress->next != NULL) {

			if(currentAddress->rating > r &&
					currentAddress->next->rating < r) {

				SNode *newNode = new SNode(r, c);
				newNode->next = currentAddress->next;
				currentAddress->next = newNode;
				break;

			}

			currentAddress = currentAddress->next;

		}
	}

}

void SLL::push(int r, string c) {
	/*
	 * Add a node to end of this SLL.
	 *
	 * @param	int		r		Rating to initialize node with.
	 * @param	string	c		Comment to initialize node with.
	 *
	 * @returns		nothing.
	 */

	last->next = new SNode(r, c);
	last = last->next;
	size++;

}

void SLL::addAtFront(int r, string c) {
	/*
	 * Add a node to the front of a linked list. If there's no first
	 * node, then addFirst(...) is called.
	 *
	 * @param	int		r		Rating to initialize node with.
	 * @param	string	c		Comment to initialize node with.
	 *
	 * @returns		nothing.
	 */

	if(first == NULL && last == NULL && size == 0) {
		addFirst(r, c);
		return;
	}

	SNode *newNode = new SNode(r, c);
	newNode->next = first;
	first = newNode;
	size++;

}

void SLL::addFirst(int r, string c) {
	/*
	 * Adds an node to the first of the linked list.
	 *
	 * @param	int		r		Rating to initialize node with.
	 * @param	string	c		Comment to initialize node with.
	 *
	 * @returns		nothing.
	 */

	first = new SNode(r, c);
	size++;
	last = first;

}

int SLL::pop() {
	/*
	 * Removes last node from the linked list and returns its rating.
	 *
	 * @returns		The rating from the last SNode in the SLL.
	 */

	int rating = last->rating;

	delete last;

	SNode *currentAddress = first;

	while(currentAddress->next != NULL &&
			currentAddress->next->next != NULL) {
		currentAddress = currentAddress->next;
	}

	last = currentAddress;

	size--;

	return rating;

}

double SLL::getAve() {
	/*
	 * Get average of all the comments in the singly linked list.
	 *
	 * @returns		average of integer score.
	 */

	double count = 0.0;

	SNode *currentAddress = first;

	while(currentAddress->next != NULL) {
		count += currentAddress->rating;
		currentAddress = currentAddress->next;
	}

	return count / size;

}

SLL::~SLL() {
	/*
	 * Destructor.
	 *
	 * @returns		nothing.
	 */

	// TODO: Delete node objects
	SNode *currentAddress = first;

	while(currentAddress->next != NULL) {
		currentAddress->printNode();
		currentAddress = currentAddress->next;
	}

}
