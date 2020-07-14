/*
 * Author:   Travis Eiler
 * Title:    Programming Assignment 2: Decisions
 *           https://cptc.instructure.com/courses/1962006/assignments/19470245?module_item_id=45278225
 * Due Date: July 15, 2020
 * Course:   CPTC CPW218 C++ Summer 2020
 * Purpose:  Calculate sitting charges for Dorian Gray Portrait Studio.
 *             Based upon:
 *             * number of subjects (see fee schedule)
 *             * day of the week (weekends += 20%)
 */

// Preprocessor Directive
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function Headers
int getNumberOfSubjects();
int getDayOfWeek();
int calculateSittingFee(int numSub, int dayOfWeek);
void displaySittingQuote(int numSub, int dayOfWeek, int dowFee);

/*
 * Calls function to request number of subjects
 * Calls function to request day of the week
 * Calls functions to calculate sitting fees and display quote
 */
int main() {
	cout << "This program calculates the cost of a portrait sitting.\nThe "
		 << "price depends on the number of subjects in the portrait and day "
		 << "of the week.\n" << endl;
	
	int numSub = getNumberOfSubjects();
	int isWeekend = getDayOfWeek();
	int sittingFee = calculateSittingFee(numSub, isWeekend);

	displaySittingQuote(numSub, isWeekend, sittingFee);
}

/*
 * Returns integer number of subjects
 */
int getNumberOfSubjects() {
	int numSub = -1;
	// confer with client to determine maximum number of subjects per sitting
	int maxSubjects = 25;
	while (numSub < 1 || numSub > maxSubjects) {
		cout << "Enter the number of subjects: ";
		cin >> numSub;
		// input validation for number of subjects
		// numSub must be > 0 and <= studio maximum
		if (numSub < 1 || numSub > maxSubjects) {
			cout << "Invalid Entry, Subjects must be between 1 and "
				<< maxSubjects << "!" << endl;
		}
	}
	return numSub;
}

/*
 * Returns integer for day of the week
 * 0 for weekdays, Monday through Friday
 * 1 for weekends, Saturday and Sunday
 */
int getDayOfWeek() {
	int isWeekend = -1;
	// input validation to ensure only 0 or 1 is entered
	while (isWeekend != 0 && isWeekend != 1) {
		cout << "Will the sitting be on a weekend? (0=no, 1=yes): ";
		cin >> isWeekend;
	}
	return isWeekend;
}

/*
 * Returns sitting fee for a portrait
 * Fee based upon number of subjects with 20% surcharge for weekends
 */
int calculateSittingFee(int numSub, int dayOfWeek) {
	int sittingFee;

	// Portrait Subject Fee Schedule
	switch (numSub) {
		case 1:
			sittingFee = 100;
			break;
		case 2:
			sittingFee = 130;
			break;
		case 3:
			sittingFee = 150;
			break;
		case 4:
			sittingFee = 165;
			break;
		case 5:
			sittingFee = 175;
			break;
		case 6:
			sittingFee = 180;
			break;
		default:
			sittingFee = 185;
	}

	/*
		// if, else if, else decision making process to show proficiency
		if (numSub == 1) {
			totalFee = 100;
		}
		else if (numSub == 2) {
			totalFee = 130;
		}
		else if (numSub == 3) {
			totalFee = 150;
		}
		else if (numSub == 4) {
			totalFee = 165;
		}
		else if (numSub == 5) {
			totalFee = 175;
		}
		else if (numSub == 6) {
			totalFee = 180;
		}
		else {
			totalFee = 185;
	}*/
	
	// Adds Weekend Surcharge
	if (dayOfWeek) {
		sittingFee = sittingFee * 120 / 100;
	}

	return sittingFee;
}

/*
 * Diplays portrait sitting quote to user
 */
void displaySittingQuote(int numSub, int isWeekend, int totalFee) {
	string isSubjectSingular;
	string dayOfAppointment;
	
	if (numSub == 1) {
		isSubjectSingular = "subject";
	}
	else {
		isSubjectSingular = "subjects";
	}
	
	if (isWeekend) {
		dayOfAppointment = "weekend";
	}
	else {
		dayOfAppointment = "weekday";
	}
	cout << "For a sitting with " << numSub << " " << isSubjectSingular << ","
		 << endl;
	cout << "on a " << dayOfAppointment << ", the cost is $" << totalFee << "."
		 << endl;
}