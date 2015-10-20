#include<iostream>
#include<time.h>
using namespace std;


int i;      //Loop index variable.
int j;      //Loop index variable.
int l;      //Variable for result size.
char G = 'y';
int h;
int choice;
char set_count = 'A';

class Sets {
private:
	long int Arr[50];  //Array for the set.
	int  sel;     	 //set eliment size.
public:
	void show_Menu();
	void execute_sets(Sets, Sets);
	Sets sets_union(Sets, Sets);
	void show_union();
	Sets compound_union(Sets,Sets,Sets,Sets,Sets);
	void sets_intersection(Sets, Sets);
	void sets_difference(Sets, Sets);
	void get_set_elements();
	void power_sets(Sets, Sets);
	void Curtatian_products(Sets, Sets);
};

Sets Sets::compound_union(Sets A,Sets B, Sets C, Sets D, Sets E)
{
	Sets a,b,c,temp;

	a=sets_union(A, B);
	b = sets_union(C, D);
	c = sets_union(a, b);
	temp = sets_union(c, E);
	return temp;
}

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

void Sets::show_union()
{
	cout << "A Union B : \n\n\t\t { ";
	for (i = 0; i < l; i++)
	{
		
		cout << Arr[i];
		if (i <l - 1)
		{
			cout << " , ";
		}
	}
	cout << "}" << endl;

}


void Sets::execute_sets(Sets A, Sets B)
{
	cout << "Welcome To Sets Program" << endl;
	Sets R;
	while (G == 'y')
	{
		show_Menu();
		switch (h)
		{
		case 1:
		{
			R=sets_union(A, B);
			R.show_union();
		}
		break;

		case 2:
		{
			cout << "\t\tIntersection set:\n\n\t\t ";
			sets_intersection(A, B);
		}
		break;

		case 3:
		{
			sets_difference(A, B);
		}
		break;

		case 4:
		{
			cout << "\t\tCartesian product: \n\n\t\t ";
			Curtatian_products(A, B);
		}
		break;

		case 5:
		{
			power_sets(A, B);
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

Sets Sets::sets_union(Sets A, Sets B)
{
	Sets temp;
	//compute union
	l = 0;
	for (i = 0; i<A.sel; i++)
	{
		temp.Arr[i] = A.Arr[i];
		l++;
	}
	int e = l;
	for (i = 0; i<B.sel; i++)
	{
		int found = 0;
		for (int j = 0; j<e; j++)
		{
			if (B.Arr[i] == temp.Arr[j])
			{
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			temp.Arr[l] = B.Arr[i];
			l++;
		}
		temp.sel = l;
	}
	return temp;
	
}

void Sets::sets_intersection(Sets A, Sets B)
{
	//compute intersection
	for (i = 0; i<A.sel; i++)                     // loop runs from 0 to Number of elements in Set A
	{
		//for (j = 0; j<B.sel; j++)               //loop runs from 0 to Number of elements in Set B
		//{
			if (A.Arr[i] == B.Arr[i])               //if elements of Set A is Equal to that in Set B at ith location of Array 
			{
				B.Arr[j] = 0;                       //then initialize ith location with 0
				Arr[l] = A.Arr[i];                  //initilize the  element of array with resultant array with the value of ith elment of Set A's Aray
				l++;                                //increment l so that the next element could be placed at next location in array
			}
		//}
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

void Sets::sets_difference(Sets A, Sets B)
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
	cout << "A Subtraction B = { ";    //A-B
	for (i = 0; i<l; i++)
	{
		cout << Arr[i];
		if (i < l - 1)
		{
			cout << " , ";
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

	for (i = 0;i<B.sel - 1;i++)
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
	cout << "Please enter number of elements For Set " << set_count << " : ";    //Getting input for  sets element size.
	cin >> sel;                                                   //Storing size in variable.
	cout << endl;                                               //getting new line

	if (choice == 1)
	{
		cout << "Please enter Set Elements For Set " << set_count << ":  ";
		for (i = 0;i < sel;i++)                                         //loop for get input elements for  set.
		{
			cin >> Arr[i];
			if (i<sel - 1)
				cin >> dummy;
		}
	}

	else
	{
		for (i = 0;i < sel;i++)                                         //loop for get input elements for  set.
		{
			Arr[i] = (rand() % 100) + i;
		}
	}

	cout << "Elements of the Set " << set_count << " : { ";
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
	/*Sets S1, S2, S3;                   //Create three objects of sets class 
	S1.get_set_elements();           //get elements in obj s1
	S2.get_set_elements();           //get elements in obj s2
	S3.execute_sets(S1, S2);          //the result of union/intersection/differnce would be stored in Arr[] of obj 3....Reason to call exexute_sets() on obj3 and passing S1 and S2 as arguments
	*/
	Sets A, B, C, D, E,F,R;
	A.get_set_elements();
	B.get_set_elements();
	C.get_set_elements();
	D.get_set_elements();
	E.get_set_elements();
	R=F.compound_union(A, B, C, D, E);
	R.show_union();
	system("pause");
}