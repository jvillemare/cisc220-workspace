/*
 * hashMapp.cpp
 *
 *  Created on: Nov 18, 2019
 *      Author: jvillemarette
 */

#include "hashMap.hpp"
#include <iostream>
using namespace std;

/* when creating the map, make sure you
 * initialize the values to NULL so you know whether that index has a key
 * in it or not already. The Boolean values initialize the h1 and the c1
 * boolean values, making it easier to control which hash and which
 * collision methods you use.
 */
hashMap::hashMap(bool hash1, bool coll1) {
	mapSize = 101;

	map = new hashNode *[mapSize]; // TODO: This right? Not specified, anywhere.

	for(int i = 0; i < mapSize; i++)
		map[i] = NULL;

	first = ""; // for first keyword for printing to a file
	numKeys = 0;
	h1 = hash1;
	c1 = coll1;
	collisionsFromHashing = 0;
	collisionsFromHandling = 0;
}

/* adds a node to the map at the correct index based on the key string, and then
 * inserts the value into the value field of the hashNode.
 *
 * Must check to see whether there's a node at that location. If there's nothing
 * there (it's NULL), add the hashNode with the keyword and value.
 *
 * If the node has the same keyword, just add the value to the list of values.
 *
 * If the node has a different keyword, keep calculating a new hash index until
 * either the keyword matches the node at that index's keyword, or until the map
 * at that index is NULL, in which case you'll add the node there.
 *
 * This method also checks for load, and if the load is over 70%, it calls the
 * reHash method to create a new longer map array and rehash the values
 *
 * if h1 is true, the first hash function is used, and if it’s false, the second
 * 		is used.
 *
 * if c1 is true, the first collision method is used, and if it’s false, the
 * 		second is used
 */
void hashMap::addKeyValue(string k, string v) {

	if(numKeys == 0)
		first = k;

	cout << "problem1" << endl;
	double nK = numKeys, mS = mapSize;
	cout << "numKeys=" << nK << " and mapSize=" << mS << " divides to=" << nK/mS << endl;

	if(nK / mS >= 0.7) {
		cout << "REHASHING!!!!!!!!!!!!!!!!!" << endl;
		reHash();
	}

	cout << "problem2" << endl;

	int index = getIndex(k);

	cout << "problem3, index=" << index << endl;

	if(map[index] == NULL) {
		cout << "problem3a" << endl;
		map[index] = new hashNode(k, v);
		numKeys++;
	} else if(map[index]->keyword == k) {
		cout << "problem3b" << endl;
		map[index]->addValue(v);
	} else {
		cout << "problem3c" << endl;
		collisionsFromHashing++;
		if(c1) { // use FIRST collision handling function
			int cH1 = collHash1(index, k, v);

			if(map[cH1] == NULL) {
				map[cH1] = new hashNode(k, v);
				numKeys++;
			}
		} else { // use SECOND collision handling function
			int cH2 = collHash2(index, k, v);

			if(map[cH2] == NULL) {
				map[cH2] = new hashNode(k, v);
				numKeys++;
			}
		}

		cout << "problem3a" << endl;
	}

	cout << "problem4" << endl;
}

/* Yarrington: uses calcHash and reHash to calculate and return the index of
 * where the keyword k should be inserted into the map array.
 */
int hashMap::getIndex(string k) {
	if(h1) // use FIRST hashing function
		return calcHash1(k);
	else // use SECOND hashing function
		return calcHash2(k);
}

/* hash function
 *
 * Methodology: Add ASCII values and mod by mapSize.
 */
int hashMap::calcHash1(string k) {
	int sum = 0;
	for(int i = 0; k[i] != '\0'; i++) {
		sum += k[i];
	}
	if(sum < 0)
		sum *= -1;

	return sum % mapSize;
}

/* hash function 2
 *
 * Methodology: Use the string length to spread it over the hashMap. Precision
 * it by first three letters.
 */
int hashMap::calcHash2(string k) {
	int len = k.length();

	int h = 0;
	for(int i = len-1; i >0; i--) {
		h = (19*h + (int)k[i]) % mapSize;
	}
	if(h < 0)
		h *= -1;

	return h;
}

