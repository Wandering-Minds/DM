//Assignment For Discrete Maths
#include<iostream>
#include<time.h>
using namespace std;


int i;      //Loop index variable.
int j;      //Loop index variable.
int l=0;      //Variable for result size.
char G='y';
int h;
int choice;
char set_count='A';

class Sets {
private:
	long int Arr[50];  //Array for the set.
	int  sel;     	 //set eliment size.
public: 
	void show_Menu();
	void execute_sets(Sets,Sets);
	void sets_union(Sets,Sets);
	void sets_intersection(Sets,Sets);
	void sets_difference(Sets,Sets);
	void get_set_elements();
	void power_sets(Sets,Sets);
	void Curtatian_products(Sets,Sets);
};

void Sets::show_Menu()
{
	cout << "Please enter 1 for Union set \n";
	cout << "Please enter 2 for Intersection set \n";
	cout << "Please enter 3 for Subtraction set \n";
	cout << "Please enter 4 for Curtatian product \n";
	cout << "Please enter 5 for Power set \n";
	cout << "Select Your Choice: ";
	G = 'y';
	cin >> h;
}

void Sets::execute_sets(Sets A, Sets B)
{
	cout << "Welcome To Sets Program" << endl;
	while (G == 'y')
	{
		show_Menu();
		switch (h)
		{
		case 1:
		{
			sets_union(A,B);
		}
		break;

		case 2:
		{
			cout << "\t\tIntersection set:\n\n\t\t ";
			sets_intersection(A,B);
		}
		break;

		case 3:
		{
			sets_difference(A,B);
		}
		break;

		case 4:
		{
			cout << "\t\tCartesian product: \n\n\t\t{ ";
			Curtatian_products(A,B);
		}
		break;

		case 5:
		{
			power_sets(A,B);
		}
		break;

		default:

			cout << "You entered wrong key\n";
			break;
		}

		cout << "\n\n\n\n\n";
		cout << "Please enter 'y' for check again or 'n' for stop: ";
		cin >> G;
    }

}

void Sets::sets_union(Sets A, Sets B)
{
	//compute union
	for (i = 0; i<A.sel; i++)
	{
		Arr[i] = A.Arr[i];
		l++;
	}
	int e = l;
	for (i = 0; i<B.sel; i++)
	{
		int found = 0;
		for (int j = 0; j<e; j++)
		{
			if (B.Arr[i] == Arr[j])
			{
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			Arr[l] = B.Arr[i];
			l++;
		}
	}
	cout << "A Union B : \n\n\t\t { ";
	for (i = 0; i < l; i++)
	{
		cout << Arr[i];
		if (i <l-1)
		{
			cout << " , ";
		}
	}
	cout << "}" << endl;
}

void Sets::sets_intersection(Sets A, Sets B) 
{
	//compute intersection
	for (i = 0; i<A.sel; i++)
	{
		for (j = 0; j<B.sel; j++)
		{
			if (A.Arr[i] == B.Arr[j])
			{
				B.Arr[j] = 0;
				Arr[l] = A.Arr[i];
				l++;
			}
		}
	}
	cout << "A Intersection B = { ";
	for (i = 0; i<l; i++)
	{
		cout << Arr[i]; 
		if (i < l - 1)
		{
			cout << " , ";
		}
	}
	cout << " }" << endl;

}

void Sets::sets_difference(Sets A,Sets B)
{

	for (i = 0; i<A.sel; i++)
	{
		int found = 0;
		for (j = 0; j<B.sel; j++)
		{

			if (A.Arr[i] == B.Arr[j])
			{
				found = 1;
				break;

			}
		}
		if (found == 0)
		{
			Arr[l] = A.Arr[i];
			l++;

		}

	}

	for (i = 0; i<B.sel; i++)
	{
		int found = 0;
		for (j = 0; j<A.sel; j++)
		{

			if (B.Arr[i] == A.Arr[j])
			{
				found = 1;
				break;

			}
		}
		if (found == 0)
		{
			Arr[l] = B.Arr[i];
			l++;

		}

	}
	cout << "A Subtraction B = { ";
	for (i = 0; i<l; i++)
	{
		cout << Arr[i];
		if (i < l - 1)
		{
			cout<< " , ";
		}
	}
	cout << "}" << endl;
}


void Sets::Curtatian_products(Sets A, Sets B)
{

	
	for (i = 0;i<A.sel;i++)
	{

		for (j = 0;j<B.sel;j++)
		{
			cout << " [ ";
			cout << A.Arr[i] << " , " << B.Arr[j] << " ] ";
		}
	}
	cout << "}";

}

void Sets::power_sets(Sets A, Sets B)
{

	cout << "Power set: \n\n\t\t{ ";
	cout << "[0], ";
	for (i = 0;i<A.sel;i++)
	{
		cout << "[";
		cout << A.Arr[i];
		cout << "], ";
	}

	for (i = 0;i<B.sel- 1;i++)
	{
		cout << "[ ";
		cout << A.Arr[i] << " , " << A.Arr[i + 1];
		cout << "], ";
	}
	cout << "[ ";
	for (i = 0;i<A.sel;i++)
	{
		cout << A.Arr[i];
	}
	cout << "]";
	cout << " }";
}


void Sets::get_set_elements()
{
	char dummy;
	srand(time(NULL));                        //  using the time seed from srand explanation
	cout << "Select the Input Method.\n1. Enter Elements Yourself\n2. Use Random Numbers." << endl;
	cin >> choice;
	cout << "Please enter number of elements For Set "<<set_count<<" : ";    //Getting input for  sets element size.
	cin >> sel;                                                   //Storing size in variable.
	cout << endl;                                               //getting new line
	
	if (choice == 1)
	{
		cout << "Please enter Set Elements For Set "<<set_count<<":  ";
		for (i = 0;i < sel;i++)                                         //loop for get input elements for  set.
		{
			cin >> Arr[i];
			if(i<sel-1)
				cin>>dummy;
		}
	}
	
	else
	{
		for (i = 0;i < sel;i++)                                         //loop for get input elements for  set.
		{
			Arr[i] = (rand() % 100) + i;
		}
	}

	cout << "Elements of the Set " << set_count <<" : { ";
	for (i = 0;i<sel;i++) 	                                  //loop for showing elements of the set.
	{
		cout << Arr[i];
		if (i<sel - 1)
		{
			cout << " , ";
		}
	}
	cout << " }";
	cout << "\n\n";
	++set_count;
}




void main()
{                               
	Sets S1,S2,S3;                   //Create three objects of sets class 
	S1.get_set_elements();           //get elements in obj s1
	S2.get_set_elements();           //get elements in obj s2
	S3.execute_sets(S1,S2);          //the result of union/intersection/differnce would be stored in Arr[] of obj 3....Reason to call exexute_sets() on obj3 and passing S1 and S2 as arguments
	system("pause");
}
