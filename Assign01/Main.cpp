/*
 * Author:   Travis Eiler
 * Title:    Programing Assignment 1: Basic C++
 * Due Date: July 9, 2020
 * Course:   CPTC CPW218 C++ Summer 2020
 * Purpose:  This program uses the console to get a duration of time from the
 *           user in seconds, and convert it to the units of days, hours,
 *           minutes, and seconds.
 */

// Preprocessor Directive
# include <iostream>

using namespace std;

// Initialize Constants
const int SECONDS_PER_MINUTE = 60;
const int MINUTES_PER_HOUR = 60;
const int HOURS_PER_DAY = 24;

// Declare Functions
int calculateDays(long seconds);
int calculateHours(long seconds);
int calculateMinutes(long seconds);
int calculateSeconds(long seconds);
void displayResults(long seconds);

// Prompts user to enter a number of seconds as an integer value. 
// Calls function to displays the number of seconds input along with the 
// equivalent time in days, hours, minutes, and seconds.
int main() {
  long inputSeconds;
  cout << "Enter a number of seconds: ";
  cin >> inputSeconds;
  displayResults(inputSeconds);
  return EXIT_SUCCESS; // return to indicate normal exit, C++11 or later
}

// Returns the equivilant number of full day for a given number of seconds.
int calculateDays(long seconds) {
  return seconds / HOURS_PER_DAY / MINUTES_PER_HOUR / SECONDS_PER_MINUTE;
}

// Returns the equivilant number of full hours for a given number of seconds,
// after the days portion has been calculated and deducted from input.
int calculateHours(long seconds) {
  return seconds / SECONDS_PER_MINUTE / MINUTES_PER_HOUR % HOURS_PER_DAY;
}

// Returns the equivilant number of full minutes for a given number of seconds,
// after days and hours portions have been calculated and deducted from input.
int calculateMinutes(long seconds) {
  return seconds / SECONDS_PER_MINUTE % MINUTES_PER_HOUR;
}

// Returns the remainder of seconds for a given number of seconds, after days, 
// hours, and minutes portions have been calculated and deducted from input.
int calculateSeconds(long seconds) {
  return seconds % SECONDS_PER_MINUTE;
}

// Displays number of days, hours, minutes, and seconds equivilant 
// to the supplied number of seconds.
void displayResults(long seconds) {
  cout << seconds << " seconds is:" << endl
       << calculateDays(seconds) << " days, "
       << calculateHours(seconds) << " hours, "
       << calculateMinutes(seconds) << " minutes, "
       << calculateSeconds(seconds) << " seconds"
       << endl;
}