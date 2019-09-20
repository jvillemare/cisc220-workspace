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
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

	SNode *currentAddress = first;

	while(currentAddress->next != NULL) {
		currentAddress->printNode();
		currentAddress = currentAddress->next;
	}

}

void SLL::insertInOrder(int r, string c) {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

}

void SLL::push(int r, string c) {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

	last->next = new SNode(r, c);
	last = last->next;
	size++;

}

void SLL::addAtFront(int r, string c) {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

}

void SLL::addFirst(int r, string c) {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

	first = new SNode(r, c);
	size++;
	last = first;

}

int SLL::pop() {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

}

double SLL::getAve() {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

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
