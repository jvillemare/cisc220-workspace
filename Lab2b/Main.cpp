/*
 * Main.cpp
 *
 * James Villemarette
 * Philip O'Connor
 *
 * TA: Lauren Olson
 *
 *  Created on: Sep 5, 2019
 *      Author: jvillemarette
 *
 * This file contains functions for lab 2b.
 * The functions aren’t necessarily related
 * in any way other than that they are required
 * for lab 2b.
 *
 * As a rule, include the minimum, exclude the
 * maximum of a range: i.e. [0, 50)
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void stars();
void func(int *x, int size);
void generateWeirdArray(int length, int &smallest);
void generateAndReverseArray(int length);
void printSortedArray(int length, int range);
int* stackTest();
void printArray(int arr[], int size);
int* arrayHeapSomething(int *length, int *high, int *low);
int* arrayStackSomething(int *length);
void arrayAddresses(int array[], int length);
void arrayAddresses(double array[], int length);
int* removeDoubles(int values[], int *size);
int hanningWindow(int *arrayPart);
int* filterArray(int *arr, int size);
void graphArray(int *arr, int size, int high, int low);
int** multiDimensionalArray(int *x, int *y);

int main() {

	// Seeding random number generator
	srand(time(NULL));

	// Try on Computer, Page 3
	int ints[3] = {4, 2, 0};

	cout << &ints[0] << endl; //method 1: address of first value in array
	cout << ints << endl << endl;
		//method 2: same value, address of array, of first value

	for(int i = 0; i < 3; i++)
		cout << &ints[i] << endl;

	// Try on Computer, Page ~4
	stars();

	int arr[7] = {10,20,30,40,50,60,70};
	func(arr,7);
	func(&arr[0],7);
	func(&arr[2],5);

	// problem #1
	stars();

	int smallest = -1;

	generateWeirdArray(3, smallest);

	cout << "Inside main, smallest is " << smallest << endl;

	// problem #2
	stars();

	generateAndReverseArray(3);

	cout << endl;

	generateAndReverseArray(4);

	// problem #3
	stars();

	printSortedArray(10, 15);
	printSortedArray(10, 5);

	// problem #4
	stars();

	int* aPointer = stackTest();

	cout << "Address of variable is: " << aPointer << endl;
	cout << "Value of variable is..: " << *aPointer << endl;

	// Did this work? No, because the variable on the stack was cleared away
	//					when the function returned.
	// Did it compile? Yes, because there's nothing *technically* wrong with it.

	// problem #5a
	int something[3] = {1, 2, 3};

	printArray(&something[0], 3);

	// problem #5b
	stars();

	int help[25];
	int i = 0;

	while(i < 25) {
		help[i] = 1 + (rand() % 10);

		cout << help[i] << ", ";

		i++;
	}

	printArray(&help[0], 25);

	// problem #6
	stars();

	int length = 20;
	int high = 20;
	int low = 20;

	cout << "length: " << length << endl;
	cout << "high:   " << high << endl;
	cout << "low:    " << low << endl << endl;

	int *heapArray = arrayHeapSomething(&length, &high, &low);

	cout << "length: " << length << endl;
	cout << "high:   " << high << endl;
	cout << "low:    " << low << endl;

	printArray(heapArray, length);

	delete [] heapArray;

	// problem #7
	stars();

	length = 20;

	cout << "length: " << length << endl << endl;

	printArray(arrayStackSomething(&length), length);

	cout << endl << "length: " << length << endl;

	// because the array was on the stack of the arrayStackSomething(...) func.
	// its actual values were cleared away when the function ended, and thus

	// problem #8
	stars();

	arrayAddresses(something, 3);

	// problem #9
	stars();

	double somethingElse[3] = {1.0, 2.0, 3.0};

	arrayAddresses(somethingElse, 3); // basically the same thing as problem #8

	// problem #10
	stars();

	int size = 25;

	int arrayWithDoubles[25] = {5,4,4,3,6,6,6,8,9,5,1,3,8,8,1,8,9,9,3,2,2,2,6,1,2};
	int *arrayWithoutDoubles = removeDoubles(arrayWithDoubles, &size);

	cout << "Size is: " << size << endl;

	printArray(arrayWithDoubles, 25);
	// 5, 4, 4, 3, 6, 6, 6, 8, 9, 5, 1, 3, 8, 8, 1, 8, 9, 9, 3, 2, 2, 2, 6, 1, 2,

	cout << "Size is: " << size << endl;

	printArray(arrayWithoutDoubles, 25);
	// 5, 4, 3, 6, 8, 9, 5, 1, 3, 8, 1, 8, 9, 3, 2, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0,

	delete [] arrayWithoutDoubles;

	// problem #11
	stars();

	int hanningDemo1[6] = {1, 2, 3, 4, 5, 6};
	int hanningDemo2[6] = {13, 2, 5, 7, 1, 9};

	cout << "Hanning Window: " << hanningWindow(&hanningDemo1[0]) << endl;
	// Hanning Window: 3
	cout << "Hanning Window: " << hanningWindow(&hanningDemo1[3]) << endl;
	// Hanning Window: 3

	cout << "Hanning Window: " << hanningWindow(&hanningDemo2[0]) << endl;
	// Hanning Window: 4
	cout << "Hanning Window: " << hanningWindow(&hanningDemo2[3]) << endl;
	// Hanning Window: 4

	// problem #12
	stars();

	int *filteredArray = filterArray(&arrayWithDoubles[0], 25);

	printArray(&arrayWithDoubles[0], 25);
	// 5, 4, 4, 3, 6, 6, 6, 8, 9, 5, 1, 3, 8, 8, 1, 8, 9, 9, 3, 2, 2, 2, 6, 1, 2,
	printArray(filteredArray, 25);
	// 0, 3, 4, 6, 6, 6, 8, 7, 3, 1, 4, 8, 5, 3, 8, 9, 7, 2, 2, 2, 3, 4, 1, 1, 0,

	delete [] filteredArray;

	// problem #13
	stars();

	int *aNewBeginning = arrayHeapSomething(&length, &high, &low);

	// randomly generated array will be wibbly-wobbly, with spikes and crevasses.
	graphArray(&aNewBeginning[0], length, high, low);

	cout << endl << "Filtered array: " << endl;

	aNewBeginning = filterArray(&aNewBeginning[0], length);

	// filtered array should be smoother.
	graphArray(&aNewBeginning[0], length, high, low);

	// problem #14
	stars();

	int x = 0;
	int y = 0;

	cout << "x before is: " << x << endl;
	cout << "y before is: " << y << endl << endl;

	int** twoDimensionalArray = multiDimensionalArray(&x, &y);

	for(int row = 0; row < y; row++) {
		printArray(twoDimensionalArray[row], x);
	}

	cout << endl;
	cout << "x after is: " << x << endl;
	cout << "y after is: " << y << endl << endl;

	cout << ":)" << endl;

	stars();

	return 0;

}

// just for formatting
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

// Try on Computer, Page ~4
void func(int *x, int size) {
	/*
	 * Print a set number of values from an array.
	 *
	 * @param	integer		x		pointer to array.
	 * @param	integer		size	number of array values to print.
	 *
	 * @returns		TRUE if swapped,
	 * 				FALSE if not swapped.
	 */

	for (int i = 0; i < size; i++)
		cout << x[i] << ", ";

	cout << endl;
	return;
}

