#include <iostream>
#include <string>
#include <ctime>
using namespace std;

char ans='y'; // for control structures
int choice=0; // to choose what action to perform from main menu
int a,b,i,j,k=0;

class Sets                                        
{
private:

string A[50], B[50],Result[50];	// declaring arrays	for two sets and the result of operation

public:

void show_menu(); // for user to select operation to perform
void choice_generator(); //to choose random values or user inputted values
void exec_func(); // to perform specific task
void Union(); //to perform union
void intersection(); //to perform intersection
void subtraction(); // to subtract one set from another
void complement(); //to calculate complement of set

};

void Sets::show_menu()
{
	cout << "Enter 1 for (A U B) \n";
	cout << "Enter 2 for (A ∩ B)t \n";
	cout << "Enter 3 for (A - B) \n";
	cout << "Enter 4 for (A)' \n";
	cout << "Select Your Choice: ";
	cin >> choice;

}

void Sets::choice_generator()
{
	cout<<"\nHow would you Like to Input Values for Sets?"
		<<"\nPlease choose an option from the ones below:"
		<<"\n1. User Input"
		<<"\n2. Randomly Generated";
	cin>>choice;

	switch (choice)
		{
	case 1:
		{
			
	    cout << "\nPlease enter number of the elements for your first set A: ";   //Getting input for first sets element size.
        cin >> a;                                                        //Storing size in variable.
     
        cout << "\nPlease enter number of  fhe elements for your second set B: ";  //Getting input for second sets element size.
        cin >> b;                                                        //Storing size in variable.
        cout << endl;                                                    //getting new line
       for (i = 0; i < a; i++)                                          //loop for get input elements for first set.
            {
             cout << "\nPlease enter element no " << i + 1 << " of your first set: ";
             cin >> A[i];
            }
           cout << "\nElements of your first set = { ";
        for (i = 0; i < a; i++)                                           //loop to print input elements for first set.
           {
              cout << A[i];

        if (i < a - 1)
          {
          cout << " , ";
             }

		 cout << " }\n\n";

         for (i = 0; i < b; i++)                                        //loop to input second set elements.
           {
             cout << "\nPlease enter element no " << i + 1 << " of your second set: ";
              cin >> B[i];
           }
         cout << "'\nElements of your second set = { ";    // Loop to print elements of the second set
          
		 for (i = 0; i < b; i++)
          {
            cout << B[i];

          if (i < b - 1)
             { 
              cout<< " , ";
             }
           }

         cout << " }\n\n";
	
         break;
		}
		
	case 2:
		{
		   srand(time(0)); 

		cout << "\nPlease enter number of the elements for your first set A: ";   //Getting input for first sets element size.
        cin >> a;                                                                 //Storing size in variable.
		cout<<endl;                                                              //getting new line
     
                                                         
       for (i = 0; i < a; i++)                                          //loop for get input elements for first set.
            {
				A[i] = (rand()%100);
		   }
	    cout << "\nElements of your first set = { ";
        for (i = 0; i < a; i++)                                           //loop to print input elements for first set.
           {
              cout << A[i];

        if (i < a - 1)
          {
          cout << " , ";
             }

		 cout << " }\n\n";

		cout << "\nPlease enter number of  fhe elements for your second set B: ";  //Getting input for second sets element size.
        cin >> b;                                                                  //Storing size in variable.
        cout << endl;   
		
		for (i = 0; i < b; i++)                                          //loop for get input elements for first set.
            {
            
             B[i]=(rand()%100);
            }
           cout << "\nElements of your first set = { ";
        for (i = 0; i < b; i++)                                           //loop to print input elements for first set.
           {
              cout << B[i];

        if (i < b - 1)
          {
          cout << " , ";
             }

		 cout << " }\n\n";
		    }
		    break;
		
		    }


            }
	    }
	}
		system("CLS");
}
void Sets::exec_func()
{
	
	cout << "\t\tMain Menu" << endl;
	

	choice_generator();

	choice=0;

	
	
	while (ans == 'y')
	{
		show_menu();
		switch (choice)
		{
		case 1:
		{
			cout << "\n\t\tUnion of sets:\n\n\t\t";
			Union();
		
		break;
		}

		case 2:
		{
			cout << "\n\t\tIntersection of sets:\n\n\t\t ";
			intersection();
		
		break;
		}

		case 3:
		{
			cout << "\n\t\tSubtraction of sets:\n\n\t\t ";
			subtraction();
		
		break;
		}
		

		case 4:
		{
			cout << "\n\t\tComplement of set:\n\n\t\t ";
			complement();
			cout<<"\n Including all remaining elements of Universal Set\n";
		
		break;
		}
        
     
		default:
			{
			cout << "You entered wrong key\n";
			
			break;
			}
		
		}
		cout << "\n\n\n\n\n";
		cout << "Please enter 'y' to perform another action or 'n' to exit: ";
		cin >> ans;
    }

	system("CLS");
    }



void Sets::Union()
{
      for (i = 0; i < a; i++)  //compute union
           {
            Result[i] = A[i];
            k++;              // k is incremented so that once one set ends the result array takes in values of other set from next element
           }
     int temp = k;   // to make sure value stays constant as K gets incremented each time
    
	    for (i = 0; i < b; i++)
           {
              int found = 0;
          
     		   for (int j = 0; j < temp; j++)
                 {
                     if (B[i] == Result[j])     //if elements of both arrays are same it skips that element
                         {
                           found = 1;
                            break;
                          }
					 if (found == 0)            // if elements of both arrays are different it adds it to result array
                 {
                   Result[k] = B[i];
                   k++;
                  }
           cout << "A Union B : \n\n\t\t { ";
           for (i = 0; i < k; i++)
               {
                  cout << Result[i] << " ";
                }
           cout << "}" << endl;
	    }
  		k=0;
		Result[50]="NULL";
    }
}


void Sets::intersection()
{
        for (i = 0; i < a; i++)
             {
               for (j = 0; j < b; j++)
                   {
                     if (A[i] == B[j])
                         {
                            B[j] = "0";
                             Result[k] = A[i];
                             k++;
                         }
                   }
               } 
	
		cout << "A ∩ B = { ";
         
		 for (i = 0; i < k; i++)
                {
                  cout << Result[i] << " ";
                }
                 cout << "}" << endl;
                 k = 0;
                 Result[i] = "NULL" ;
}


void Sets::subtraction()
	{
	
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
                    Result[k] = A[i];
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
                             Result[k] = B[i];
         					 k++;
                         }
          }
                cout << "A Subtraction B = { ";
                for (i = 0; i < k; i++)
                        {
                           cout << Result[i] << "," << " ";
                          }
                cout << "}" << endl;

}

void main()
{
	Sets A1, A2, A3, A4;


system("pause");

}