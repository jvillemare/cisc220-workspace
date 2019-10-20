/*
 * DLL.hpp
 *
 *  Created on: Sep 29, 2019
 *      Author: Debra
 */

#ifndef DLL_HPP_
#define DLL_HPP_
#include "DNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

class DLL {
	friend class Coder;
	DNode *first;
	DNode *last;
	int size;
	char alpha[58]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',',','.','!','?','\''};
public:
	DLL();  // constructor - initializes an empty list
	DLL(int x);  // constructor, initializes a list with one new node with data x
	void push(int x);  // does what you'd think
	int pop();  //does what you'd think
	void addAtFront(int x);  // add a new node to the beginning of the list
	void addFirst(int x); // add the very first node to the list
	void insertAt(int ind, int x);  //insert x at index ind
	int removeAtK(int ind);  // remove the node at index ind and returns its data (indices start at 0)
	void reverse();  // reverse the list
	void skip();  // remove every other node - first stays, second is removed, third stays, fourth removed, etc. to end of list
	void printList();
	void printCode();
	~DLL();
};





#endif /* DLL_HPP_ */
