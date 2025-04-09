#include "Customer.h"
#include "Account.h"
#include <iostream>
using namespace std;

int main()
{
	Customer customerlist[20];
	CheckingAccount checkingList[20];
	SavingAccount savinglist[20];
	int tracker;

	customerlist[0].setAll("Bobber", "Chang", "51 stone street", "904-614-7571", "bobberChang@gmail.com");
	customerlist[1].setAll("Clemente", "Smith", "91 dirt street", "904-555-5550", "ClementeIsHim@gmail.com");
	customerlist[0].PrintInfo();
	customerlist[1].PrintInfo();



	int userOpt;
	cout << "Welcome to Dolphin Bank!" << endl << endl;
	cout << "Please choose an option:" << endl;
	cout << "1. CREATE A CHECKING ACCOUNT" << endl;
	cout << "2. CREATE A SAVINGS ACCOUNT" << endl;
	cout << "3. VIEW MY ACCOUNT INFORMATION" << endl;
	cout << "4. MODIFY MY ACCOUNT" << endl;
	cout << "5. DELETE MY ACCOUNT" << endl;
	cout << "6. TRANSFER" << endl;
	cout << "7. QUIT" << endl;
	cin >> userOpt;
	cout << endl;
	while (userOpt != 7)
	{
		if (userOpt == 1)
		{
			for (int i = 0; i < sizeof(customerlist); i++)
			{
				cout << "An Account Has Already Been Created Using This Email And Phone Number";
			}
			for (int i = 0; i < sizeof(customerlist); i++)
			{
				if ((customerlist[i].getFname() == "") && (customerlist[i].getAddress() == "") && (customerlist[i].getLname() == "") && (customerlist[i].getPhone() == "") && (customerlist[i].getEmail() == ""))
				{
				tracker = i;
				}
				else cout << "Sorry we are out of account storage" << endl;
			}
			
		}
		else if (userOpt == 2)
		{
	
		}
		else if (userOpt == 3)
		{
	
		}
		else if (userOpt == 4)
		{
	
		}
		else if (userOpt == 5)
		{
	
		}
		else if (userOpt == 6)
		{
	
		}
		else
		{
			cout << "Error invalid option entered!" << endl;
			cout << "Please make sure to enter an option from 1 to 7!" << endl;
		}
	
		cout << "Welcome to Dolphin Bank!" << endl << endl;
		cout << "Please choose an option:" << endl;
		cout << "1. CREATE A CHECKING ACCOUNT" << endl;
		cout << "2. CREATE A SAVINGS ACCOUNT" << endl;
		cout << "3. VIEW MY ACCOUNT INFORMATION" << endl;
		cout << "4. MODIFY MY ACCOUNT" << endl;
		cout << "5. DELETE MY ACCOUNT" << endl;
		cout << "6. TRANSFER" << endl;
		cout << "7. QUIT" << endl;
		cin >> userOpt;
		cout << endl;
	}



		//MAKE SURE TO DO GET LINE FOR ADDRESS AND CIN>IGNORE AFTER

}
