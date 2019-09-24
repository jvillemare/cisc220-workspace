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

void SLL::insertInOrder(int r, string c) {
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

void SLL::push(int r, string c) {
	/*
	 * Add a node to end of this SLL.
	 *
	 * @param	int		r		Rating to initialize node with.
	 * @param	string	c		Comment to initialize node with.
	 *
	 * @returns		nothing.
	 */

	SNode *newNode = new SNode(r, c);
	last->next = newNode;
	last = newNode;
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

	if(first == NULL) {
		addFirst(r, c);
	} else {
		SNode *newNode = new SNode(r, c);
		newNode->next = first;
		first = newNode;
		size++;
	}

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
	last = first;
	size++;

}

int SLL::pop() {
	/*
	 * Removes last node from the linked list and returns its rating.
	 *
	 * @returns		The rating from the last SNode in the SLL.
	 */

	cout << last->rating << endl << "deleting " << last->rating << ", "
			<< last->comments << endl;

	int rating = last->rating;

	delete last;

	SNode *currentAddress = first;

	while(currentAddress->next->next != NULL) {
		currentAddress = currentAddress->next;
	}

	last = currentAddress;
	last->next = NULL;

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

	while(currentAddress != NULL) {
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
