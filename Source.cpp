#include "CheckingAccount.h"
#include "SavingAccount.h"
#include <string>
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
	cout << endl << "Welcome to Dolphin Bank!" << endl << endl;
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

				for (int i = 0; i < 20; i++) // search for existing customer with matching phone number or email
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

				for (int i = 0; i < 20; i++) // search for existing customer with matching phone number or email
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
			cin.ignore();

			if (tempUserOpt != 1 && tempUserOpt != 2)
			{
				cout << "Error Invalid Option Entered!" << endl;
			}
			else if (tempUserOpt == 1)
			{
				string custEmail;
				string custPhone;
				bool existingCustomer = false;

				cout << "Please input email: ";
				getline(cin, custEmail);
				cout << "Please input phone number:";
				getline(cin, custPhone);

				for (int i = 0; i < 20; i++) // search for existing customer with matching phone number or email
				{
					if (customerList[i].getEmail() == custEmail || customerList[i].getPhone() == custPhone) // found existing customer 
					{
						cout << "Customer found: " << customerList[i].getFname() << " " << customerList[i].getLname() << endl;
						existingCustomer = true;
						bool existingAccount = false;
						for (int j = 0; j < 20; j++) // searching for checking and savings accounts associated with customer account
						{
							if (&customerList[i] == checkingList[j].returnAddress())
							{
								cout<< "Checking Account:" << endl;
								checkingList[j].PrintInfo();
								existingAccount = true;
							}
							if (&customerList[i] == savingList[j].returnAddress())
							{
								cout << "Saving Account" << endl;
								savingList[j].PrintInfo();
								existingAccount = true;
							}
						}
						if (existingAccount == false)
						{
							cout << "Customer has no associated accounts." << endl;
						}
						else
						{

						}
						break;
					}
				}

				if (existingCustomer == false)
				{
					cout << endl << "Customer not found! Cannot display account information." << endl << endl;
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

			for (int i = 0; i < 20; i++) // search for existing customer with matching phone number or email
			{
				if (customerList[i].getEmail() == custEmail || customerList[i].getPhone() == custPhone) // found existing customer 
				{
					cout << endl << "Customer found: " << customerList[i].getFname() << " " << customerList[i].getLname() << endl;
					existingCustomer = true;
					int noOfCustCheckAccs = 0;
					int noOfCustSavAccs = 0;

					for (int j = 0; j < 20; j++) // searching for checking and savings accounts associated with customer account
					{
						if (&customerList[i] == checkingList[j].returnAddress())
						{
							noOfCustCheckAccs++;
							cout << endl << "Checking Account #" << noOfCustCheckAccs << " :" << endl;
							checkingList[j].PrintInfo();
						}
						if (&customerList[i] == savingList[j].returnAddress())
						{
							noOfCustSavAccs++;
							cout << endl << "Saving Account #" << noOfCustSavAccs << " :" << endl;
							savingList[j].PrintInfo();
						}
					}
					
					cout << endl << "MODIFICATION OPTIONS:" << endl;
					cout << "1. DEPOSIT" << endl;
					cout << "2. WITHDRAW" << endl;
					cout << "3. EDIT CUSTOMER ACCOUNT INFORMATION" << endl;
					cout << "4. EXIT BACK TO MAIN MENU" << endl;
					cout << "Please enter option (1-4): ";
					cin >> modifyOption;

					if (modifyOption == 1 || modifyOption == 2) // don't necessarily think it's a great idea to have this as a loop. bank teller wants to committ one action and once that modification is done should go back to main menu not loop
					{
						if (noOfCustCheckAccs == 0 && noOfCustSavAccs == 0)
						{
							cout << endl << "This customer has no associated accounts." << endl;
							cout << "Exiting to main menu..." << endl;
							break;
						}

						cout << endl << "Please select account type:" << endl;
						cout << "1. Checking Account" << endl;
						cout << "2. Savings Account" << endl;
						int accountType;
						cin >> accountType;

						if (accountType == 1 && noOfCustCheckAccs != 0) // checking account 
						{
							int custAcc;
							int tracker = 0;
							for (int j = 0; j < 20; j++) // displaying all checking accounts associated with customer account
							{
								if (&customerList[i] == checkingList[j].returnAddress())
								{
									tracker++;
									cout << endl << "Checking Account #" << j + 1 << " :" << endl;
									checkingList[j].PrintInfo();
								}
							}

							if (tracker > 1) // if there is more than once checking account associated with customer ask teller to choose which account is going to be modified
							{
								cout << endl << "Which checking acccount?" << endl;
								cin >> custAcc;
								if (custAcc > tracker || custAcc < 1)
								{
									cout << endl << "Entered invalid account number!" << endl;
									cout << "Exiting to main menu..." << endl;
									break;
								}
								custAcc--;
							}
							else
							{
								custAcc = 0;
							}
							
							double amount;
							cout << endl << "Enter amount customer would like to deposit or withdraw:";
							cin >> amount;

							if (modifyOption == 1)
							{
								checkingList[custAcc].DepositMoney(amount);
							}
							else
							{
								checkingList[custAcc].WithdrawMoney(amount);
							}
						}
						else if (accountType == 2 && noOfCustSavAccs != 0) // saving account
						{
							int custAcc;
							int tracker = 0;
							for (int j = 0; j < 20; j++) // displaying all savings accounts associated with customer account
							{
								if (&customerList[i] == savingList[j].returnAddress())
								{
									tracker++;
									cout << endl << "Saving Account #" << j + 1 << " :" << endl;
									savingList[j].PrintInfo();
								}
							}

							if (tracker > 1) // if there is more than once saving account associated with customer ask teller to choose which account is going to be modified
							{
								cout << endl << "Which savings acccount?" << endl;
								cin >> custAcc;
								if (custAcc > tracker || custAcc < 1)
								{
									cout << endl << "Entered invalid account number!" << endl;
									cout << "Exiting to main menu..." << endl;
									break;
								}
								custAcc--;
							}
							else
							{
								custAcc = 0;
							}

							double amount;
							cout << endl << "Enter amount customer would like to deposit or withdraw:";
							cin >> amount;

							if (modifyOption == 1)
							{
								savingList[custAcc].DepositMoney(amount);
							}
							else
							{
								savingList[custAcc].WithdrawMoney(amount);
							}
						}
						else if (accountType != 1 || accountType != 2)
						{
							cout << endl << "Entered invalid option!" << endl;
							cout << "Exiting to main menu...";
							break;
						}
						else
						{
							cout << endl << "Customer does not have an account of this type." << endl;
							cout << "Exiting to main menu...";
							break;
						}
					}
					else if (modifyOption == 3)
					{

					}
					else if (modifyOption < 1 || modifyOption > 4)
					{
						cout << endl << "Entered invalid option. Exiting to main menu..." << endl;
						break;
					}
				}
			}

			if (existingCustomer == false)
			{
				cout << endl << "No Exisiting Customer with that Email or Phone Number!";
				cout << "Exiting to main menu...";
			}
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
	
		cout << endl <<  "Welcome to Dolphin Bank!" << endl << endl;
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
	}



		//MAKE SURE TO DO GET LINE FOR ADDRESS AND CIN>IGNORE AFTER
	
}
