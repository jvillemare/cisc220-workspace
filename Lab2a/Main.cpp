/*
 * Main.cpp
 *
 * James Villemarette
 * Philip O'Connor
 *
 * TA: Lauren Olson
 *
 *  Created on: Sep 3, 2019
 *      Author: jvillemarette
 *
 * This file contains functions for lab 2a.
 * The functions aren’t necessarily related
 * in any way other than that they are required
 * for lab 2a.
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#define getName(var) #var
using namespace std;

void swap(int x, int y);
void swap2(int *x, int *y);
void swap3(int &x, int &y);
void stars();
void problemOne();
void addFourByReference(int &x);
int getRand();
void cube(int &val);
void alias(int &val);
void weirdAdd(int *first, int *second);
void milkshake(char first, char *second, char &third);
bool weirdSwap(int &i1, int &i2);
void randomTester();

int main() {

	// Seeding random number generator
	srand(time(NULL));

	// Try on Computer, Page 4
	int x = 8;

	cout << x << endl;
	cout << &x << endl;
	cout << getName(x) << endl;

	// Try on Computer, Page 5
	int* y = &x;

	cout << *y << endl; // a
	cout << y << endl; // b
	cout << &x << endl; // c
	cout << &y << endl; // d

	x = 5; // e

	cout << *y << endl; // f

	int z = 10; // a2
	y = &z;

	cout << x << endl; // b2

	// Try on Computer, Page 8
	int a = 2;
	int b = 4;
	cout << a << b << endl;
	swap(a,b);
	cout << a << b << endl;
	swap2(&a, &b);
	cout << a << b << endl;

	// Try on Computer, Page 9
	a = 2;
	b = 4;

	cout << a << b << endl;
	swap3(a, b);
	cout << a << b << endl;

	// problem #1
	stars();

	problemOne();

	// problem #2
	stars();

	int r = 64;

	cout << r << endl;
	cout << &r << endl;

	// this is a call-by-reference
	addFourByReference(r);

	cout << r << endl;
	cout << &r << endl;

	// problem #3
	stars();

	int yarp = getRand();

	cout << yarp << endl;
	cout << &yarp << endl;

	// problem #4
	stars();

	int someVal = 4;

	cout << someVal << endl;
	cout << &someVal << endl;

	cube(someVal);

	cout << someVal << endl;
	cout << &someVal << endl;

	// problem #5
	stars();

	int whatever = 1;

	cout << whatever << endl;
	cout << &whatever << endl;

	alias(whatever);

	cout << whatever << endl;
	cout << &whatever << endl;

	// problem #6
	stars();

	int first = 10;
	int second = 20;

	weirdAdd(&first, &second);

	cout << "First:  " << first << endl;
	cout << "Second: " << second << endl;

	// problem #7
	stars();

	char c1 = 'H';
	char c2 = 'e';
	char c3 = 'y';

	cout << c1 << c2 << c3 << endl;

	milkshake(c1, &c2, c3);

	cout << c1 << c2 << c3 << endl;

	// problem #8a
	stars();

	int tgif1 = 2;
	int tgif2 = 4;

	bool imRunningOutOfIdeas = weirdSwap(tgif1, tgif2);

	cout << "This should be false (0): " << imRunningOutOfIdeas << endl;

	tgif1 = 4;
	tgif2 = 2;

	imRunningOutOfIdeas = weirdSwap(tgif1, tgif2);

	cout << "This should be true (1): " << imRunningOutOfIdeas << endl;

	// problem #8b
	stars();

	randomTester();

	return 0;

}

// problem #0
void swap(int m, int n) {
	/*
	 * THIS IS THE ORIGINAL SWAP FUNCTION.
	 * Yarrington asked us to keep this here.
	 *
	 * @param	integer		m		first int to swap.
	 * @param	integer		n		second int to swap.
	 *
	 * @returns		nothing.
	 */

	int tmp = m;
	m = n;
	n = tmp;
}

void swap2(int *x, int *y) {
	/*
	 * Fixed swap method. Actually swaps two integers by their pointers.
	 *
	 * @param	integer		m		first int to swap.
	 * @param	integer		n		second int to swap.
	 *
	 * @returns		nothing.
	 */

	int tmp = *x;
	*x = *y;
	*y = tmp;

}

