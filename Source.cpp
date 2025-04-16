#include "CheckingAccount.h"
#include "SavingAccount.h"
#include <iostream>
using namespace std;


int main()
{
	Customer customerList[20];
	CheckingAccount checkingList[20];
	SavingAccount savingList[20];
	int customerTracker = -1;
	int checkingTracker = -1;
	int savingTracker = -1;

	customerList[0].setAll("Bobber", "Chang", "51 stone street", "904-614-7571", "bobberChang@gmail.com");
	customerList[1].setAll("Clemente", "Smith", "91 dirt street", "904-555-5550", "ClementeIsHim@gmail.com");
	customerTracker++;
	customerTracker++;
	customerList[0].PrintInfo();
	customerList[1].PrintInfo();
	checkingList[0].setAll(0, 10000, &customerList[0], 100);
	checkingList[0].PrintInfo();

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
	cin.clear();
	cout << endl;

	while (userOpt != 7)
	{
		if (userOpt == 1)
		{
			string custFname;
			string custLname;
			string userAddress;
			string custEmail;
			string custPhone;
			double custBalance;
			double custOverdraftLimit;
			Customer* cPtr = nullptr;
			bool existingCustomer = false;
			checkingTracker++;

			if (checkingTracker < 20) // might give us issues later if somehow checkingTracker isn't over 20 but all slots are filled thus causing us to overwrite someone's checking account
			{
				cout << "Please input email: ";
				cin.ignore();
				getline(cin, custEmail);

				cout << "Please input phone number:";
				getline(cin, custPhone);

				for (int i = 0; i < sizeof(customerTracker); i++) // search for existing customer with matching phone number or email
				{
					if (customerList[i].getEmail() == custEmail || customerList[i].getPhone() == custPhone) // found existing customer 
					{
						cout << "Customer found: " << customerList[i].getFname() << " " << customerList[i].getLname() << endl;
						cout << "Please input balance for new checking account: ";
						cin >> custBalance;
						cout << "Please input overdraft limit for new checking account: ";
						cin >> custOverdraftLimit;
						Customer* cPtr = customerList + i;
						checkingList[checkingTracker].setAll(i, custBalance, cPtr, custOverdraftLimit);
						existingCustomer = true;
					}
				}

				if (existingCustomer == false) // did not find existing customer account and thus must create customer and checking account
				{
					customerTracker++;
					if (customerTracker < 20 && (customerList[customerTracker].getFname() == "" && customerList[customerTracker].getLname() == "" &&
						customerList[customerTracker].getAddress() == "" && customerList[customerTracker].getPhone() == "" &&
						customerList[customerTracker].getEmail() == "")) // makes sure that customerList array has room for another customer and that the customer in the array that the tracker is on is empty!
					{
						cout << "Please input first name: ";
						cin >> custFname;
						cout << "Please input last name: ";
						cin >> custLname;
						cout << "Please input customer's address: ";
						cin.ignore();
						getline(cin, userAddress);
						customerList[customerTracker].setAll(custFname, custLname, userAddress, custPhone, custEmail);

						cout << "Please input customer's balance: ";
						cin.ignore();
						cin >> custBalance;
						cout << "Please input overdraft limit for customer: ";
						cin >> custOverdraftLimit;
						Customer* cPtr = customerList + customerTracker;
						checkingList[checkingTracker].setAll(checkingTracker, custBalance, cPtr, custOverdraftLimit);
					}
					else // either no room for customer or elment in customer list has preexisting information occupying it
					{
						cout << "Out of Room For More Customers!" << endl;
						break;
					}
				}
				
			}
			else
			{
				cout << "Sorry We Are Out of Checking Account Space!" << endl;
				break;
			}
		}
		else if (userOpt == 2)
		{
			string custFname;
			string custLname;
			string userAddress;
			string custEmail;
			string custPhone;
			double custBalance;
			double custInterestRate;
			Customer* cPtr = nullptr;
			bool existingCustomer = false;
			savingTracker++;

			if (savingTracker < 20) // might give us issues later if somehow savingTracker isn't over 20 but all slots are filled thus causing us to overwrite someone's savings account
			{
				cout << "Please input email: ";
				cin.ignore();
				getline(cin, custEmail);

				cout << "Please input phone number:";
				getline(cin, custPhone);

				for (int i = 0; i < sizeof(customerTracker); i++) // search for existing customer with matching phone number or email
				{
					if (customerList[i].getEmail() == custEmail || customerList[i].getPhone() == custPhone) // found existing customer 
					{
						cout << "Customer found: " << customerList[i].getFname() << " " << customerList[i].getLname() << endl;
						cout << "Please input balance for new savings account: ";
						cin >> custBalance;
						cout << "Please input interest rate for new savings account: ";
						cin >> custInterestRate;
						Customer* cPtr = customerList + i;
						savingList[checkingTracker].setAll(cPtr, i, custBalance, custInterestRate);
						existingCustomer = true;
					}
				}

				if (existingCustomer == false) // did not find existing customer account and thus must create customer and saving account
				{
					customerTracker++;
					if (customerTracker < 20 && (customerList[customerTracker].getFname() == "" && customerList[customerTracker].getLname() == "" &&
						customerList[customerTracker].getAddress() == "" && customerList[customerTracker].getPhone() == "" &&
						customerList[customerTracker].getEmail() == "")) // makes sure that customerList array has room for another customer and that the customer in the array that the tracker is on is empty!
					{
						cout << "Please input first name: ";
						cin >> custFname;
						cout << "Please input last name: ";
						cin >> custLname;
						cout << "Please input customer's address: ";
						cin.ignore();
						getline(cin, userAddress);
						customerList[customerTracker].setAll(custFname, custLname, userAddress, custPhone, custEmail);

						cout << "Please input customer's balance: ";
						cin.ignore();
						cin >> custBalance;
						cout << "Please input interest rate for customer: ";
						cin >> custInterestRate;
						Customer* cPtr = customerList + customerTracker;
						savingList[checkingTracker].setAll(cPtr, checkingTracker, custBalance, custInterestRate);
					}
					else // either no room for customer or element in customer list has preexisting information occupying it
					{
						cout << "Out of Room For More Customers!" << endl;
						break;
					}
				}
			}
			else
			{
				cout << "Sorry We Are Out of Saving Account Space!" << endl;
				break;
			}
		}
		else if (userOpt == 3)
		{
			int tempUserOpt;
			cout << "Select an Option" << endl;
			cout << "1. Print Individual Account Information" << endl;
			cout << "2. Print All Account Information" << endl;
			cin >> tempUserOpt;
			if (tempUserOpt != 1 && tempUserOpt != 2)
			{
				cout << "Error invalid Option Entered!" << endl;
			}
			else
				if (tempUserOpt == 1)
				{
					string custEmail;
					string custPhone;

					cout << "Please input email: ";
					getline(cin, custEmail);
					cout << "Please input phone number:";
					cin.ignore();
					getline(cin, custPhone);
					for (int i = 0; i < sizeof(customerTracker); i++) // search for existing customer with matching phone number or email
					{
						if (customerList[i].getEmail() == custEmail || customerList[i].getPhone() == custPhone) // found existing customer 
						{
							customerList[i].PrintInfo();
							for (int j = 0; j < sizeof(checkingTracker); i++)
							{
								if (&customerList[i] == checkingList[j].returnAddress())
								{
									checkingList[j].PrintInfo();
									break;
								}
								
							}
							for (int j = 0; j < sizeof(savingTracker); i++)
							{
								if (&customerList[i] == savingList[j].returnAddress())
								{
									savingList[j].PrintInfo();
									break;
								}
							}
						}
					}

					

				}
		}
		else if (userOpt == 4)
		{
			string custEmail;
			string custPhone;
			int modifyOption;
			bool existingCustomer = false;
			
			cout << "Please input customer email: ";
			cin.ignore();
			getline(cin, custEmail);

			cout << "Please input customer phone number:";
			getline(cin, custPhone);

			for (int i = 0; i < sizeof(customerTracker); i++) // search for existing customer with matching phone number or email
			{
				if (customerList[i].getEmail() == custEmail || customerList[i].getPhone() == custPhone) // found existing customer 
				{
					cout << "Customer found: " << customerList[i].getFname() << " " << customerList[i].getLname() << endl;
					
					existingCustomer = true;
				}
			}

			if (existingCustomer = false)
			{
				cout << "No Exisiting Customer with that Email or Phone Number!";
			}
		}
		else if (userOpt == 5)
		{
			checkingList[0].PrintInfo();
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
		cout << "3. VIEW ACCOUNT INFORMATION" << endl;
		cout << "4. MODIFY ACCOUNT" << endl;
		cout << "5. DELETE ACCOUNT" << endl;
		cout << "6. TRANSFER" << endl;
		cout << "7. QUIT" << endl;
		cin.ignore();
		cin >> userOpt;
		cin.clear();
		cout << endl;
	}



		//MAKE SURE TO DO GET LINE FOR ADDRESS AND CIN>IGNORE AFTER
	
}
