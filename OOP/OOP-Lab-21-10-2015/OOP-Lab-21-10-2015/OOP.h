#pragma once

class Distance {

private:
	int feet;
	float inches;
public:
	Distance(): feet(0),inches(0) {}
	Distance(int ft, float in): feet(ft),inches(in) {}
	void getDistance();
	void showDistance();
	Distance operator -(Distance);
	bool operator > (Distance);
};