// problem #1
void generateWeirdArray(int length, int &smallest) {
	/*
	 * Generate an array of specified length, with values filled between 1 and
	 * 50. The smallest value present in the array is recorded in smallest.
	 *
	 * @param	integer		length		how many indexes in the array.
	 * @param	integer		smallest	the smallest value of the array.
	 *
	 * @returns		nothing (Yarrington didn't specify.)
	 */

	int arr[length];
	int i = 0;
	smallest = 51;

	while(i < length) {
		arr[i] = 1 + (rand() % 50);

		if(arr[i] < smallest)
			smallest = arr[i];

		cout << arr[i] << ", ";

		i++;
	}

	cout << endl;

	cout << "Smallest value: " << smallest << endl;

}

// problem #2
void generateAndReverseArray(int length) {
	/*
	 * Generate an array of specified length, with values filled between 1 and
	 * 50. Print the array, flip it, then print it, again.
	 *
	 * @param	integer		length		how many indexes in the array.
	 *
	 * @returns		nothing (Yarrington didn't specify.)
	 */

	int arr[length];
	int i = 0;

	while(i < length) {
		arr[i] = 1 + (rand() % 50);

		cout << arr[i] << ", ";

		i++;
	}

	cout << endl << "Reverse, reverse!" << endl;
	i = 0;

	// flip values
	while(i < length / 2) {

		int high = arr[length - i - 1];
		int low = arr[i];

		arr[i] = high;
		arr[length - i - 1] = low;

		i++;

	}

	i = 0;

	// print out array, now reversed
	while(i < length) {
		cout << arr[i] << ", ";
		i++;
	}

	cout << endl;

}

