/*
 * Author:   Travis Eiler
 * Title:    In Class Exercise #3
 *           https://cptc.instructure.com/courses/1962006/pages/in-class-exercise-chapter-3?module_item_id=45423028
 * Due Date: July 9, 2020
 * Course:   CPTC CPW218 C++ Summer 2020
 * Purpose:  See Below
 */

// Preprocessor Directive
#include <iostream>
#include <string>

using namespace std;

// Declare Functions = Function Headers
void decisionAssignment();
void printEqual(int a, int b, int c);
string season(int month, int day);
string checkDate(int month, int day);


// Main Documentation
int main() {

    /*decisionAssignment();
    system("pause");

    int a, b, c;
    cout << "Enter a number for A: ";
    cin >> a;
    cout << "Enter a number for B: ";
    cin >> b;
    cout << "Enter a number for C: ";
    cin >> c;
    printEqual(a, b, c);
    system("pause");*/

    int month, day;
    cout << "Enter the month(1-12): ";
    cin >> month;
    cout << "Enter the day(1-31): ";
    cin >> day;
    cout << season(month, day) << endl;
 
    return 0;
}

// In C++, zero is false and any other number is true. To demonstrate this, 
// start with an empty project, add a new item named InClassChapter3.
void decisionAssignment() {
    int a, b;
    cout << "Enter a number for A: ";
    cin >> a;
    cout << "Enter a number for B: ";
    cin >> b;

    if (a == b) {
        cout << "a and b are equal" << endl;
    }
    else {
        cout << "a and b are NOT equal" << endl;
    }
}

/*
   The method should not return anything (void).
   If any parameter is less than 0, print text "Invalid Value".
   If all parameters are equal, print text "All numbers are equal".
   If all parameters have different values, print text "All numbers are different".
   Otherwise, print "Neither all are equal nor different".
*/
void printEqual(int a, int b, int c) {
    if (a<0 || b<0 || c<0) {
        cout << "Invalid Values" << endl;
    }
    else if (a==b && b==c){
        cout << "All Numbers Are Equal" << endl;
    }
    else if (a != b && b != c && a != c) {
        cout << "All Numbers Are Different" << endl;
    }
    else {
        cout << "All Number are neither equal or differnet!" << endl;
    }
}

/*
   Write a function named season that takes two integers as parameters 
   representing a month and day and that returns a string indicating the season 
   for that month and day. Assume that months are specified as an integer between 
   1 and 12 (1 for January, 2 for February, and so on) and that the day of the 
   month is a number between 1 and 31.
   
   If the date falls between 12/16 and 3/15, you should return "Winter".
   If the date falls between 3/16 and 6/15, you should return "Spring". 
   If the date falls between 6/16 and 9/15, you should return "Summer". 
   And if the date falls between 9/16 and 12/15, you should return "Fall".
*/
string season(int month, int day) {
    if (month > 12 || month < 1) {
        return "Invalid Month";
    }
    else if (day < 1) {
        return "Day must be greater than 0";
    }
    else if (day > 31) {
        return "No month has more than 31 days";
    }
    else if (month == 2 && day > 29) {
        return "Feb only has 28 or 29 days, depending upon the year";
    }
    else if (month == 4 && day > 30) {
        return "April only has 30 days";
    }
    else if (month == 6 && day > 30) {
        return "June only has 30 days";
    }
    else if (month == 9 && day > 30) {
        return "September only has 30 days";
    }
    else if (month == 11 && day > 30) {
        return "November only has 30 days";
    }

    //winter
    if (month == 1 || month == 2 || (month == 3 && day < 16) || (month == 12 && day > 15)) {
        return "Winter";
    }

    //spring
    if (month == 4 || month == 5 || (month == 3 && day > 15) || (month == 6 && day < 16)) {
        return "Spring";
    }

    //summer
    if (month == 7 || month == 8 || (month == 6 && day > 15) || (month == 9 && day < 16)) {
        return "Summer";
    }

    //fall
    if (month == 10 || month == 11 || (month == 9 && day > 15) || (month == 12 && day < 16)) {
        return "fall";
    }
}

string checkDate(int month, int day) {
    if (month > 12 || month < 1 || day > 31 or day < 1) {
        return "Invalid Date";
    }
}