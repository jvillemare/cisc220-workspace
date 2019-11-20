/*
 * hashNode.cpp
 *
 *  Created on: Nov 8, 2019
 *      Author: jvillemarette
 */

#include "hashNode.hpp"

/* constructor-initializes keyword to “” , valuesSize to 0, and
 * currSize to 0 and values to NULL */
hashNode::hashNode() {
	keyword = "";
	valuesSize = 0;
	values = NULL;
	currSize = 0;
}

/* initializes keyword to s, the valuesSize to 100
 * (or whatever you like for starting), the currSize to
 * 0, and the values to be a dynamically allocated array of valuesSize */
hashNode::hashNode(string s) {
	keyword = s;
	valuesSize = 100;
	values = new string[valuesSize];
	currSize = 0;
}

/* in addition, puts a value in the values
 * array and initializes currSize to 1 */
hashNode::hashNode(string s, string v) {
	keyword = s;
	valuesSize = 100;
	values = new string[valuesSize];
	values[0] = v;
	currSize = 1;
}

/* adds a new value to the end of the values array,
 * increases currSize, checks to make sure there’s more space, and, if not,
 * calls dblArray() */
void hashNode::addValue(string v) {
	if(currSize >= valuesSize)
		dblArray();

	values[currSize] = v;
	currSize++;
}

/* creates a new array, double the length, and copies over
 * the values. Sets the values array to be the newly allocated array. */
void hashNode::dblArray() {
	string *newValues = new string[valuesSize * 2];

	for(int i = 0; i < valuesSize; i++)
		newValues[i] = values[i];

	values = newValues;
	valuesSize = valuesSize * 2;
}

/* returns a random string from the values array. If
 * there’s no values in the value array, then it returns an empty string. */
string hashNode::getRandValue() {
	if(currSize == 0)
		return "";

	return values[rand() % valuesSize];
}

