// Time Calculator (Hours_Minutes).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int check;
	int vidNumber = 1;
	vector<int> hours;
	vector<int> minutes;
	vector<int> seconds;

	cout << "Type in times and then -1 for hours to calculate" << endl;
	// gets all the numbers from the user
	do {
		cout << "Entry " << vidNumber << endl;
		cout << "Hours: ";
		cin >> check; //the number the user enters for hours, minutes, and seconds. 
		if (check == -1) break; //ends loop to do calculations
		hours.push_back(check);
		cout << "Minutes: ";
		cin >> check;
		minutes.push_back(check);
		cout << "Seconds: ";
		cin >> check;
		seconds.push_back(check);
		cout << endl;
		vidNumber++; //counter to keep track of which part user is at

	} while (check >= 0);

	// adding up all the raw hours
	int totHours = 0;
	for (int i = 0; i < hours.size(); i++) {
		totHours += hours.at(i);
	}
	// adding up all the raw minutes
	int totMinutes = 0;
	for (int i = 0; i < minutes.size(); i++) {
		totMinutes += minutes.at(i);
	}
	// adding up all the raw seconds
	int totSeconds = 0;
	for (int i = 0; i < seconds.size(); i++) {
		totSeconds += seconds.at(i);
	}
	
	// make appropriate adjustments to seconds and minutes if seconds are >= 60
	do {
		if (totSeconds >= 60) {
			totMinutes += 1;
			totSeconds -= 60;
		}
	} while (totSeconds > 59);
	// make appropriate adjustments to hours and minutes if minutes are >= 60
	do {
		if (totMinutes >= 60) {
			totHours += 1;
			totMinutes -= 60;
		}
	} while (totMinutes > 59);

	// display final information
	cout << "Total time - " << totHours << ":" << totMinutes << ":" << totSeconds << endl;
	cout << "Press any key to quit" << endl;
	return 0;
}
