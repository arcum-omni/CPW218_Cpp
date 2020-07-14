/*
 * Author:   Travis Eiler
 * Title:    Programming Assignment 3: Loops
 *           https://cptc.instructure.com/courses/1962006/assignments/19470383?module_item_id=45278653
 * Due Date: July 23, 2020
 * Course:   CPTC CPW218 C++ Summer 2020
 * Purpose:  Calculate the following summantion to two decimal places.
 *   1/(1+2^0.5) + 1/(2^0.5+3^0.5) + 1/(3^0.5+4^0.5) + ... + 1/(n^0.5+(n+1)^0.5)
 *
 *   Extra Credit: Allow the user to determine the number of terms in the sum.
 */

 // Preprocessor Directive
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// Function Headers
double calculateSummation(int n);

/*
 * Main Function
 */
int main() {
	int nTerms;
	cout << "We will do a sum for you." << endl;
	cout << "How many terms do you want? ";
	cin >> nTerms;
	cout << setprecision(2) << fixed << calculateSummation(nTerms) << endl;
}

/*
 * Returns the summantion of to n terms:
 * 1/(1+2^0.5) + 1/(2^0.5+3^0.5) + 1/(3^0.5+4^0.5) + ... + 1/(n^0.5+(n+1)^0.5)
 */
double calculateSummation(int n) {
	double calculatedSum = 0;
	for (int i = 1; i <= n; ++i) {
		calculatedSum += 1 / (sqrt(i) + sqrt(i + 1));
	}
	return calculatedSum;
}