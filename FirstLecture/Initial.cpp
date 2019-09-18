/*
 * Initial.cpp
 *
 *  Created on: Aug 29, 2019
 *      Author: jvillemarette
 */

#include <iostream>

using namespace std;

void func(int x);

int main() {
	cout << "Hey there, what's your name?" << endl;

	string x;

	cin >> x;

	cout << "Your name is " << x << "? Haha." << endl;

	func(3);

	cout << endl << "How many times do you laugh?" << endl;

	int y;

	cin >> y;

	func(y);

	return 0;
}

void func(int x) {
	for(int i = 0; i < x; i++)
		cout << endl << "Haha" << endl;
}