void swap3(int &x, int &y) {
	/*
	 * Alternate swap function using call-by-reference (aliasing).
	 *
	 * @param	integer		m		first int to swap.
	 * @param	integer		n		second int to swap.
	 *
	 * @returns		nothing.
	 */

	int tmp = x;
	x = y;
	y = tmp;

}

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

// problem #1
void problemOne() {
	/*
	 * Create an int and print its value and address.
	 *
	 * @returns		nothing.
	 */

	int x = 32;

	cout << x << endl;
	cout << &x << endl;


}

// problem #2
void addFourByReference(int &x) {
	/*
	 * Add four to an integer by its reference.
	 *
	 * @param	integer		x		int to add 4 to.
	 *
	 * @returns		nothing.
	 */

	x = x + 4;

	cout << x << endl;
	cout << &x << endl;

}

// problem #3
int getRand() {
	/*
	 * Get a random number between 1 and 50, exclusive. Print its value and
	 * address. Yarrington wasn't clear on the exclusive/inclusive part, but
	 * she usually states exclusive.
	 *
	 * @returns		nothing.
	 */

	int x = rand() % 50;

	cout << x << endl;
	cout << &x << endl;

	return x;

}

// problem #4
void cube(int &val) {
	/*
	 * Print out a value and its address, cube it, then print its value and
	 * address again
	 *
	 * @param	integer		val		int to square using call-by-reference.
	 *
	 * @returns		nothing.
	 */

	cout << val << endl;
	cout << &val << endl;

	val = val * val;

	cout << val << endl;
	cout << &val << endl;

}

// problem #5
void alias(int &val) {
	/*
	 * Add a random number *between* 0 and 10 to an aliased integer. Printing
	 * the value and addresses of the original value, the random int, and the
	 * update value.
	 *
	 * @param	integer		val		int to add (0, 10) to.
	 *
	 * @returns		nothing.
	 */

	cout << "Original Value: " << val << endl;
	cout << "Original Value: " << &val << endl;

	int random = rand() % 10;
	val += random;

	cout << "Random: " << random << endl;
	cout << "Random: " << &random << endl;

	cout << "New Value: " << val << endl;
	cout << "New Value: " << &val << endl;

}

// problem #6
void weirdAdd(int *first, int *second) {
	/*
	 * Basically update two integers (using pointers) with the specific values
	 * that Yarrington told us to use.
	 *
	 * @param	*integer		first		update int value to 32.
	 * @param	*integer		second		updaste int value to 42.
	 *
	 * @returns		nothing.
	 */

	int *something = first;
	*something = 32;

	something = second;
	*something = 42;

}

// problem #7
void milkshake(char first, char *second, char &third) {
	/*
	 * THIS IS THE ORIGINAL SWAP FUNCTION.
	 * Yarrington asked us to keep this here.
	 *
	 * @param	char		first		first char to update to 'y'.
	 * 									(this won't work since its just a value
	 * 									that will only be updated within $this
	 * 									function's stack call.)
	 * @param	*char		second		second char to update to 'o'.
	 * @param	&char		third		third char to update to 'u'.
	 *
	 * @returns		nothing.
	 */

	first = 'y';
	*second = 'o';
	third = 'u';

}

// problem #8a
bool weirdSwap(int &i1, int &i2) {
	/*
	 * Swap to aliased integers only if the first integer is larger than the
	 * second integer.
	 *
	 * @param	integer		i1		first int, which will be swapped if its
	 * 								larger.
	 * @param	integer		i2		second int, which will be swapped if i1 is
	 * 								larger.
	 *
	 * @returns		TRUE if swapped,
	 * 				FALSE if not swapped.
	 */

	if(i1 > i2) {

		int tmp = i1;
		i1 = i2;
		i2 = tmp;

		return true;

	}

	return false;

}

// problem #8b
void randomTester() {
	/*
	 * Loops 20 times, generates two random numbers (0, 25), prints the two
	 * numbers, and then prints them out again if they're swapped.
	 *
	 * @returns		nothing.
	 */

	int i = 20;

	while(i) {

		int a = rand() % 25;
		int b = rand() % 25;

		cout << "A is: " << a << endl;
		cout << "B is: " << b << endl;

		if(weirdSwap(a, b))
			cout << "A and B were swapped! Now they're:" << endl <<
				"   A: " << a << endl << "   B: " << b << endl;

		i--;

	}

}


