#include<iostream>
#include "OOP.h";
using namespace std;

void Distance::getDistance()
{
	cout << "Enter Feet: ";
	cin >> feet;
	cout << "Enter Inches: ";
	cin >> inches;
	if (inches >= 12)
	{
		inches = inches - 12;
		feet++;
	}
}

void Distance::showDistance()
{
	cout << "Enter Feet: "<<feet;
	cout << "Enter Inches: "<<inches;
}

Distance Distance::operator -(Distance d)
{
	feet - d.feet;
	inches - d.inches;
	return *this;
}

bool Distance::operator > (Distance d)
{
	if (feet > d.feet && inches > d.inches)
		return true;
	else
		return false;
}