/*
 * BinHeap.cpp
 *
 * James Villemarette
 * (No Partner)
 *
 * TA: Lauren Olson
 *
 *  Created on: Oct 29, 2019
 *      Author: jvillemarette
 *
 * This file contains functions for lab BinHeap. The functions aren’t necessarily
 * related in any way other than that they are required for lab 4.
 */

#include "BinHeap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

BinHeap::BinHeap(string arr[], int len) {
	heaplen = 0;
	arrlen = len;
	heap = new string[arrlen];
	for (int i = 0; i < len; i++) {
		insertHeap(arr[i]);
	}
	printHeap();
}

BinHeap::~BinHeap() {
	delete [] heap;
}

void BinHeap::printHeap() {
	cout << endl;
	for(int i = 0; i < arrlen; i++) {
		cout << i << ", ";
	}
	cout << endl;
	for(int i = 0; i < heaplen; i++) {
		cout << heap[i] << ", ";
	}
	cout << endl;
}

int BinHeap::findMax(int x, int y) {
	if((x < heaplen) && (y < heaplen)) {
		if (heap[x] > heap[y]) {
			return (x);
		} else {
			return (y);
		}
	} else if(x < heaplen) {
		return x;
	} else {
		return -1;
	}
}

void BinHeap::insertHeap(string s) {
	heap[heaplen] = s;

	bubbleUp(heaplen);

	heaplen++;
}

string BinHeap::deleteHeap() { // returns the string that was deleted
	string root = heap[0];

	heap[0] = heap[heaplen];
	bubbleDown(0);

	return root;
}

void BinHeap::swap(int i1, int i2) {
	string temp = heap[i1];
	heap[i1] = heap[i2];
	heap[i2] = temp;
}

void BinHeap::bubbleUp(int child) {
	int parent = (child - 1) / 2;

	if(parent >= 0 && heap[child] > heap[parent]) {
		swap(child, parent);
		bubbleUp(parent);
	}
}

void BinHeap::bubbleDown(int i) {
	int followMe = findMax( (i*2) + 1, (i*2) + 2 );

	if(heap[i] < heap[followMe] && (i*2) + 2 < heaplen) {
		swap(i, followMe);
		bubbleDown(followMe);
	}
}

/***************************************************************************/
/* Part 2 */

string BinHeap::deleteHeap2() {
	string root = heap[0];

	heap[0] = heap[heaplen];
	heap[heaplen + 1] = root;
	bubbleDown(0);

	return root;
}

void BinHeap::deleteAll() {
	for(int i = 0, originalHeapLen = heaplen; i < originalHeapLen; i++)
		deleteHeap2();
}

/********************************************************************************/
