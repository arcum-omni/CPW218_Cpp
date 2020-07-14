/*
 * Author:   Travis Eiler
 * Title:    In Class Exercise #4
 *           https://cptc.instructure.com/courses/1962006/pages/in-class-exercise-chapter-3?module_item_id=45423028
 * Due Date: July 14, 2020
 * Course:   CPTC CPW218 C++ Summer 2020
 * Purpose:  See Below
 */

 // Preprocessor Directive
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function Headers
void dieRoll();
void approximatePi();
void prePostIncrement();

/*
 * Main Function Documentation
 */
int main() {
	//dieRoll();
	//approximatePi();
	prePostIncrement();
	return 0;
}

/*
 * Simulate rolling a die
 */
void dieRoll() {
	unsigned int minDieFace = 1;
	unsigned int maxDieFace = 6;
	default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	uniform_int_distribution<unsigned int> randomInt{ minDieFace, maxDieFace };
	
	for (unsigned int i{ 1 }; i <= 6; ++i) { 
		cout << randomInt(engine) << endl; 
	}
}

void approximatePi() {
	unsigned int minRando = 1;
	unsigned int maxRando = 1'000'000;
	default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	uniform_int_distribution<unsigned int> randomInt{ 1, 1'000'000 };


	int numTrials = 1'000'000;
	int insideCircle = 0;

	for (int i = 1; i <= numTrials; ++i) {
		double x = randomInt(engine) / 1'000'000.0;
		double y = randomInt(engine) / 1'000'000.0;

		double distance = sqrt(x * x + y * y);
		if (distance < 1.0) {
			//cout << "inside circle" << endl;
			++insideCircle;
		}
		/*else {
			cout << "outside circle" << endl;
		}*/
	}

	cout << "Pi is approximately " << 4.0 * insideCircle / numTrials << endl;
}

void prePostIncrement() {
	int a = 0;
	cout << a << endl;
	cout << a++ << endl;
	cout << a << endl;
	cout << ++a << endl;
	cout << a << endl;
}