// problem #3
void printSortedArray(int length, int range) {
	/*
	 * Generate an array of specified length, with values filled between 1 and
	 * range. Print the array, then "sort" it.
	 *
	 * @param	integer		length		how many indexes in the array.
	 * @param	integer		range		[0 to range), what kind of values to
	 * 									include in the randomly-generated array.
	 *
	 * @returns		nothing (Yarrington didn't specify.)
	 */

	int arr[length];
	int i = 0;

	cout << "Unsorted array:" << endl;

	while(i < length) {
		arr[i] = 1 + (rand() % range);

		cout << arr[i] << ", ";

		i++;
	}

	cout << endl << "Sorted array:" << endl;

	i = 0;

	while(i < length) {

		int smallest = range + 1, smallestIndex = -1, j = 0;

		while(j < length) {

			if(arr[j] < smallest) {
				smallest = arr[j];
				smallestIndex = j;
			}

			j++;

		}

		cout << arr[smallestIndex] << ", ";
		arr[smallestIndex] = range + 1;

		i++;

	}

	cout << endl << endl;

}

// problem #4
int* stackTest() {
	/*
	 * Creates a variable on the stack and return its address.
	 *
	 * @returns		address of an integer on the stack.
	 */

	int whatever = 3;

	return &whatever;

}

// problem #5a
void printArray(int arr[], int size) {
	/*
	 * Print a comma-separated array.
	 *
	 * @param	integer[]	arr		address of first value in array.
	 * @param	integer		size	number of elements in array to print.
	 *
	 * @returns		nothing
	 */

	int i = 0;

	while(i < size) {

		cout << arr[i] << ", ";
		i++;

	}

	cout << endl;

}

// problem #6
int* arrayHeapSomething(int *length, int *high, int *low) {
	/*
	 * Create a new array on the heap, with values between high and low, with
	 * high [5, 10) and low [-10, -5).
	 *
	 * @param	integer*	length		what will be the length of the array,
	 * 									between [25, 50).
	 * @param	integer*	high		upper-bound of random #s in array.
	 * @param	integer*	low			lower-bound of random #s in array.
	 *
	 * @returns		address of the array on the heap.
	 */

	*length = 25 + (rand() % 25);

	int *arr = new int[*length];
	*high = 5 + (rand() % 5);
	*low = -5 - (rand() % 5);

	int i = 0;

	while(i < *length) {
		arr[i] = - (rand() % *low) + (rand() % *high);
		i++;
	}

	return arr;

}

// problem #7
int* arrayStackSomething(int *length) {
	/*
	 * Create a new array on the heap, with values between high and low, with
	 * high [5, 10) and low [-10, -5).
	 *
	 * @param	integer*	length		length of the array to create.
	 *
	 * @returns		address of array on the stack.
	 */

	int arr[*length];
	int high = 5 + (rand() % 5), low = -5 - (rand() % 5), i = 0;

	while(i < *length) {
		arr[i] = - (rand() % low) + (rand() % high);
		i++;
	}

	return arr;

}

// problem #8
void arrayAddresses(int array[], int length) {
	/*
	 * Print all the addresses of an array that's been passed.
	 *
	 * @param	integer		array		array with addresses to be printed.
	 * @param	integer		length		number of addresses to print.
	 *
	 * @returns		address of array on the stack.
	 */

	for(int i = 0; i < length; i++)
		cout << &array[i] << ", ";

	cout << endl;

}

// problem #9
void arrayAddresses(double array[], int length) {
	/*
	 * Print all the addresses of an array that's been passed.
	 *
	 * @param	double		array		array with addresses to be printed.
	 * @param	integer		length		number of addresses to print.
	 *
	 * @returns		address of array on the stack.
	 */

	for(int i = 0; i < length; i++)
		cout << &array[i] << ", ";

	cout << endl;

}

