/*
	Program Name: Sample Program 1
	Purpose: This program converts two English measurements
			to metric.
	Coder: Paul Zoski
	Date: 3/27/99
	Last Modified: JL Popyack, 3/25/2002
*/

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	const double INCHES_PER_METER = 39.37;
	const double POUNDS_PER_KG = 2.20;


	string height_str;
	string weight_str;
	double height;
	double weight;

	cout << "METRIC CONVERTER" << endl << endl;
	cout << "Enter your height in inches ";
	getline(cin, height_str, '\n');

	cout << "Enter your weight in pounds ";
	getline(cin, weight_str, '\n');
	
	if (int pos = height_str.find('/') != -1) // user entered fraction, special handling
	{
		string numerator = height_str.substr(0, pos);
		string denominator = height_str.substr(pos + 1, height_str.length() - 1);
		double num = stod(numerator); // stod is built in C function that converts a string to a double
		double den = stod(denominator);
		height = num / den;
	}
	else {
		height = stod(height_str);
	}

	if (int pos = weight_str.find('/') != -1)
	{
		string numerator = weight_str.substr(0, pos);
		string denominator = weight_str.substr(pos + 1, weight_str.length());
		double num = stod(numerator);
		double den = stod(denominator);
		weight = num / den;
	}
	else {
		weight = stod(weight_str);
	}

	double metric_height = height / INCHES_PER_METER;
	double metric_weight = weight / POUNDS_PER_KG;

	cout << "Your height is " << metric_height << " meters." << endl;
	cout << "Your weight is " << metric_weight << " kilograms." << endl;

	int dummyval;
	cout << "Type any key to exit: ";
	cin >> dummyval;

	return 0;
}
