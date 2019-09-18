/*
 * lab1main.cpp
 *
 * Name: Takiyah Price
 * Partner Name: James Villemarette
 * T.A.: Lauren Olson
 * Created on: Aug 29, 2019
 *      Author: takiyah
 *
 * This file contains the functions required for Lab 1. The functions aren't
 * necessarily related in any way other than that they are required for Lab 1.
 */

#include <iostream>
using namespace std;

void stars();
bool is_prime(int x);
void sum();
int how_many_in_100000();
void times_table(int x);
void all_times_tables();
int collatz_conjecture(int answer);
void leap_years();
void x_of_stars(int arm_length);
void collatz_conjecture_range(int x, int y);


int main() {
	//Problem 1
	cout << "Problem 1" << endl;
	cout << "Hello, world!" << endl;

	cout << "Problem 2" << endl;
	stars();

	cout <<"Problem 3" << endl;
	//is_prime(7) -> 1 (true)
	cout << "Is 7 prime? Answer: " << is_prime(7) << endl;
	//is_prime(82) -> 0 (false)
	cout << "Is 82 prime? Answer: " << is_prime(82) << endl;
	//is_prime(7727) -> 1 (true)
	cout << "Is 7727 prime? Answer: " << is_prime(7727) << endl;
	stars();

	cout << "Problem 4" << endl;
	//test sum(): 447
	sum();
	stars();

	cout << "Problem 5" << endl;
	how_many_in_100000();
	stars();

	cout << "Problem 6" << endl;
	//test times_table(6): 1*6=6,2*6=12,3*6=18...12*6=72
	times_table(6);
	//test times_table(14): 1*14=14,2*14=28,3*14=42...12*14=168
	times_table(14);
	//test times_table(-4): 1*-4=-4,2*-4=-8,3*=4=-12...12*-4=-48
	times_table(-4);
	stars();

	cout << "Problem 7" << endl;
	//test all_times_tables(): 1*1=1,2*1=2...11*12=132,12*12=144
	all_times_tables();
	stars();

	cout << "Problem 8" << endl;
	int answer;
	cout << "Enter a natural positive number: " << endl;
		cin >> answer;
	//to test, entering 10: collatz_conjecture(10) -> 6
	//entering 21: collatz_conjecture(21) -> 7
	//entering 7: collatz_conjecture(7) -> 16
	cout << "The Collatz Conjecture looped " << collatz_conjecture(answer) << " times" << endl;
	stars();

	cout<< "Problem 9" << endl;
	//test leap_years(): 2020,2024,2028,2032,2036,2040...2416
	leap_years();
	stars();

	cout << "Problem 10" << endl;
	x_of_stars(10);		//x should have 11 stars on each arm
	x_of_stars(5);		//x should have 5 stars on each arm
	x_of_stars(16);		//x should have 17 stars on each arm
	stars();

	cout << "Problem 11" << endl;
	/* test collatz_conjecture_range(4,8):
	 * 4
	 * The Collatz Conjecture looped 2 times
	 * Collatz Conjecture is still working
	 * 5
	 * The Collatz Conjecture looped 5 times
	 * Collatz Conjecture is still working
	 * 6
	 * The Collatz Conjecture looped 8 times
	 * Collatz Conjecture is still working
	 * 7
	 * The Collatz Conjecture looped 16 times
	 * Collatz Conjecture is still working
	 * 8
	 * The Collatz Conjecture looped 3 times
	 * Collatz Conjecture is still working
	 */
	collatz_conjecture_range(4,8);

	/* test collatz_conjecture_range(44,46):
	 * 44
	 * The Collatz Conjecture looped 16 times
	 * Collatz Conjecture is still working
	 * 45
	 * The Collatz Conjecture looped 16 times
	 * Collatz Conjecture is still working
	 * 46
	 * The Collatz Conjecture looped 16 times
	 * Collatz Conjecture is still working
	 */
	collatz_conjecture_range(44,46);

	/* test collatz_conjecture_range(13,16):
	 * 13
	 * The Collatz Conjecture looped 9 times
	 * Collatz Conjecture is still working
	 * 14
	 * The Collatz Conjecture looped 17 times
	 * Collatz Conjecture is still working
	 * 15
	 * The Collatz Conjecture looped 17 times
	 * Collatz Conjecture is still working
	 * 16
	 * The Collatz Conjecture looped 4 times
	 * Collatz Conjecture is still working
	 */
	collatz_conjecture_range(13,16);

	return 0;

}

///Problem 2
void stars() {
	/*
	 * Input parameters: none
	 * Returns: void
	 * Purpose: prints out a line of stars
	 */
	cout << "************************************************" << endl;
}

