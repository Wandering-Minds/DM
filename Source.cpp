#include<iostream>
#include<Windows.h>

using namespace std;

class Converter {
protected:
	int arr[20];
	int num;
	char brr[20];
};

class binary : public Converter {
public:
	void BinarytoDecimal();
	void DecimaltoBinary();
};

class octal : public Converter {
public:
	void OctaltoDecimal();
	void DecimaltoOctal();
};

class hexadecimal : public Converter {
public:
	void HexaDecimalToDecimal();
	void DecimalToHexaDecimal();
};

class Menu {
public:
	void showMenu();
};


void Menu::showMenu()
{
int ch; 
cout << "\n\nPlease Select From Following\n\n1.\tDecimal To Binary Conversion\n2.\tBinary To Decimal Conversion"
<< "\n3.\tDecimal To Octal Conversion\n4.\tOctal To Decimal Conversion\n5.\tHexaDecimal To Decimal Conversion" 
<<"\n6.\tDecimal To HexaDecimal Conversion"<< endl;
cout << "\nWhich operation do you want to perform: ";
cin >> ch;
system("cls");
 switch (ch)
  {

	case 1:
	{
		binary bn;
		cout << "\n\t******Decimal To Binary******" << endl;

		bn.DecimaltoBinary();

		cout << "\n\n";
		system("pause");
		system("cls");
	}
	break;

	case 2:
	{
		binary bn;
		cout << "\n\t******Binary To Decimal******" << endl;

		bn.BinarytoDecimal();

		cout << "\n\n";
		system("pause");
		system("cls");
	}
	break;

	case 3:
	{
		octal oc;
		cout << "\n\t******Decimal To Octal******" << endl;

		oc.DecimaltoOctal();

		cout << "\n\n";
		system("pause");
		system("cls");
	}
	break;

	case 4:
	{
		octal oc;
		cout << "\n\t******Octal To Decimal******" << endl;

		oc.OctaltoDecimal();

		cout << "\n\n";
		system("pause");
		system("cls");
	}
	break;

	case 5:
	{
		hexadecimal hx;
		cout << "\n\t******HexaDecimal To Decimal******" << endl;

		hx.HexaDecimalToDecimal();

		cout << "\n\n";
		system("pause");
		system("cls");
	}
	break;
    
	case 6:
	{
		hexadecimal hx;
		cout << "\n\t******Decimal To HexaDecimal******" << endl;

		hx.DecimalToHexaDecimal();

		cout << "\n\n";
		system("pause");
		system("cls");
	}
	break;


	default:
		cout << "Invalid Choice!!!";
  }
}

void hexadecimal::DecimalToHexaDecimal()
{
	cout << "Please Enter A Decimal Number i.e. (43456): " << endl;
	cin >> num;

	int i = 0, count = 0;

	do
	{
		arr[i] = num % 16;
		num = num / 16;
		count++;
		i++;
	} while (num > 0);


	cout << "Converted Number in HexaDecimal / Base 16: (";

	for (int i = count - 1;i >= 0;i--)
	{
		switch (arr[i])
		{
		case 0:
			brr[i] = '0';
			break;

		case 1:
			brr[i] = '1';
			break;

		case 2:
			brr[i] = '2';
			break;

		case 3:
			brr[i] = '3';
			break;

		case 4:
			brr[i] = '4';
			break;

		case 5:
			brr[i] = '5';
			break;

		case 6:
			brr[i] = '6';
			break;

		case 7:
			brr[i] = '7';
			break;

		case 8:
			brr[i] = '8';
			break;

		case 9:
			brr[i] = '9';
			break;

		case 10:
			brr[i] = 'A';
			break;

		case 11:
			brr[i] = 'B';
			break;

		case 12:
			brr[i] = 'C';
			break;

		case 13:
			brr[i] = 'D';
			break;

		case 14:
			brr[i] = 'E';
			break;

		case 15:
			brr[i] = 'F';
			break;

		default:
			cout << "Invalid Choice!!!" << endl;
		}

		cout << brr[i];
	}
	cout << ")16\n";
}

