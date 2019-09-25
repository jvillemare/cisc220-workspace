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
	 * Default Constructor where ratings are initialized to 0.
	 *
	 * @param	string	authorFirstName		The first name of the author.
	 * @param	string	authorLastName		The last name of the author.
	 * @param	string	bookName			The name of the author's book.
	 * @param	int		yearPublished		The year the book was published.
	 *
	 * @returns		nothing.
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
	 * Second Constructor that accepts all aforementioned parameters, as well
	 * as a pointer to an integer array of 10 ratings.
	 *
	 * @param	string	authorFirstName		The first name of the author.
	 * @param	string	authorLastName		The last name of the author.
	 * @param	string	bookName			The name of the author's book.
	 * @param	int		yearPublished		The year the book was published.
	 * @param	int[]	ratings				10 intger ratings of the book,
	 * 										from [0, 10].
	 *
	 * @returns		nothing.
	 */

	this->authorFirstName = authorFirstName;
	this->authorLastName = authorLastName;
	this->bookName = bookName;
	this->yearPublished = yearPublished;

	this->ratings = ratings;

}

double Book::averageRating() {
	/*
	 * Calculate the average rating of this Book.
	 *
	 * @returns		average of all ratings.
	 */

	double sum = 0.0;

	for(int i = 0; i < 10; i++)
		sum += ratings[i];

	return sum / 10.0;

}

void Book::printRatings() {
	/*
	 * Run the averageRating() function and print out formatted ratings.
	 *
	 * @returns		nothing.
	 */

	double avgRating = averageRating();

	if(avgRating == 0.0)
		cout << "(no ratings yet)" << endl;
	else
		cout << "Rating:......" << avgRating << endl;

}

void Book::printBookInfo() {
	/*
	 * Prints all the information about the Book, including the title,
	 * author, year published, and ratings.
	 *
	 * @returns		nothing.
	 */

	cout << "Title:......." << bookName << endl <<
			"Author:......" << authorLastName << ", " << authorFirstName << endl <<
			"Published:..." << yearPublished << endl;

	printRatings();

}

bool Book::operator>(Book b) {
	/*
	 * Overrides > comparison operator.
	 *
	 * @param	Book	b		Second-book being compared against.
	 *
	 * @returns		TRUE if this Book has a higher average rating than b,
	 * 				FALSE if not.
	 */

	return this->averageRating() > b.averageRating();

}

Book::~Book() {
	/*
	 * Destructor.
	 *
	 * @returns		Nothing.
	 */

	delete [] ratings;

}
