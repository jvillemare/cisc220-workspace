/*
 * Book.hpp
 *
 *  Created on: Sep 18, 2019
 *      Author: jvillemarette
 */

#include<iostream>
#include<string> // for string class
using namespace std;

#ifndef BOOK_HPP_
#define BOOK_HPP_

class Book {

	string authorFirstName;
	string authorLastName;

	string bookName;
	int yearPublished;

	int *ratings;

public:
	Book(string authorFirstName, string authorLastName, string bookName,
			int yearPublished);
	Book(string authorFirstName, string authorLastName, string bookName,
				int yearPublished, int ratings[10]);

	double averageRating();
	void printRatings();
	void printBookInfo();

	bool operator>(const Book b1, const Book b2);
	bool operator>=(const Book b1, const Book b2);

	bool operator<(const Book b1, const Book b2);
	bool operator<=(const Book b1, const Book b2);

	~Book(); // destructor
};

#endif /* BOOK_HPP_ */
