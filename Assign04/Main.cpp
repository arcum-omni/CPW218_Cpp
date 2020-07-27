/*
 * Author:   Travis Eiler
 * Title:    Programming Assignment 4: Functions
 *           https://cptc.instructure.com/courses/1962006/assignments/19470384?module_item_id=45278657
 * Due Date: July 30, 2020
 * Course:   CPTC CPW218 C++ Summer 2020
 * Purpose:  To create functions below the main function,
 *           by using function prototypes.
 */

// Preprocessor Directive
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function Prototype(s)/Interface(s)
double mathRootSum(int num);
bool isOdd(int num);
int countEs(string str);
vector<int> cumulative(vector<int> &vec); 
string factors56(int num);


/*
 * Main Function
 * Assignment 4, Starter Code
 */
int main() {
	// test mathRootSum
	cout << (abs(mathRootSum(624) - 24.0) < 0.0000000000001 ? "Success" : "Fail")
		<< " on mathRootSum test 1" << endl;
	cout << (abs(mathRootSum(1000) - 30.6386) < 0.0001 ? "Success" : "Fail")
		<< " on mathRootSum test 2" << endl;

	// test isOdd
	cout << (isOdd(3) ? "Success" : "Fail")
		<< " on isOdd test 1" << endl;
	cout << (isOdd(-1) ? "Success" : "Fail")
		<< " on isOdd test 2" << endl;
	cout << (!isOdd(-2) ? "Success" : "Fail")
		<< " on isOdd test 3" << endl;

	// test countEs
	cout << (countEs("Elephant") == 2 ? "Success" : "Fail")
		<< " on countEs test 1" << endl;
	cout << (countEs("Aardvark") == 0 ? "Success" : "Fail")
		<< " on countEs test 2" << endl;
	cout << (countEs("Elephantine") == 3 ? "Success" : "Fail")
		<< " on countEs test 3" << endl;

	// test cumulative
	vector<int> v1{ 1, 1, 2, 3, 5 };
	vector<int> v1Cumulative{ 1, 2, 4, 7, 12 };
	cumulative(v1);
	cout << (v1 == v1Cumulative ? "Success" : "Fail")
		<< " on cumulative test 1" << endl;

	vector<int> v2{ 1 };
	vector<int> v2Cumulative{ 1 };
	cumulative(v2);
	cout << (v2 == v2Cumulative ? "Success" : "Fail")
		<< " on cumulative test 2" << endl;

	vector<int> v3{};
	vector<int> v3Cumulative{};
	cumulative(v3);
	cout << (v3 == v3Cumulative ? "Success" : "Fail")
		<< " on cumulative test 3" << endl;

	// test factors56
	cout << (factors56(10) == "10 is divisible by 5 or 6, but not both" ? "Success" : "Fail")
		<< " on factors56 test 1" << endl;
	cout << (factors56(30) == "30 is divisible by both 5 and 6" ? "Success" : "Fail")
		<< " on factors56 test 2" << endl;
	cout << (factors56(23) == "23 is not divisible by either 5 or 6" ? "Success" : "Fail")
		<< " on factors56 test 3" << endl;

	system("pause");
}

/*
 * Returns the summantion of to n terms:
 * 1/(1+2^0.5) + 1/(2^0.5+3^0.5) + 1/(3^0.5+4^0.5) + ... + 1/(n^0.5+(n+1)^0.5)
 */
double mathRootSum(int n) {
	double calculatedSum = 0;
	for (int i = 1; i <= n; ++i) {
		calculatedSum += 1 / (sqrt(i) + sqrt(i + 1));
	}
	return calculatedSum;
}
/*
 * This function should return true if its parameter is an odd number,
 * false if it is even.
 */
bool isOdd(int n) {
	if (n % 2 == 0) {
		return false;
	}
	else {
		return true;
	}
}
/*
 * This function accepts a string parameter and
 * returns the number of occurrences of the letter 'E', 
 * counting upper case and lower case 'e' characters.
 */
int countEs(string s) {
	int sumOfE = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (tolower(s[i]) == 'e') {
			++sumOfE;
		}
	}
	return sumOfE;
}

/*
 * This function accepts as a parameter a reference to a vector of integers, and 
 * modifies it so that each element contains the cumulative sum of the elements 
 * up through that index.*/
vector<int> cumulative(vector<int> &v) {
	if (v.size() > 1) {
		for (int i = v.size() - 1;i >= 0;--i) {
			for (int j = 0; j < i; ++j) {
				v[i] += v[j];
			}
		}
	}
	return v;
}

/*
 * This function accepts a positive integer parameter and checks whether that
 * number is divisible by both 5 and 6, or neither of them, or just one of them.
 */
string factors56(int n) {
	string returnStatement = "";
	if (n % 5 == 0 && n % 6 == 0) {
		returnStatement = to_string(n) + " is divisible by both 5 and 6";
	}
	else if (n % 5 == 0 || n % 6 == 0) {
		returnStatement = to_string(n) + " is divisible by 5 or 6, but not both";
	}
	else {
		returnStatement = to_string(n) + " is not divisible by either 5 or 6";
	}

	return returnStatement;
}