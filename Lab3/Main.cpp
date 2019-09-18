/*
 * Main.cpp
 *
 * James Villemarette
 * (No Partner)
 *
 * TA: Lauren Olson
 *
 *  Created on: Sep 12, 2019
 *      Author: jvillemarette
 *
 * This file contains functions for lab 3.
 * The functions aren’t necessarily related
 * in any way other than that they are required
 * for lab 3.
 *
 * As a rule, include the minimum, exclude the
 * maximum of a range: i.e. [0, 50)
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Try on Computer, Page 7, Section 3
#include "TicTacToe.hpp"
// Try on Computer, Page 12, Section 4
#include "Box.hpp"

void stars();

// Try on Computer, Page 3
class MathQuiz {

	int numberForQuiz;
	int countTotalQuestions;
	int countCorrectQuestions;

public:
	MathQuiz(int quizNumber) {
		numberForQuiz = quizNumber;
		countTotalQuestions = 0;
		countCorrectQuestions = 0;
	}

	void quizStudent() {
		/*
		 * Prompts student with question, asks for answer, receives answer,
		 * and processes answer.
		 *
		 * @returns		nothing.
		 */

		int multiplier = 1 + (rand() % 12);
		int response;

		cout << "What is " << numberForQuiz << " multiplied by "
				<< multiplier << "?" << endl;

		cin >> response;

		if(numberForQuiz * multiplier == response) {
			cout << endl << "You were correct!" << endl;
			countTotalQuestions++;
			countCorrectQuestions++;
		} else {
			cout << endl << "You were wrong, feel bad!" << endl;
			countTotalQuestions++;
		}
	}

	void quizStatus() {
		/*
		 * Prints out a running tally of correct vs total questions.
		 *
		 * @returns		nothing.
		 */

		cout << countCorrectQuestions << "/" << countTotalQuestions
				<< " is the ratio of correct-to-total questions." << endl;

	}
};

// Try on Computer, Page 4, Section 2
class HanningWindow {

	int windowSize;

	int *originalArray;
	int arraySize;

	int *filteredArray;

public:
	HanningWindow(int windowSize, int originalArray[], int arraySize,
			int filteredArray[]);

	// Page 4, Section 2.1
	int window(int *arrayPart);

	// Page 4, Section 2.2
	void filterArray();

	// Page 4, Section 2.3
	void graphArray(bool whichGraph);

	// Page 4, Section 2.4
	void changeWindowSize(int newWindowSize);

	// Page 4, Section 2.5
	void toString(bool whichArray);

};

HanningWindow::HanningWindow(int windowSize, int originalArray[], int arraySize,
		int filteredArray[]) { // @suppress("Class members should be properly initialized" // @suppress("Class members should be properly initialized")
	this->windowSize = windowSize;
	this->originalArray = originalArray;
	this->arraySize = arraySize;
	this->filteredArray = filteredArray;
}

// Page 4, Section 2.1
int HanningWindow::window(int *arrayPart) {
	/*
	 * Uses the Hanning Window algorithm on a window of an array, assuming that
	 * window is a size of 5.
	 *
	 * @param	integer		*arrayPart	the window to be hanned.
	 *
	 * @returns		weighted average of window.
	 */

	int sum = 0;
	int weight = 0;

	for (int i = 0; i < windowSize; i++) {
		if (i < windowSize / 2) {
			sum += i * arrayPart[i];
			weight += i;
		} else {
			sum += (windowSize - i) * arrayPart[i];
			weight += windowSize - i;
		}
	}

	return sum / weight;

}

// Page 4, Section 2.2
void HanningWindow::filterArray() {
	/*
	 * Uses the Hanning Window algorithm on an array, assuming that window
	 * is a size of what was specified.
	 *
	 * @returns		nothing.
	 */

	for (int i = 0; i < arraySize - windowSize; i++) {
		if (i == 0 || i + 1 == arraySize) {
			filteredArray[i] = 0;
			continue;
		}

		filteredArray[i] = window(&originalArray[i]);
	}

	filteredArray[arraySize] = 0;

}

// Page 4, Section 2.3
void HanningWindow::graphArray(bool whichGraph) {
	/*
	 * Makes a crude graph representation of a specified array held in
	 * this class.
	 *
	 * @param	bool	whichGraph		FALSE to use the original array,
	 * 									TRUE to use the filtered array.
	 *
	 * @returns		nothing.
	 */

	int high = -200, low = 200;
	int *arr;

	if (whichGraph)
		arr = this->filteredArray;
	else
		arr = this->originalArray;

	for (int i = 0; i < arraySize; i++) {
		if (arr[i] > high)
			high = arr[i];
		if (arr[i] < low)
			low = arr[i];
	}

	for (int row = high; row > low; row--) {
		cout << row << ":";

		for (int col = 0; col < arraySize; col++) {
			if (arr[col] == row)
				cout << "*";
			else
				cout << " ";
		}

		cout << endl;
	}

}

// Page 4, Section 2.4
void HanningWindow::changeWindowSize(int newWindowSize) {
	/*
	 * Update the Hanning window size to a new, odd number.
	 *
	 * @param	int	newWindowSize		Odd number. If not odd, then its
	 * 									value is decremented by one.
	 *
	 * @returns		nothing.
	 */

	if (newWindowSize % 2 == 0)
		newWindowSize--;

	windowSize = newWindowSize;

	filterArray();

}

// Page 4, Section 2.5
void HanningWindow::toString(bool whichArray) {
	/*
	 * Print a one-line, comma-separated representation of an array stored
	 * in this class.
	 *
	 * @param	bool	whichArray		FALSE to use the original array,
	 * 									TRUE to use the filtered array.
	 *
	 * @returns		nothing.
	 */

	int *arr;

	if (whichArray)
		arr = this->filteredArray;
	else
		arr = this->originalArray;

	for (int i = 0; i < arraySize; i++)
		cout << arr[i] << ", ";

	cout << endl;

}

int main() {

	// Seeding random number generator
	srand(time(NULL));

	// =========================================================================
	// Try on Computer, Page 3, Section 1
	stars();

	MathQuiz mq(5);

	for(int i = 0; i < 10; i++)
		mq.quizStudent();

	mq.quizStatus();
	// I know it said to run quizStatus after every input, but it would
	// take up a lot of screen output space/be kind of annoying.

	// =========================================================================
	// Try on Computer, Page 4, Section 2
	stars();
	int a[9] = {3,8,2,5,1,4,6,0,2};
	int b[9] = {3,8,2,5,1,4,6,0,2};

	HanningWindow hw(5, &a[0], 9, &b[0]);

	hw.filterArray();

	hw.toString(false);
	hw.toString(true);

	hw.graphArray(false);
	hw.graphArray(true);

	hw.changeWindowSize(3);

	hw.toString(false);
	hw.toString(true);

	hw.graphArray(false);
	hw.graphArray(true);

	// =========================================================================
	// Try on Computer, Page 7, Section 3
	stars();
	TicTacToe ttt("Me", "Myself");
	ttt.playGame();

	// =========================================================================
	// Try on Computer, Page 12, Section 4
	stars();

	 Box Box1(3.3, 1.2, 1.5);
	 Box Box2(8.5, 6.0, 2.0);
	 Box Box3 = Box1 + Box2;
	 double volume = Box3.getVolume();

	 cout << "Volume of Box3: " << volume << endl;

	 cout << "Box3 == Box1? Should be false (0): " <<
			 (Box1 == Box3) << endl;
	 cout << "Box3 == Box3? Should be true (1):  " <<
	 		 (Box3 == Box3) << endl;

	 return 0;


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