//Problem 3
bool is_prime(int x) {
	/*
	 * Input parameters:
	 * 		x: integer for which the function is called to determine if it is prime
	 * Returns:
	 * 		a boolean- true if x is prime or false if x is not prime
	 * Purpose: Determines whether a number is prime
	 */
	int check = 2;

	while (x!= check) {
		if (x % check == 0) {
			return false;
		}
		check++;
	}
	return true;
}

//Problem 4
void sum() {
	/*
	 * Input parameters: none
	 * Returns: none
	 * Purpose: Calculates the total of the terms 1-300 and displays the
	 * 	subtotal after every 20 terms
	 */
	int count = 1;
	int sum = count;
	while (count <= 300) {
		if (count % 20 == 0) {
			cout << sum << endl;
		}
		count++;
		sum += count;

	}

}

//Problem 5
int how_many_in_100000() {
	/*
	 * Input parameters: none
	 * Returns:
	 * 		an int- total number of terms in the sum of 1-100000
	 * Purpose: Calculates the number of terms in the sum of 1-100000 and
	 * 	prints the result
	 */
	int sum = 1;
	int count = 0;
	while (sum < 100000) {
		count++;
		sum+= count;
	}
	cout << count << endl;
	return count;
}

//Problem 6
void times_table(int x) {
	/*
	 * Input parameters:
	 * 		x: an integer for which the function will calculate its multiplication
	 * 		table from 1 to 12
	 * Returns: none
	 * Purpose: Prints out the multiplication table for the given int
	 */

	for (int i = 1;i<=12;i++) {
		cout << i << "*" << x << "=" << i*x << endl;
	}
}

//Problem 7
void all_times_tables() {
	/*
	 * Input parameters: none
	 * Returns: none
	 * Purpose: Prints the multiplication table of every integer 1-12
	 */
	for (int i = 1;i<=12;i++) {
		times_table(i);
	}
}

//Problem 8
int collatz_conjecture(int answer) {
	/*
	 * Input parameters:
	 * 		answer: an integer for which the function will calculate the collatz
	 * 		conjecture
	 * Returns:
	 * 		an int- the number of loops
	 * Purpose: calculates the number of times the collatz conjecture loops before reaching
	 * 	one starting from the given number
	 */
	int count = 0;
	while (answer != 1) {
		count++;
		if (answer % 2==0) {
			answer/=2;
		}
		else {
			answer = answer*3 +1;
		}
	}
	//cout << "The Collatz conjecture looped "+ to_string(count)+ " times" << endl;
	return count;
}

//Problem 9
void leap_years() {
	/*
	 * Input parameters: none
	 * Returns: none
	 * Purpose: Calculates the leaps years for the next 400 years starting
	 * from 2017 and prints them out
	 */
	for (int y = 2017; y < 2417; y++) {
		if (y % 4==0) {
			if (y%100==0) {
				if (y%400==0) {
					cout << y << endl;
				}
			}
			else {
				cout << y << endl;
			}
		}
	}
}

//Problem 10
void x_of_stars(int arm_length) {
	/*
	 * Input parameters:
	 * 		arm_length: an int representing how many stars will be in each arm of the x
	 * 		(if even, it will have arm_length + 1 stars)
	 * Returns: none
	 * Purpose: Prints out an x of stars
	 */
	if (arm_length % 2==0) {
		arm_length++;
	}
	int line_num = 0;
	int original_arm_length = arm_length - 1;


	while (line_num < original_arm_length) {
		arm_length = line_num;
		while(arm_length > 0) {
			cout << " ";
			arm_length--;
		}
		cout << " *";
		arm_length = (original_arm_length * 2) - (line_num * 2) - 1;

		while(arm_length > 0) {
			cout << " ";
			arm_length--;
		}

		cout << "*" << endl;
		line_num++;
	}
	arm_length = original_arm_length;

	while (arm_length > 0) {
		cout << " ";
		arm_length--;
	}

	cout << " *" << endl;
	line_num = 0;

	while(line_num < original_arm_length) {
		arm_length = original_arm_length - line_num;

		while (arm_length > 0) {
			cout << " ";
			arm_length--;
		}

		cout << "*";
		arm_length = (line_num * 2) + 1;

		while (arm_length > 0) {
			cout << " ";
			arm_length--;
		}

		cout << "*" << endl;
		line_num++;
	}

}

//Problem 11
void collatz_conjecture_range (int lower, int upper) {
	/*
	 * Input parameters:
	 * 		lower- an int; the lower bound of the range of numbers on which the collatz conjecture
	 * 		 will be tested
	 * 		upper- an int; upper bound of the range
	 * Returns: none
	 * Purpose: tests the Collatz Conjecture on a range of given numbers; tells how many times it loops
	 * 	for each term and whether it is still working after testing each term
	 */
	for (int x=lower;x<=upper;x++) {
			cout << x << endl;
			cout << "The Collatz Conjecture looped " << collatz_conjecture(x) << " times" << endl;
			cout << "Collatz Conjecture is still working" << endl;
	}
}



