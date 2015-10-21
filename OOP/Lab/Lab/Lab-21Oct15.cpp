#include<iostream>
using namespace std;

class Time {

private:
	int hours;
	int minutes;
	int seconds;
public:
	Time(): hours(0),minutes(0),seconds(0) {}
	Time(int h,int m,int s) : hours(h),minutes(m), seconds(s) {}
	void print();
	Time operator+(Time);
	Time operator ++();
	Time operator ++(int);
	Time operator --();
	Time operator --(int);
};


void main()
{
	//Implementation Of Task 1
	//--------------------------------------------------
	Time t1(21,45,59), t2(4,15,1), t3;
	cout << "\nTime Of Obj1 Is As Follows:" << endl;
	t1.print();
	cout << "\nTime Of Obj2 Is As Follows:" << endl;
	t2.print();
	t3 = t1 + t2;
	cout << "\nThe Added Time Is As Follows:" << endl;
	t3.print();
	cout << endl;
	system("pause");
	//-------------------------------------------------
	system("cls");
	//Implementation Of Task 2
	//--------------------------------------------------
	Time t4(23, 59, 59), t5(12, 34, 35);
	cout << "\nTime Of Obj4 Is As Follows Before Increment:" << endl;
	t4.print();
	t4++;
	cout << "\nTime Of Obj4 Is As Follows After Increment:" << endl;
	t4.print();
	cout << "\nTime Of Obj5 Is As Follows Before Decrement:" << endl;
	t5.print();
	t5--;
	cout << "\nTime Of Obj5 Is As Follows After Decrement:" << endl;
	t5.print();
	cout << endl;
	system("pause");
}


Time Time::operator+(Time t)
{
	hours = hours + t.hours;
	if (hours >= 24)
	{
		hours = hours - 24;
	}
	
	minutes = minutes + t.minutes;
	if (minutes >= 60)
	{
		minutes = minutes - 60;
		hours++;
	}

    seconds = seconds + t.seconds;
	if (seconds >= 60)
	{
		seconds = seconds - 60;
		minutes++;
	}
	return *this;
}

Time Time::operator++ ()
{

	hours++;
	if (hours >= 24)
	{
		hours = hours - 24;
	}

	minutes++;
	if (minutes >= 60)
	{
		minutes = minutes - 60;
		hours++;
	}

	seconds++;
	if (seconds >= 60)
	{
		seconds = seconds - 60;
		minutes++;
	}
	return *this;
}

Time Time::operator--()
{
	hours--;
	minutes--;
	seconds--;
	return *this;
}

Time Time::operator++ (int)
{
	hours++;
	if (hours >= 24)
	{
		hours = hours - 24;
	}

	minutes++;
	if (minutes >= 60)
	{
		minutes = minutes - 60;
		hours++;
	}

	seconds++;
	if (seconds >= 60)
	{
		seconds = seconds - 60;
		minutes++;
	}
	return *this;
}

Time Time::operator--(int)
{
	hours--;
	minutes--;
	seconds--;
	return *this;
}





void Time::print()
{
	cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
}
