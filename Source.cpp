#include<iostream>
#include<time.h>
using namespace std;


int i;           //Loop index variable.
int j;           //Loop index variable.
int l;           //Variable for result size.
char G = 'y';    //for while loop to remain true
int h;           //switch to menu
int choice;      //choice for random number or enter elements
char set_count = 'A';    //couts the set number

class Sets {
private:
	long int Arr[50];    //Array for the set.
	int  sel;     	    //set eliment size.
public:
	Sets()             //default constructor
	{
		Arr[50] = 0;
		sel = 0;
	}

	//Function Declarations

	void show_Menu();
	void execute_sets(Sets, Sets, Sets, Sets, Sets, Sets);
	Sets sets_union(Sets, Sets);
	Sets compound_union(Sets, Sets, Sets, Sets, Sets);              
	Sets sets_intersection(Sets, Sets);
	Sets compound_intersection(Sets A, Sets B, Sets C);             //For 3 Arguments
	Sets compound_intersection(Sets, Sets, Sets, Sets, Sets);       //For 3 Arguments
	Sets sets_difference(Sets, Sets);
	void get_set_elements();
	void show_set_elements();
	void Universal();
	void Sort();
	void show();
};




void main()              //main function
{
	system("COLOR 3F");
	cout << "--------------------------Welcome To Sets Program--------------------------" << endl;
	cout << "\nYou May Have To Enter Elements For 5 Sets A,B,C,D,E in order to proceed\n";
	cout << "\nPlease Select the Input Method\n\n1. Enter Elements Yourself\n2. Use Random Numbers." << endl;
	cin >> choice;
	cout << "---------------------------------------------------------------------------" << endl;
	Sets S1, S2, S3, S4, S5, S6, S7;         //creating 7 objects of Sets Class
	S1.get_set_elements();                   //getting elements on S1,S2,S3,S4,S5
	S2.get_set_elements();
	S3.get_set_elements();
	S4.get_set_elements();
	S5.get_set_elements();
	cout << "---------------------------------------------------------------------------" << endl;
	S6.Universal();
	system("cls");
	cout << "--------------------------Welcome To Sets Program--------------------------" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "\n\t\tFollowing Are The Sets Used For Operations:\n\n";
	cout << "---------------------------------------------------------------------------" << endl;
	S1.show_set_elements();
	cout << "---------------------------------------------------------------------------" << endl;
	S2.show_set_elements();
	cout << "---------------------------------------------------------------------------" << endl;
	S3.show_set_elements();
	cout << "---------------------------------------------------------------------------" << endl;
	S4.show_set_elements();
	cout << "---------------------------------------------------------------------------" << endl;
	S5.show_set_elements();
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "\t\t\t";
	system("pause");
	cout << "---------------------------------------------------------------------------" << endl;
	system("cls");
	cout << "--------------------------Welcome To Sets Program--------------------------" << endl;
	S7.execute_sets(S1, S2, S3, S4, S5, S6);      //passing S1,S2,S3,S4,S5,S6  as arguments to Func Execute_Sets ....Further Process is implementation is done there
	cout << "\t\t\t";
	system("pause");
	cout << "---------------------------------------------------------------------------" << endl;
}






//Function Definitions


void Sets::show_Menu()          //shows menu
{
	cout << "---------------------------------\nImplementation Of Question 1:\n---------------------------------\n\n";
	cout << "1.\tA U B\n";
	cout << "2.\tA N B\n";
	cout << "3.\tA - B\n";
	cout << "4.\tB - A\n";
	cout << "5.\tA'\n";
	cout << "6.\tB'\n";
	cout << "\n---------------------------------\nImplementation Of Question 2:\n---------------------------------\n\n";
	cout << "7.\tA1 U A2 N A3\n";
	cout << "8.\tA1 N A2 U A3\n";
	cout << "9.\tA1 U A2 U A3 U A4 U A5\n";
	cout << "10.\tA1 N A2 N A3 N A4 N A5\n";
	cout << "\n---------------------------------\nImplementation Of Question 3:\n---------------------------------\n\n";
	cout << "11.\tA U (B N C)\n";
	cout << "12.\t(A U B ) N C\n";
	cout << "13.\tA N (B U C)\n";
	cout << "14.\t(A N B ) U C\n";
	cout << "15.\tA N (B N C)\n";
	cout << "16.\t(A U (B U C)\n";
	cout << "\n\nSelect Your Choice: ";
	cin >> h;
	system("CLS");
}



