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

}

/* initializes keyword to s, the valuesSize to 100
 * (or whatever you like for starting), the currSize to
 *0, and the values to be a dynamically allocated array of valuesSize */
hashNode::hashNode(string s) {

}

/* in addition, puts a value in the values
 * array and initializes currSize to 1 */
hashNode::hashNode(string s, string v) {

}

/* adds a new value to the end of the values array,
 * increases currSize, checks to make sure there’s more space, and, if not,
 * calls dblArray() */
void hashNode::addValue(string v) {

}

/* creates a new array, double the length, and copies over
 * the values. Sets the values array to be the newly allocated array. */
void hashNode::dblArray() {

}

/* returns a random string from the values array. If
 * there’s no values in the value array, then it returns an empty string. */
string hashNode::getRandValue() {

}

