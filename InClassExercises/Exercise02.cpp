/*
 * Author:   Travis Eiler
 * Title:    In Class Exercise #2
 *           https://cptc.instructure.com/courses/1962006/pages/in-class-exercise-chapter-2?module_item_id=45386283
 * Due Date: July 7, 2020
 * Course:   CPTC CPW218 C++ Summer 2020
 * Purpose:  See Below
 */

// Preprocessor Directive
# include <cmath>
# include <ctime>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string> 

using namespace std;

// Initialize Constants
const int FIRST_CONSTANT = 0;

// Declare Functions
void wrapAround();
void physics();
void triangle();
void randomCharacter();
void fullName();
void retirementAge();


// Main Documentation
int main() {
	wrapAround();
	system("pause");
	physics();
	system("pause");
	triangle();
	system("pause");
	randomCharacter();
	system("pause");
	fullName();
	system("pause");
	retirementAge();
	return EXIT_SUCCESS; // return to indicate normal exit, C++11 or later
}

/* 
   If an int value is the highest possible int value and you add onto it,
   what happens?
 */
void wrapAround() {
	cout << sizeof(short) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;

	unsigned int smallNumber = 2'147'483'647;
	//unsigned short int smallNumber; // unsigned only 0 to max
	//smallNumber = 32767 + 32767;
	cout << "small number:" << smallNumber << endl;
	smallNumber++;
	cout << "small number:" << smallNumber << endl;
	smallNumber++;
	cout << "small number:" << smallNumber << endl;
}

/* 
   In physics, a common useful equation for finding the position s of a body in
   linear motion at a given time t, based on its initial position s0, initial 
   velocity v0, and rate of acceleration a, is the following:
   
   s = s0 + v0 t + ½ at2
   
   Write code to declare variables for s0 with a value of 12.0, v0 with a value 
   of 3.5, a with a value of 9.8, and t with a value of 10, and then write the 
   code to compute s on the basis of these values. At the end of your code, 
   print the value of your variable s to the console.
 */
void physics() {
	double initialPosition = 12.0;
	double initialVelocity = 3.5;
	double rateOfAcceleration = 9.81;
	double time = 10.0;

	cout << "Enter Initial Position(m): " << endl;
	cin >> initialPosition;
	cout << "Enter Initial Velocity(m/s): " << endl;
	cin >> initialVelocity;
	cout << "Enter Rate of Acceleration(m/s/s): " << endl;
	cin >> rateOfAcceleration;
	cout << "Enter Time Duaration(s): " << endl;
	cin >> time;

	double position = initialPosition + initialVelocity * time + 0.5 
	                * rateOfAcceleration * time * time;

	cout << "The body traveled " << setprecision(2) << fixed << position << " meters." << endl;
}

/*
   Write code to prompt the user to enter the three side lengths of a triangle 
   and display the area of that triangle. If the side lengths are a, b, and c, 
   the area is calculated as:

   double s = (a + b + c) / 2;

   double area = sqrt( s * (s - a) *(s - b) * (s - c));

   When testing your code, be sure to use a valid triangle.
 */
void triangle() {
	double a, b, c;

	cout << "Enter three side lengths of a triangle: ";
	cin >> a >> b >> c;

	// Ensure valid triangle. The sum of any two sides of a triangle must be
	// longer than the third side to be valid.
	if (a+b <= c || a+c <= b || b+c <= a) {
		cout << "Triangle is invalid" << endl;
	}
	else {
		// Heron's Formula using semi-perimeter "s" to find area
		double s = (a + b + c) / 2;
		double area = sqrt(s * (s - a) * (s - b) * (s - c));

		cout << "The area of the triangle is " << setprecision(4) << area 
			 << endl;
	}
}

/*
   Write code that displays a random character. Note that ASCII uppercase chars 
   run from A = 65 to Z = 90 and lower case from a = 97 to z = 122.
 */
void randomCharacter() {
	int elapsedTime = time(nullptr);
	
	srand(elapsedTime);

	char lowerCase = rand() % 26 + 97; // A = 97 >> Z = 122
	char upperCase = rand() % 26 + 65; // A = 65 >> Z = 90

	cout << "upper: " << upperCase << endl 
		 << "lower: " << lowerCase << endl;
	cout << "A char is " << sizeof(char) << " byte." << endl;
}

/*
   Write code that asks the user to enter their first name, middle name, and last
   name into three variables. Build a string consisting of last name, first name,
   middle initial (with a period). Print that string.
 */
void fullName() {
	string first, middle, last, fullFormatted;
	cout << "Enter your full name: ";
	cin >> first >> middle >> last;
	
	fullFormatted = last + ", " + first + " " + middle[0] + ".";
	cout << fullFormatted << endl;
}

/*
   Write code that asks the user for their age and name. Assuming they will 
   retire at age 66, print out this: name, you can retire in x years.
 */
void retirementAge() {
	int userAge;
	string userName;
	cout << "Enter your age: ";
	cin >> userAge;
	cin.ignore();
	cout << "Enter your full name: ";
	getline(cin, userName);
	cout << userName << ", you can retire in " << 66 - userAge << " years."
		 << endl;
}