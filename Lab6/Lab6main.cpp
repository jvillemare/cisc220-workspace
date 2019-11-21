/*
 * Main.cpp
 *
 * James Villemarette
 * (No Partner)
 *
 * TA: Lauren Olson
 *
 *  Created on: Nov 8, 2019
 *      Author: jvillemarette
 *
 * This file the main to run lab 6.
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "hashMap.hpp"
#include "hashNode.hpp"
#include "makeSeuss.hpp"
using namespace std;

// for formatting purposes
void stars();

int main() {

	srand(time(NULL));

	// first hash, first collision
	stars();
	cout << "FIRST hash, FIRST collision:" << endl;
	makeSeuss m1 = makeSeuss("DrSeuss.txt", "output1.txt", true, true);

	// first hash, second collision
	stars();
	cout << "FIRST hash, SECOND collision:" << endl;
	makeSeuss m2 = makeSeuss("DrSeuss.txt", "output1.txt", true, false);

	// second hash, first collision
	stars();
	cout << "SECOND hash, FIRST collision:" << endl;
	makeSeuss m3 = makeSeuss("DrSeuss.txt", "output1.txt", false, true);

	// second hash, second collision
	stars();
	cout << "SECOND hash, SECOND collision:" << endl;
	makeSeuss m4 = makeSeuss("DrSeuss.txt", "output1.txt", false, false);

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
