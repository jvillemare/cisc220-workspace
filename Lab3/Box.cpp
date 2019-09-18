/*
 * Box.cpp
 *
 *  Created on: Sep 17, 2019
 *      Author: jvillemarette
 */

#include "Box.hpp"

Box::Box(double l, double b, double h) {
	/*
	 * Constructor.
	 *
	 * @param	double	l	length of a box.
	 * @param	double	b	breadth of a box.
	 * @param	double	h	height of a box.
	 *
	 * @returns		nothing.
	 */

	length = l;
	breadth = b;
	height = h;
}

double Box::getVolume() {
	/*
	 * Calculates the volume of a box by multiplying its length, breadth, and
	 * height, together.
	 *
	 * @returns		volume of the box.
	 */

	return length * breadth * height;
}

Box Box::operator+(Box b) {
	/*
	 * Handles the addition of two different boxes.
	 *
	 * @param	Box	b	Second box in the right-hand field being added.
	 *
	 * @returns		One added together box.
	 */
	Box box(-1.0, -1.0, -1.0); // Yarrington told me to handle it, this way.
	box.length = length + b.length;
	box.breadth = breadth + b.breadth;
	box.height = height + b.height;
	return box;
}

bool Box::operator==(Box b) {
	/*
	 * Handles the equivalence of two different boxes.
	 *
	 * @param	Box	b	Second box being compared.
	 *
	 * @returns		TRUE if the boxes have the same length, breadth, and height,
	 * 				FALSE if otherwise.
	 */

	return length == b.length && breadth == b.breadth && height == b.height;

}

