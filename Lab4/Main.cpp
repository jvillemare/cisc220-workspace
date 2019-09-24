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

#include "Book.hpp"
#include "SLL.hpp"

// for formatting purposes
void stars();
void findBestBook(Book *books, int arraySize);

int main() {

	// Part A: Class/pointers (35 pts)
	// Question 1: Create an array of 5 book objects (on the stack)...
	stars();
	cout << "Lab 4B: Part A: Question 1:" << endl;

	int ratingsBad[10] = {4, 1, 5, 3, 2, 1, 2, 2, 4, 5};
	int ratingsGood[10] = {9, 8, 10, 9, 4, 8, 6, 4, 9, 10};

	Book books[4] = {
		Book("Andrew", "Jackson", "If I Won", 1865, ratingsBad),
		Book("Dr.", "Seuss", "Cat in a Hat", 1972, ratingsBad),
		Book("Abraham", "Lincoln", "My Love of Theater", 1864, ratingsBad),
		Book("Debra", "Yarrington", "Data Structures and You", 2019,
					ratingsGood)
	};

	// TODO: Why does this crash the program?
	//findBestBook(books, 4);

	// Question 2: Create one book object on the heap and print out that...
	stars();
	cout << "Lab 4B: Part A: Question 2:" << endl;

	Book *heapBook = new Book("Don't Know", "I", "Running Out of Titles",
			2019, ratingsBad);

	heapBook->printBookInfo();

	// Question 3: Create an array of 2 book objects on the heap, and...
	stars();
	cout << "Lab 4B: Part A: Question 3:" << endl;

	Book *heapBookArray[2];

	heapBookArray[0] = new Book("Me", "Myself",
			"Lesson's Learnt", 2019, ratingsBad);
	heapBookArray[1] = new Book("Me", "Myself",
			"Summer Days", 2018, ratingsBad);

	for(int i = 0; i < 2; i++) {
		heapBookArray[i]->printBookInfo();
		cout << endl;
	}

	// =========================================================================
	// Part B: Linked Lists (Assumed 45 pts, it's not specified)
	stars();

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
		list->insertInOrder(r[i], s[i]);
		list->printSLL();
	}

	cout << "Ave: " << list->getAve() << endl;
	cout << "Popping " << list->pop() << endl;

	list->printSLL();

	cout << "Popping " << list->pop() << endl;

	list->printSLL();

	delete list;

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

// Part 1, Question 1
void findBestBook(Book *books, int arraySize) {

	int ratings[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

	Book bestBook = Book("", "", "", 0, ratings);

	arraySize--;

	while(arraySize) {
		if(books[arraySize].averageRating() > bestBook.averageRating())
			bestBook = books[arraySize];

		arraySize--;
	}

	cout << "Found the Best Book of them all!" << endl;

	bestBook.printBookInfo();

}
