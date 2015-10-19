#include<iostream>
#include<string>
using namespace std;

int i, j, k;
int a, b, c, choice;
class Sets                                        // making a sets class
{
private:
	string A[50], B[50], R[50];					// declaring arrays					
	// value for sets


public:
	void show();
	//	void choice();
	void sUnion();
	void intersection();
	string getdata();
	void subtraction();
	//	void complement();


};
void Sets::show()										// selecting an option
{


	cout << "Press 1 for Union" << endl;
	cout << "Press 2 for intersection" << endl;




}
string Sets::getdata()
{
	cout << "Please enter number of elements of your first set: ";  //Getting input for first sets element size.
	cin >> a;                                                      //Storing size in variable.
	cout << endl;
	cout << "Please enter number of elements of your second set: ";   //Getting input for second sets element size.
	cin >> b;                                                         //Storing size in variable.
	cout << endl;
	for (i = 0; i < a; i++)                                 	//loop for get input elements for first set.
	{
		cout << "Please enter element no " << i + 1 << " of your first set: ";
		cin >> A[i];
	}
	cout << "Elements of your first set = { ";
	for (i = 0; i < a; i++)                     //loop for get input elements for first set.
	{
	 cout << A[i];
		if (i < a - 1)
		{
			cout << " , ";
		}
	}//loop printing second set elements.
	cout << " }";
	cout << "\n\n";
	for (i = 0; i < b; i++)
	{
		cout << "Please enter element no " << i + 1 << " of your second set: ";
		cin >> B[i];
	}
	cout << "Elements of your second set = { ";
	for (i = 0; i < b; i++)
	{
		cout << B[i];
		if (i < b - 1)
		{
			cout << " , ";
		}
	}
	//loop printing second set elements.
	cout << " }";
	cout << "\n\n";


	return "";
}
void Sets::sUnion()
{
	cout << getdata();
	//compute union
	for (i = 0; i < a; i++)
	{
		R[i] = A[i];
		k++;
	}
	int e = k;
	for (i = 0; i < b; i++)
	{
		int found = 0;
		for (int j = 0; j < e; j++)
		{
			if (B[i] == R[j])
			{
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			R[k] = B[i];
			k++;
		}
	}
	cout << "A Union B : \n\n\t\t { ";
	for (i = 0; i < k; i++)
	{
		cout << R[i] << "," << " ";
	}
	cout << "}" << endl;
	k = 0;
	R[i] = { "NULL" };
}   // function end
void Sets::intersection()
{
	cout << getdata();
	//compute intersection
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			if (A[i] == B[j])
			{
				B[j] = { "0" };
				R[k] = A[i];
				k++;
			}
		}
	}
	cout << "A Intersection B = { ";
	for (i = 0; i < k; i++)
	{
		cout << R[i] << " ";
	}
	cout << "}" << endl;
	k = 0;
	R[i] = { "NULL" };
}
void Sets::subtraction()
{
	cout << getdata();
	// doing subtraction
	for (i = 0; i < a; i++)
	{
		int found = 0;
		for (j = 0; j < b; j++)
		{

			if (A[i] == B[j])
			{
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			R[k] = A[i];
			k++;
		}
	}
	for (i = 0; i < b; i++)
	{
		int found = 0;
		for (j = 0; j < a; j++)
		{
			if (B[i] == A[j])
			{
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			R[k] = B[i];
			k++;
		}
	}
	cout << "A Subtraction B = { ";
	for (i = 0; i < k; i++)
	{
		cout << R[i] << "," << " ";
	}
	cout << "}" << endl;
}
void main()
{
	Sets s, d;
	s.show();
	s.sUnion();
	s.intersection();
	s.subtraction();

	system("pause");
}