/* I used a binary search on an array of prime numbers to find the closest prime
 * to double the map Size, and then set mapSize to that new prime. You can
 * include as one of the fields an array of prime numbers, or you can write a
 * function that calculates the next prime number. Whichever you prefer.
 *
 * We do this because we're using modulus with the array size.
 */
int hashMap::getClosestPrime() {
	int primes[] = {101, 211, 431, 863, 1733, 3467};
	for(int i = 0; i < 5; i++)
		if(primes[i] > mapSize)
			return primes[i];

	return 7919;
}

/* Yarrington: when size of array is at 70%, double array size and rehash keys
 *
 * PowerPoint: IDEAL array size:  double the amount of data, and then go up to
 * 		the nearest prime!
 *
 */
void hashMap::reHash() {
	int oldMapSize = mapSize;
	mapSize = getClosestPrime();
	hashNode **newMap = new hashNode *[mapSize];

	for(int i = 0; i < mapSize; i++)
		newMap[i] = NULL;

	for(int i = 0; i < oldMapSize; i++) {
		if(map[i] != NULL) {
			newMap[getIndex(map[i]->keyword)] = map[i];
		}
	}

	map = newMap;
}

/* Yarrington: Getting index with collision method 1 (note – you may modify the
 * parameters if you don’t need some/need more)
 *
 * !!!!!!!!!!!!!!!!! LINEAR PROBING !!!!!!!!!!!!!!!!!
 *
 * Methodology: Keep looking for the next spot on the right. If hits the end of
 * the mapSize, loop over to the beginning of the array looking for a new spot.
 *
 * @param	integer		from	where in the hashMap should collHash1 look for a
 * 								new space from.
 * @param	string		k		value to insert.
 *
 * @return	new index where k was inserted.
 */
int hashMap::collHash1(int from, string k, string v) {
	cout << "colHash1" << endl;
	while(map[from] != NULL) {
		if(map[from]->keyword == k) {
			if(v != "")
				map[from]->addValue(v);
			break;
		}
		from++;
		collisionsFromHandling++;
		if(from > mapSize)
			from = 0;
	}
	return from;
}

/* Yarrington: Getting index with collision method 2 (note – you may modify the
 * parameters if you don’t need some/need more)
 *
 * !!!!!!!!!!!!!!!!! QUADRATIC PROBING !!!!!!!!!!!!!!!!!
 *
 * Methodology: If index (from) is already occupied, move forward one index to
 * find an open spot, move backwards two indexes to find an open spot, move
 * forward three indexes to find an open spot, and so on and so forth.
 *
 * @param	integer		from	where in the hashMap should collHash1 look for a
 * 								new space from.
 * @param	string		k		value to insert.
 *
 * @return	new index where k was inserted.
 */
int hashMap::collHash2(int from, string k, string v) {
	int quadraticFactor = 1;
	while(map[from] != NULL) {
		if(map[from]->keyword == k) {
			if(v != "")
				map[from]->addValue(v);
			break;
		}
		from += quadraticFactor++;
		collisionsFromHandling++;
		if(from > mapSize)
			from = from % mapSize;
	}
	cout << "works" << endl;
	return from;
}

/* finds the key in the array and returns its index. If it's not in the array,
 * returns -1.
 */
int hashMap::findKey(string k) {
	int index = getIndex(k);

	if(map[index] == NULL)
		return -1;

	if(map[index]->keyword == k)
		return index;

	if(c1) { // linear probing
		return collHash1(index, k, "");
	} else { // quadratic probing
		return collHash2(index, k, "");
	}
}

/* Yarrington: I wrote this solely to check if everything was working.
 *
 * ...
 */
void hashMap::printMap() {
	for(int i = 0; i < mapSize; i++) {
		if(map[i] != NULL) {
			cout << "hashNode (" << map[i]->keyword << ")" << endl;
			cout << "...values:";

			for(int j = 0; j < map[i]->valuesSize; j++)
				cout << map[i]->values[j] << " ";

			cout << endl;
		}
	}
}