void Sets::execute_sets(Sets A, Sets B, Sets C, Sets D, Sets E, Sets U)             //The Actual Implementation Of The Program Starts Here
{
	Sets R, R2;
	while (G == 'y')
	{
		show_Menu();
		switch (h)
		{
		case 1:
		{
			R = sets_union(A, B);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "A U B :\t";
			R.Sort();
			R.show();;
			cout << "---------------------------------------------------------------------------" << endl;
		}
		break;

		case 2:
		{
			R = sets_intersection(A, B);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "A N B :\t";
			R.Sort();
			R.show();;
			cout << "---------------------------------------------------------------------------" << endl;
		}
		break;

		case 3:
		{
			R = sets_difference(A, B);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "A - B :\t";
			R.Sort();
			R.show();;
			cout << "---------------------------------------------------------------------------" << endl;
		}
		break;

		case 4:
		{
			R = sets_difference(B, A);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "B - A :\t";
			R.Sort();
			R.show();;
			cout << "---------------------------------------------------------------------------" << endl;
		}
		break;

		case 5:
		{
			R = sets_difference(U, A);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "A' :\t";
			R.Sort();
			R.show();
			cout << "---------------------------------------------------------------------------" << endl;
		}
		break;

		case 6:
		{
			R = sets_difference(U, B);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "B' :\t";
			R.Sort();
			R.show();
			cout << "---------------------------------------------------------------------------" << endl;
		}

		break;

		case 7:
		{
			R = sets_union(A, B);
			R2 = sets_intersection(R, C);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "A1 U A2 N A3 :\t";
			R2.Sort();
			R2.show();
			cout << "---------------------------------------------------------------------------" << endl;
		}
		break;

		case 8:
		{
			R = sets_intersection(A, B);
			R2 = sets_union(R, C);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "A1 N A2 U A3 :\t";
			R2.Sort();
			R2.show();
			cout << "---------------------------------------------------------------------------" << endl;
		}
		break;

		case 9:
		{
			R = compound_union(A, B, C, D, E);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "A1 U A2 U A3 U A4 U A5 :\t";
			R.Sort();
			R.show();
			cout << "---------------------------------------------------------------------------" << endl;

		}
		break;

		case 10:
		{
			R = compound_intersection(A, B, C, D, E);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "A1 N A2 N A3 N A4 N A5 :\t";
			R.Sort();
			R.show();
			cout << "---------------------------------------------------------------------------" << endl;
		}
		break;

		case 11:
		{
			R = sets_intersection(B, C);
			R2 = sets_union(A, R);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "A U (B N C): \n";
			R2.Sort();
			R2.show();
			cout << "---------------------------------------------------------------------------" << endl;
		}
		break;
		case 12:
		{
			R = sets_union(A, B);
			R2 = sets_intersection(R, C);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "(A U B ) N C: \n";
			R2.Sort();
			R2.show();
			cout << "---------------------------------------------------------------------------" << endl;
		}
		break;
		case 13:
		{
			R = sets_union(B, C);
			R2 = sets_intersection(A, R);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "A N (B U C): \n";
			R2.Sort();
			R2.show();
			cout << "---------------------------------------------------------------------------" << endl;
		}
		break;
		case 14:
		{
			R = sets_intersection(A, B);
			R2 = sets_union(R, C);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "(A N B ) U C: \n";
			R2.Sort();
			R2.show();
			cout << "---------------------------------------------------------------------------" << endl;
		}
		break;
		case 15:
		{
			R = compound_intersection(A, B, C);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "A N (B N C): \n";
			R2.Sort();
			R2.show();
			cout << "---------------------------------------------------------------------------" << endl;
		}
		break;
		case 16:
		{
			R = sets_union(B, C);
			R2 = sets_union(A, R);
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "A U (B U C): \n";
			R2.Sort();
			R2.show();
			cout << "---------------------------------------------------------------------------" << endl;
		}
		break;


		default:
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "You entered wrong key\n";
			cout << "---------------------------------------------------------------------------" << endl;
			break;
		}
		cout << "\n\n";
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Please enter 'y' for check again or 'n' for stop: " << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		cin >> G;
		cout << "---------------------------------------------------------------------------" << endl;
	}

}



