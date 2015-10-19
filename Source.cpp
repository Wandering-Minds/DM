<<<<<<< HEAD
#include<iostream>
#include<string>
using namespace std;

=======
#include <iostream>            //Assignment For Discrete Maths
# include <time.h>
using namespace std;

int i;      //Loop index variable.
int j;      //Loop index variable.
int l=0;      //Variable for result size.
char G='y'; //for control structure
int h;
>>>>>>> origin/master
int choice;

class Employee {

private:
	int ID;
	string Name;
	string Designation;
	int Salary;
	double Bonus;

public:
	void GetEmpDetails();
	double  GetSalary();
	void PrintDetails();
};

<<<<<<< HEAD
void Employee::GetEmpDetails()
=======
void Sets::show_Menu()  // show menu 
>>>>>>> origin/master
{
	cout << "\t\t###### ENTER EMPLOYEE DETAILS ######\n\n" << endl;
	cout << "Enter Your Name: ";
	cin >> Name;
	cout << "Enter Your Employee ID: ";
	cin >> ID;
	cout << "\nSelect Your Designation:\n\n1.\tJunior Employee\n2.\tSenior Employee\n3.\tExecutive Employee\n\nChoice:";
	cin >> choice;
}

double Employee::GetSalary()
{
	switch (choice)
	{
	case 1:
		Salary = 30000 * 12;
		Bonus = 0.20*Salary;
		Designation = "Junior Employee";
		return (Salary + Bonus);
		break;
	case 2:
		Salary = 40000 * 12;
		Bonus = 0.20*Salary;
		Designation = "Senior Employee";
		return (Salary + Bonus);
		break;
	case 3:
		Salary = 50000 * 12;
		Bonus = 0.20*Salary;
		Designation = "Executive Employee";
		return (Salary + Bonus);
		break;
	default:
		cout << "Invalid Choice!!!";
	}
}

void Employee::PrintDetails()
{
	system("CLS");
	cout << "\t\t###### EMPLOYEE DETAILS ######\n\n" << endl;
	cout << "Name: " << Name << "\nID: " << ID << endl;
	cout << "Designation: " << Designation << "\nSalary: Rs " << GetSalary() << " /- Per Annum" << endl;
}


void main()
{
	system("COLOR 3F");
	Employee e1;
	e1.GetEmpDetails();
	e1.GetSalary();
	e1.PrintDetails();
	system("pause");
}
