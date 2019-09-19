/*
 * Main.cpp
 *
 * James Villemarette
 * (No Partner)
 *
 * TA: Lauren Olson
 *
 *  Created on: Sep 18, 2019
 *      Author: jvillemarette
 *
 * This file contains functions for lab 4. The functions aren’t necessarily
 * related in any way other than that they are required for lab 4.
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "SLL.hpp"

// for formatting purposes
void stars();

int main() {

	// Part A: Class/pointers (35 pts)


	// Part B: Linked Lists (Assumed 45 pts, it's not specified)

	/*
	int r[10] = {9,8,4,5,11,10,3,6,8,2};

	string s[10] = {
			"really good!",
			"loved it",
			"mediocre",
			"okay, not great",
			"best book ever!",
			"awesome!",
			"boring",
			"not bad",
			"definitely worth reading",
			"terrible!"
	};

	SLL *list = new SLL();

	for (int i = 0; i < 10; i++) {
		list->insertInOrder(r[i],s[i]);
		list->printSLL();
	}

	cout << "Ave: " << list->getAve() << endl;
	cout << "Popping " << list->pop() << endl;

	list->printSLL();

	cout << "Popping " << list->pop() << endl;

	list->printSLL();

	delete list;
	*/

	cout << "Everything is in working order." << endl;

	return 0;

}

// for formatting purposes
void stars() {
	/*
	 * Prints a line of stars for better console reading.
	 *
	 * @returns		nothing.
	 */

	int i = 32;

	while(i) {
		cout << "*";
		i--;
	}

	cout << endl;

}