Sets Sets::sets_union(Sets A, Sets B)                  //compute Union
{
	l = 0;
	Sets temp;
	//compute union
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





Sets Sets::compound_union(Sets A, Sets B, Sets C, Sets D, Sets E)           //function to compute compound union
{
	Sets a, b, c, temp;
	a = sets_union(A, B);
	b = sets_union(C, D);
	c = sets_union(a, b);
	temp = sets_union(c, E);
	return temp;
}


Sets Sets::sets_intersection(Sets A, Sets B)          //compute Intersection
{
	l = 0;
	Sets obj;
	for (i = 0; i<A.sel; i++)
	{
		for (j = 0; j<B.sel; j++)
		{
			if (A.Arr[i] == B.Arr[j])
			{
				B.Arr[j] = 0;
				obj.Arr[l] = A.Arr[i];
				l++;
			}
		}
	}
	return obj;
}




Sets Sets::compound_intersection(Sets A, Sets B, Sets C)      //function to computecompound  intersection with three Arguments
{
	l = 0;
	Sets temp;
	for (i = 0; i<A.sel; i++)                     
	{
		for (j = 0; j < B.sel; j++)             
		{
			for (int k = 0; k < C.sel; k++)
			{
				if (A.Arr[i] == B.Arr[j] && B.Arr[j] == C.Arr[k])               
				{
					B.Arr[j] = 0;                       
					temp.Arr[l] = A.Arr[i];                 
					l++;                              
				}

			}
		}

	}
	return temp;
}



Sets Sets::compound_intersection(Sets A, Sets B, Sets C, Sets D, Sets E)      //function to compute compound  intersection with three Arguments
{
	l = 0;
	Sets temp;

	for (i = 0; i<A.sel; i++)
	{
		for (j = 0; j < B.sel; j++)
		{
			for (int k = 0; k < C.sel; k++)
			{
				for (int x = 0; x < D.sel; x++)
				{
					for (int p = 0; p < E.sel; p++)
					{
						if (A.Arr[i] == B.Arr[j] && B.Arr[j] == C.Arr[k] && C.Arr[k] == D.Arr[x] && D.Arr[x] == E.Arr[p])
						{
							B.Arr[j] = 0;
							temp.Arr[l] = A.Arr[i];
							l++;
						}
					}
				}
			}
		}

	}
	return temp;
}



Sets Sets::sets_difference(Sets A, Sets B)          //compute difference
{
	l = 0;
	Sets temp;
	for (i = 0; i < A.sel; i++)
	{
		int found = 0;
		for (j = 0; j < B.sel; j++)
		{

			if (A.Arr[i] == B.Arr[j])
			{
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			temp.Arr[l] = A.Arr[i];
			l++;
		}
	}
	for (i = 0; i < B.sel; i++)
	{
		int found = 0;
		for (j = 0; j < A.sel; j++)
		{
			if (B.Arr[i] == A.Arr[j])
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
	}
	return temp;
}



void Sets::get_set_elements()                                                                //function to get Elements
{
	char dummy; 
	srand(time(NULL));                                                                     //  using the time seed from srand explanation
	cout << "Please enter number of elements For Set " << set_count << " : ";              //Getting input for  sets element size.
	cin >> sel;                                                                            //Storing size in variable.


	if (choice == 1)
	{
		cout << "Please enter Set Elements For Set " << set_count << ":  ";
		for (i = 0;i < sel;i++)                                        
		{
			cin >> Arr[i];
			if (i<sel - 1)
				cin >> dummy;

		}
		cout << endl;                                               
	}

	else
	{
		for (i = 0;i < sel;i++)                                        
		{
			Arr[i] = (rand() % 10) + i;
		}
	}
	++set_count;
}

void Sets::show_set_elements()         //function to show wlwmwnts
{
	cout << "Elements of the Set " << set_count << " : { ";
	for (i = 0;i<sel;i++) 	                                 \
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




void Sets::Universal()    //universal Array
{

	for (i = 0;i < 21;i++)
	{
		Arr[i] = i;
	}
	sel = 20;
}




void  Sets::Sort()                                //function for sorting the array
{
	int swap;
	for (i = 0; i < (sel - 1); i++)
	{
		for (j = 0; j < sel - i - 1; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				swap = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = swap;
			}
		}
	}
}



void Sets::show()           //show function
{
	cout << "{ ";
	for (i = 0; i < l; i++)
	{

		cout << Arr[i];
		if (i <l - 1)
		{
			cout << " , ";
		}
	}
	cout << " }" << endl;
}
