/*
 * Book.cpp
 *
 *  Created on: Sep 18, 2019
 *      Author: jvillemarette
 */

#include "Book.hpp"

Book::Book(string authorFirstName, string authorLastName, string bookName,
		int yearPublished) {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

	this->authorFirstName = authorFirstName;
	this->authorLastName = authorLastName;
	this->bookName = bookName;
	this->yearPublished = yearPublished;

	this->ratings = new int[10];

	for(int i = 0; i < 10; i++)
		ratings[i] = 0;

}

Book::Book(string authorFirstName, string authorLastName, string bookName,
				int yearPublished, int ratings[10]) {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

	this->authorFirstName = authorFirstName;
	this->authorLastName = authorLastName;
	this->bookName = bookName;
	this->yearPublished = yearPublished;

	this->ratings = ratings;

}

double Book::averageRating() {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

	double sum = 0.0;

	for(int i = 0; i < 10; i++)
		sum += ratings[i];

	return sum / 10.0;

}

void Book::printRatings() {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

	double avgRating = averageRating();

	if(avgRating == 0.0)
		cout << "(no ratings yet)" << endl;
	else
		cout << "Rating: " << avgRating << endl;

}

void Book::printBookInfo() {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

	cout << "Title:......." << bookName << endl <<
			"Author:......" << authorLastName << ", " << authorFirstName << endl <<
			"Published:..." << yearPublished << endl;

	printRatings();

}

bool Book::operator>(const Book b) {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

	return this->yearPublished > b.yearPublished;

}

bool Book::operator>=(const Book b) {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

	return this->yearPublished >= b.yearPublished;

}

bool Book::operator<(const Book b) {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

	return this->yearPublished < b.yearPublished;

}

bool Book::operator<=(const Book b) {
	/*
	 * TODO: ...
	 *
	 * @param	string	playerX		...
	 *
	 * @returns		...
	 */

	return this->yearPublished <= b.yearPublished;

}

Book::~Book() {
	/*
	 * Destructor.
	 *
	 * @returns		Nothing.
	 */

	delete [] ratings;

}
