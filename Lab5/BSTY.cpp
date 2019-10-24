#include "BSTY.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

BSTY::BSTY() {
	root = NULL;
}

// You write:  insert a new node with data x (a string) into the 
// binary search tree
// This method should return true if a new node is inserted and 
// false if the data x is already in the tree
// Remember to check whether the new node will be the root
// (meaning the root is currently NULL) and if so, set the root
// to be the new node.
// Note: Make sure you make the new node point to its parent!!! 
// Note2: after you've inserted a new node, you should call the 
// adjustHeights method that will update the heights of all the 
// ancestors of the node that was just inserted.
bool BSTY::insertit(string x) {

	cout << "inserting " << x << endl;

	if(root == NULL) {
		root = new NodeT(x);
	} else {
		NodeT *n = root;

		while(n != NULL) {
			if(x < n->data) { // go left
				if(n->left == NULL) {
					n->left = new NodeT(x);
					n->left->parent = n;

					adjustHeights(n->left);
					return true;
				} else {
					n = n->left;
				}
			} else if(x > n->data) { // go right
				if(n->right == NULL) {
					n->right = new NodeT(x);
					n->right->parent = n;

					adjustHeights(n->right);
					return true;
				} else {
					n = n->right;
				}
			} else {
				return false; // x is already in the tree
			}
		}
	}
	
}

// the adjustHeights method updates the heights of every ancestor of the node n.
// This method will be massively useful with our next lab, so make sure you have 
// this working now.  It should be called whenever you change the height of a 
// a particular node.  So, for instance, when a new node is inserted as a leaf, 
// its height is 1.  The adjustHeights method should then check the parent to see
// if the height of the parent changes (the height of each node is the maximum of 
// the height of the left child and the height of the right child, plus 1).  If 
// the parent's height changes, then the grandparent's height should be checked and,
// if necessary, adjusted.  If the grandparent's height is updated, then the great-
// grandparent's height should be adjusted, etc.  The checking stops when either 
// the loop has worked its way up to the root, or until the currently being checked
// ancestor is not changed.  
void BSTY::adjustHeights(NodeT *n) {

	if(root == NULL)
		return;

	int height = n->height - 1;

	while(n != NULL) {
		int left = height, right = height;

		if(n->left != NULL)
			left = n->left->height;
		if(n->right != NULL)
			right = n->right->height;

		n->height = max(left, right) + 1;
		n = n->parent;
	}

}

void BSTY::printTreeIO() {
	if (root == NULL) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreeIO(root);
	}
}

// Print the tree in order (left child, then parent, then right child).
// Use the slides, but make sure you can understand how the tree is 
// traversed in order
void BSTY::printTreeIO(NodeT *n) {

	if(n == NULL)
		return;

	printTreeIO(n->left);

	n->printNode();

	printTreeIO(n->right);

}

void BSTY::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePre(root);
	}
}

// Prints the tree using pre-order traversal (parent, then left child, then right
// child.  Use the slides, but make sure you understand how a tree is traversed in
// pre-order
void BSTY::printTreePre(NodeT *n) {

	if(n == NULL)
		return;

	n->printNode();

	printTreePre(n->left);

	printTreePre(n->right);

}

void BSTY::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePost(root);
		cout << endl;
	}
}

// Prints the tree using pre-order traversal (left child, then right, then parent)
// Use the slides, but make sure you understand how a tree is traversed in
// post-order
void BSTY::printTreePost(NodeT *n) {

	if(n == NULL)
		return;

	printTreePost(n->left);

	printTreePost(n->right);

	n->printNode();

}

void BSTY::myPrint() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrint(root);
		cout << endl;
	}
}
void BSTY::myPrint(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrint(n->left);
		cout << n->data.length()-1;
		if (mine) {
			cout <<".";
			mine = false;
		}
		myPrint(n->right);
	}
}

// the find method takes as input a string, and finds whether that string is already
// in the tree or not.  If it is in the tree, that node is returned from the tree.
// If it isn't, NULL is returned.  
// NOTE: If the node can't be found, this method prints out that x can't be found.
// if it is found, the printNode method is called for the node.  
NodeT *BSTY::find(string x) {

	int comparisons = 0;
	NodeT *n = root;

	if(n == NULL) {
		return NULL;
	} else {
		while(n != NULL) {
			if(x < n->data) {
				n = n->left;
			} else if(x > n->data) {
				n = n->right;
			} else {
				return n;
			}
			comparisons++;
		}
	}

	cout << x << " not found" << endl;
	return NULL;

}