void hexadecimal::HexaDecimalToDecimal()
{

	cout << "Please Enter A HexaDecimal Number 5- digits only i.e. (2A5C8): " << endl;
	for (int i = 4;i >= 0;i--)
	{
		cin >> brr[i];
	}

	int sum = 0;
	for (int i = 4;i >= 0;i--)
	{
		switch (brr[i])
		{
		case '0':
			arr[i] = 0;
			break;
		case '1':
			arr[i] = 1;
			break;
		case '2':
			arr[i] = 2;
			break;
		case '3':
			arr[i] = 3;
			break;
		case '4':
			arr[i] = 4;
			break;
		case '5':
			arr[i] = 5;
			break;
		case '6':
			arr[i] = 6;
			break;
		case '7':
			arr[i] = 7;
			break;
		case '8':
			arr[i] = 8;
			break;
		case '9':
			arr[i] = 9;
			break;

		case 'A':
		case 'a':
			arr[i] = 10;
			break;

		case 'B':
		case 'b':
			arr[i] = 11;
			break;

		case 'C':
		case 'c':
			arr[i] = 12;
			break;

		case 'D':
		case 'd':
			arr[i] = 13;
			break;

		case 'E':
		case 'e':
			arr[i] = 14;
			break;

		case 'F':
		case 'f':
			arr[i] = 15;
			break;

		default:
			cout << "Invalid Choice!!!" << endl;
		}

		arr[i] = arr[i] * pow(16, i);
	}

	cout << "The Converted Number in Decimal / Base 10 is : " << endl;
	for (int i = 4;i >= 0;i--)
	{
		sum += arr[i];
		cout << arr[i];
		if (i>0)
			cout << "+";
	}
	cout << "\n= (" << sum << ")10" << endl;

}


void octal::OctaltoDecimal()
{
	cout << "Please Enter An Octal Number 5- digits only i.e. (4 5 6 2 3 ): " << endl;
	for (int i = 4;i >= 0;i--)
	{
		cin >> arr[i];
	}

	int sum = 0;
	for (int i = 4;i >= 0;i--)
	{
		arr[i] = arr[i] * pow(8, i);
	}

	cout << "The Converted Number in Decimal / Base 10 is : " << endl;
	for (int i = 4;i >= 0;i--)
	{
		sum += arr[i];
		cout << arr[i];
		if (i>0)
			cout << "+";
	}
	cout << "\n= (" << sum << " )10" << endl;

}

void octal::DecimaltoOctal()
{
	cout << "Please Enter A Decimal Number i.e. (234): " << endl;
	cin >> num;

	int i = 0, count = 0;

	do
	{
		arr[i] = num % 8;
		num = num / 8;
		count++;
		i++;
	} while (num > 0);


	cout << "Converted Number in Octal / Base 8: (";
	for (int i = count - 1;i >= 0;i--)
	{
		cout << arr[i];
	}
	cout << ")8\n";


}

void binary::DecimaltoBinary()
{

	cout << "Please Enter A Decimal Number i.e. (234): " << endl;
	cin >> num;

	int i = 0, count = 0;

	do
	{
		arr[i] = num % 2;
		num = num / 2;
		count++;
		i++;
	} while (num > 0);


	cout << "Converted Number in Binary / Base 2: (";
	for (int i = count - 1;i >= 0;i--)
	{
		cout << arr[i];
	}
	cout << ")2\n";
}




void binary::BinarytoDecimal()
{
	cout << "Please Enter A Binary Number 5- digits only i.e. (1 1 0 1 0 ): " << endl;
	for (int i = 4;i >= 0;i--)
	{
		cin >> arr[i];
	}

	int sum = 0;
	for (int i = 4;i >= 0;i--)
	{
		arr[i] = arr[i] * pow(2, i);
	}

	cout << "The Converted Number in Decimal / Base 10 is : " << endl;
	for (int i = 4;i >= 0;i--)
	{
		sum += arr[i];
		cout << arr[i];
		if (i>0)
			cout << "+";
	}
	cout << "\n= (" << sum << " )10" << endl;
}



void main()
{
	system("color 3F");
	cout << "\n\n\nWelcome To Number System Converter (OOP Project)" << endl;
	cout << "\n\nMade By Hussain Khan\n\n" << endl;
	Menu m;
	m.showMenu();
	cout << "\n\n\n\n\n\n\n\n\n\t\t\tThanks For Using Converter..... ";
	Sleep(5000);
}