// problem #10
int* removeDoubles(int values[], int *size) {
	/*
	 * Removes multiple occurrences of integers that are adjacent to each other.
	 *
	 * Example:
	 * 	5,4,4,3,6,6,6,8,9,5,1,3,8,8,1,8,9,9,3,2,2,2,6,1,2
	 * 	Becomes:
	 * 	5,4,3,6,8,9,5,1,3,8,1,8,9,3,2,6,1,2
	 *
	 * @param	integer		values[]	array with integers to be de-doubled.
	 * @param	integer		size		number of elements in that array.
	 *
	 * @returns		address of non-doubled array on the stack.
	 */

	int addedValues = 0, i = 0;

	// determine how many doubles there are
	for(; i < *size; i++) {
		if(values[i] == values[i + 1]) {
			addedValues++;
		} else {
			continue;
		}
	}

	cout << "DEBUG: size is now " << *size << endl;

	*size -= addedValues; addedValues = 0; i = 0;
	int *arr = new int[*size];

	cout << "DEBUG: size is now " << *size << endl;

	for(; i < *size - 1; i++) {
		if(values[i] == values[i + 1]) {
			continue;
		} else {
			arr[addedValues] = values[i];
			addedValues++;
		}
	}

	return arr;

}

// problem #11
int hanningWindow(int *arrayPart) {
	/*
	 * Uses the Hanning Window algorithm on a window of an array, assuming that
	 * window is a size of 5.
	 *
	 * @param	integer		arrayPart[]	the window to be hanned.
	 *
	 * @returns		weighted average of window.
	 */

	int windowSize = 5;

	int sum = 0;
	int weight = 0;

	for(int i = 0; i < windowSize; i++) {
		if(i < windowSize / 2) {
			sum += i * arrayPart[i];
			weight += i;
		} else {
			sum += (windowSize - i) * arrayPart[i];
			weight += windowSize - i;
		}
	}

	return sum/weight;

}

// problem #12
int* filterArray(int *arr, int size) {
	/*
	 * Uses the Hanning Window algorithm on an array, assuming that window is
	 * a size of 3.
	 *
	 * @param	integer		arr[]	array to be filtered.
	 * @param	integer		size	size of the array.
	 *
	 * @returns		weighted average of window.
	 */

	int *filteredArr = new int[size];

	for(int i = 0; i < size; i++) {
		if(i == 0 || i + 1 == size) {
			filteredArr[i] = 0;
			continue;
		}

		filteredArr[i] = hanningWindow(&arr[i]);
	}

	return filteredArr;

}

// problem #13
void graphArray(int *arr, int size, int high, int low) {
	/*
	 * Uses the Hanning Window algorithm on an array, assuming that window is
	 * a size of 3.
	 *
	 * @param	integer		arr[]	array to be filtered.
	 * @param	integer		size	size of the array.
	 *
	 * @returns		weighted average of window.
	 */

	for(int row = high; row > low; row--) {
		cout << row << ":";

		for(int col = 0; col < size; col++) {
			if(arr[col] == row)
				cout << "*";
			else
				cout << " ";
		}

		cout << endl;
	}

}

// problem #14
int** multiDimensionalArray(int *x, int *y) {
	/*
	 * Creates a new 2d-array on the heap, x wide and y tall, and fills it
	 * with zeroes. Then, randomly selects 5 integer pairs between [0, x) and
	 * [0, y) and fills in that space with a 1. If that space already has a
	 * 1 in it, then it moves tries to find a new space to put a one.
	 *
	 * @param	integer		*x		To be updated with the number of columns
	 * 								in the 2d-array.
	 * @param	integer		*y		To be updated with the number of rows
	 * 								in the 2d-array.
	 *
	 * @returns		Pointer to 2d-array.
	 */

	*x = 5 + (rand() % 5);
	*y = 4 + (rand() % 4);

	// create array on the heap
	int** a = new int*[*y];
	for(int i = 0; i < *y; ++i)
	    a[i] = new int[*x];

	// fill with zeroes
	for(int row = 0; row < *y; row++)
		for(int col = 0; col < *x; col++)
			a[row][col] = 0;

	// generate 5 random number pairs
	int randomX[5], randomY[5];

	for(int i = 0; i < 5; i++) {
		int newRandomX = rand() % *x;
		int newRandomY = rand() % *y;

		if(a[newRandomX][newRandomY] == 1) {
			*x = 5 + (rand() % 5);
			*y = 4 + (rand() % 4);
			i--;
		} else {
			a[newRandomX][newRandomY] = 1;
		}
	}

	return a;

}

