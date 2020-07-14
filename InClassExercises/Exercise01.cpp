# include <iostream>

using namespace std;

int populationExercise() {
	cout << "Part 1: Population Exercise" << endl;
	long long worldPopulation;
	cout << "Enter World Population: ";
	cin >> worldPopulation;

	long long usPopulation;
	cout << "Enter US Population: ";
	cin >> usPopulation;

	double popPercentage = 100.0L * usPopulation / worldPopulation;

	cout << "\nThe population of the US is ";
	//cout << 100.0L * usPopulation / worldPopulation;
	cout << popPercentage;
	cout << "% of the worlds population." << endl;
	return 0;
}

int degreeExercise() {
	cout << "Part 2: Degrees Exercise" << endl;
	int latDegrees;
	int latMinutes;
	int latSeconds;
	const int MINUTES_PER_DEGREE = 60;
	const int SECONDS_PER_DEGREE = 3600;

	cout << "Enter a latitude degrees, minutes, and seconds:\n";
	cout << "First, enter the degrees: ";
	cin >> latDegrees;

	cout << "Next, enter the minutes of arc: ";
	cin >> latMinutes;

	cout << "Finally, enter the seconds of arc: ";
	cin >> latSeconds;

	// Convert to decimal
	double decimalDegrees = latDegrees + (double)latMinutes / MINUTES_PER_DEGREE + (double)latSeconds / SECONDS_PER_DEGREE;

	cout << "\n" << latDegrees << "degrees, " << latMinutes << " minutes, " << latSeconds << " seconds = ";
	cout << decimalDegrees << " degrees" << endl;
	return 0;
}

int main() {
	populationExercise();
	cout << "\n\n\n" << endl;
	degreeExercise();
	return 0;
}

