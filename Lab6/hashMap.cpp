/*
 * hashMapp.cpp
 *
 *  Created on: Nov 18, 2019
 *      Author: jvillemarette
 */

#include "hashMap.hpp"

/* when creating the map, make sure you
 initialize the values to NULL so you know whether that index has a key
 in it or not already. The Boolean values initialize the h1 and the c1
 boolean values, making it easier to control which hash and which
 collision methods you use.*/
hashMap::hashMap(bool hash1, bool coll1) {

	map = new hashNode[]; // TODO: This right?

	first = NULL; // for first keyword for printing to a file
	numKeys = 0;
	mapSize = 0;
	h1 = hash1; // if true, first hash function used, otherwise second hash function is used
	c1 = coll1; //if true, first collision method used, otherwise second collision method is used.
	collisionct1 = 0; //count of original collisions (caused by the hashing function used)
	collisionct2 = 0; //count of secondary collisions (caused by the collision handling method used)

}


/* adds a node to the map at the correct index based on the key string,
 * and then inserts the value into the  value field of the hashNode
 * Must check to see whether there's a node at that location. If
 * there's nothing there (it's NULL), add the hashNode with the keyword
 * and value.
 *
 * If the node has the same keyword, just add the value to the list of
 * values.
 *
 * If the node has a different keyword, keep calculating a new hash
 * index until either the keyword matches the node at that index's
 * keyword, or until the map at that index is NULL, in which case
 * you'll add the node there.
 *
 * This method also checks for load, and if the load is over 70%, it
 * calls the reHash method to create a new longer map array and rehash
 * the values
 *
 * if h1 is true, the first hash function is used, and if it’s false,
 * the second is used.
 * if c1 is true, the first collision method is used, and if it’s
 * false, the second is used
 */
void hashMap::addKeyValue(string k, string v) {

}

/* uses calcHash and reHash to calculate and return the index of where
 * the keyword  k should be inserted into the map array.
 */
int hashMap::getIndex(string k) {

	return 0;

}

// hash function
int hashMap::calcHash(string k) {

	return 0;

}

// hash function 2
int hashMap::calcHash2(string k) {

	return 0;

}

/* I used a binary search on an array of prime numbers to find the
 * closest prime to double the map Size, and then set mapSize to that
 * new prime. You can include as one of the fields an array of prime
 * numbers, or you can write a function that calculates the next prime
 * number. Whichever you prefer.
 */
void hashMap::getClosestPrime() {

}

/* when size of array is at 70%, double array size and rehash keys */
void hashMap::reHash() {

}

/* getting index with collision method 1 (note – you may modify the
 * parameters if you don’t need some/need more)
 */
int hashMap::collHash1(int h, int i, string k) {

	return 0;

}

/* getting index with collision method 2 (note – you may modify the
 * parameters if you don’t need some/need more)
 */
int hashMap::collHash2(int h, int i, string k) {

	return 0;

}

/* finds the key in the array and returns its index. If it's not in
 *  the array, returns -1.
 */
int hashMap::findKey(string k) {

	return 0;

}

void hashMap::printMap() {

}