/*************************************************************************************/
/* Extra Credit Methods                                                              */
/* Challenging: worth 35 EC pts to go towards labs                                   */
/* NOTE: IF YOU CHOOSE NOT TO IMPLEMENT THESE METHODS, YOU ARE STILL RESPONSIBLE FOR */
/* UNDERSTANDING HOW THEY WORK!!                                                     */
/*************************************************************************************/
/* When removing a node from a binary search tree, the resulting tree MUST BE a binary
 * search tree.
 *
 * When removing a node, there are 3 conditions:
 * 1: when the node being removed has no children, in which case the node is deleted,
 * the node's parent is set to NULL, and the node's parent's height is adjusted (if
 * necessary) and heights on up are adjusted.
 * 2: when the node being removed has one child, in which case the node's parent points
 * to the node's child, and the node's child points to the node's parent, and the node
 * is deleted (and the height of the parent on up as necessary is adjusted)
 * 3: when the node has 2 children, in which case the left-most child of the node's
 * right child replaces the node.
 * A couple of notes about this one: you are replacing a node with a node that is lower
 * down in the tree.  That means that you are, in essence, removing the node from that
 * lower position and moving it up to the old node's location.  Thus the replacing node
 * must be removed using 1 or 2 above (why not 3?).  The heights must be adjusted after
 * the replacing node is removed from its old location but before it is inserted into its
 * new location.  Equally, the replacing node's height must be adjusted to be the larger of
 * its two children's heights before you adjust heights above that.
 *****************************************************************************************
 * remove(): takes as input a string, uses the find method to find the node in the tree that
 * holds that string, and then calls remove1, remove2, or remove3 depending on what type
 * of replacing should be done.  It adjusts the heights, deletes the node, and returns
 * true if the removal was successful.
 */
bool BSTY::remove(string s) {

	if(root == NULL)
		return false;

	NodeT *toRemove = find(s);

	if(toRemove == NULL)
		return false;

	if(toRemove->left == NULL && toRemove->right == NULL) // no children
		remove1(toRemove);
	else if(toRemove->left != NULL && toRemove->right != NULL) // two children
		remove3(toRemove);
	else // one child
		remove2(toRemove);

	return true;

}

/* remove1(): called when the node to be removed has no children. Takes as input the 
 * node to be removed, and sets the parent of the node to point to NULL.
 * helpful hint: if (n->parent->left == n) is true, then n is its parent's left child.
 * Make sure you check to whether n is the root or not.
 */
void BSTY::remove1(NodeT *n) {

	NodeT *parent = n->parent;

	if(parent == NULL) { // if this tree has one node n
		delete n;
		return;
	}

	if(parent->left == n)
		parent->left = NULL;
	else
		parent->right = NULL;

	delete n;

	adjustHeights(parent);

}

/* remove2(): called when the node to be removed has 1 child only.  Takes as input
 * the node to be removed and bypasses it by making the parent point to the node's
 * one child, and makes the node's one child point to the node's parent.
 * This one needs a bunch of checking - you need to see if the node is the parent's
 * left or right child, and you need to see if the node's child is its left or its
 * right child.
 * Also, make sure you check that if the node to be removed is the root, then the
 * one child becomes the root.
 */
void BSTY::remove2(NodeT *n) {

	NodeT *strandedChild, *deleteMe = n;

	if(n->left == NULL)
		strandedChild = n->right;
	else
		strandedChild = n->left;

	if(n->parent == NULL) { // if n is root, just make stranded child root.
		strandedChild->parent = NULL;
		root = strandedChild;
		delete deleteMe;
		return;
	} else {
		strandedChild->parent = n->parent;
	}

	if(n->parent->right == n)
		n->parent->right = strandedChild;
	else
		n->parent->left = strandedChild;

	delete deleteMe;

	adjustHeights(strandedChild);

}

/* remove3(): called when the node to be removed has 2 children.  Takes as input the
 * node to be removed.  The node to replace the node to be removed should be the
 * left-most descendant of the node's right child.  That way the binary search tree
 * properties are guaranteed to be maintained.
 * When replacing the node to be removed with the replacing node, the replacing node
 * is, in essence, being removed from its place in the tree, and thus replace1 or
 * replace2 methods should be used.
 * The new node's parent must be set to the removed node's parent, the removed node's
 * parent must point to the new node, the new node's left child must point to the
 * removed node's left child (and the child must point to the new node as a parent),
 * and the same for the right child.
 * Remember to take into account that the node being removed might be the root.
 */
void BSTY::remove3(NodeT *n) {

	NodeT *newN = findMin(n);

	if(newN->parent->left == newN)
		newN->parent->left = NULL;
	else
		newN->parent->right = NULL;

	newN->parent = n->parent;
	newN->left = n->left;
	newN->right = n->right;

	newN->left->parent = newN;
	newN->right->parent = newN;

	delete n;

}

/* findMin(): takes as input a node, and finds the left-most descendant of its 
 * right child. The left-most descendant is returned.
 */
NodeT *BSTY::findMin(NodeT *n) {

	n = n->right;

	while(n->left != NULL) {
		n = n->left;
	}

	return n;

}

void BSTY::myPrintEC() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrintEC(root);
		cout << endl;
	}
}
void BSTY::myPrintEC(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrintEC(n->left);
		cout << alpha[n->data.length()-2];
		myPrintEC(n->right);
	}
}

/************************************************************************/
