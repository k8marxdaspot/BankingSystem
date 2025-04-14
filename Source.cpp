#include "CheckingAccount.h"
#include "SavingAccount.h"
#include <iostream>
using namespace std;


int main()
{
	Customer customerList[20];
	CheckingAccount checkingList[20];
	SavingAccount savingList[20];
	int tracker;

	customerList[0].setAll("Bobber", "Chang", "51 stone street", "904-614-7571", "bobberChang@gmail.com");
	customerList[1].setAll("Clemente", "Smith", "91 dirt street", "904-555-5550", "ClementeIsHim@gmail.com");
	customerList[0].PrintInfo();
	customerList[1].PrintInfo();

	int userOpt;
	cout << "Welcome to Dolphin Bank!" << endl << endl;
	cout << "Please choose an option:" << endl;
	cout << "1. CREATE A CHECKING ACCOUNT" << endl;
	cout << "2. CREATE A SAVINGS ACCOUNT" << endl;
	cout << "3. VIEW ACCOUNT INFORMATION" << endl;
	cout << "4. MODIFY ACCOUNT" << endl;
	cout << "5. DELETE ACCOUNT" << endl;
	cout << "6. TRANSFER" << endl;
	cout << "7. QUIT" << endl;
	cin >> userOpt;
	cout << endl;

	while (userOpt != 7)
	{
		if (userOpt == 1)
		{
			string userFname;
			string userLname;
			string userAddress;
			string userEmail;
			string userPhone;
			double userBalance;
			double overdraftLimit;

			cout << "Please input email: ";
			cin.ignore();
			getline(cin, userEmail);
			
			cout << "Please input phone number:";
			getline(cin, userPhone);

			for (int i = 0; i < sizeof(customerList); i++)
			{
				if (customerList[i].getEmail() == userEmail || customerList[i].getPhone() == userPhone)
				{
					cout << "Customer found: " << customerList[i].getFname() << " " << customerList[i].getLname() << endl;
					cout << "Please input balance for new checking account: ";
					cin >> userBalance;
					cout << "Please input overdraft limit for new checking account: ";
					cin >> overdraftLimit;
					for (int i = 0; i < sizeof(checkingList); i++)
					{
						if (checkingList[i].getAccountCustomer() == nullptr)
						{
							checkingList[i].setAll(i, userBalance, &(customerList[i]), overdraftLimit);
						}
						else
						{
							cout << "We Are Out Of Checking Account Space!" << endl;
						}
					}
				}
				else
				{
					tracker = i;
					cout << "Please input first name: ";
					cin >> userFname;
					cout << "Please input last name: ";
					cin >> userLname;
					cout << "Please input customer's address: ";
					getline(cin, userAddress);
					cout << "Please input customer's balance: ";
					cin.ignore();
					cin >> userBalance;
					cout << "Please input overdraft limit for customer: ";
					cin >> overdraftLimit;

					for (int i = 0; i < sizeof(customerList); i++)
					{
						if ((customerList[i].getFname() == "") && (customerList[i].getAddress() == "") && (customerList[i].getLname() == "") && (customerList[i].getPhone() == "") && (customerList[i].getEmail() == ""))
						{
							customerList[tracker].setAll(userFname, userLname, userAddress, userPhone, userEmail);
							for (int i = 0; i < sizeof(checkingList); i++)
							{
								if (checkingList[tracker].getAccountCustomer() == nullptr && checkingList[tracker].getBalance() == 0 && checkingList[tracker].getOverDraftLimit() == 0)
								{
									checkingList[tracker].setAll(tracker, userBalance, &(customerList[tracker]), overdraftLimit);
								}
								else
								{
									cout << "We Are Out Of Checking Account Space!" << endl;
								}
							}
						}
						else
						{
							cout << "We Are Out Of Checking Account Storage." << endl;
						}
					}
				}
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
