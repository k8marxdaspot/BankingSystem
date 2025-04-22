#include "CheckingAccount.h"
#include "SavingAccount.h"
#include "Password.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;


int main()
{
	Customer customerList[20];
	CheckingAccount checkingList[20];
	SavingAccount savingList[20];
	int customerTracker = -1;
	int checkingTracker = -1;
	int savingTracker = -1;

	int numberWrongAttempts = 0;
	Password test;
	string username;
	string password;
	cout << "DOLPHIN BANK LOGIN" << endl;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	if (test.correctLogin(username, password))
	{
		cout << endl << "Logging in..." << endl;
	}
	else
	{
		while (!test.correctLogin(username, password))
		{
			numberWrongAttempts++;
			cout << endl << "Failed Login." << endl;
			if (numberWrongAttempts < 2)
			{
				cout << "You have " << 3 - numberWrongAttempts << " more attempts before the system times you out!" << endl;
			}
			else if (numberWrongAttempts == 2)
			{
				cout << "You have 1 more attempt before the system times you out!" << endl; // grammar fix for singular attempt
			}

			if (numberWrongAttempts == 3)
			{
				cout << endl << "You have been timed out for 10 seconds due to bad login attempts." << endl;
				time_t start = time(nullptr);
				while (difftime(time(nullptr), start) < 10.0)
				{
				
				}
				numberWrongAttempts = 0;
			}

			cout << endl;
			cout << "DOLPHIN BANK LOGIN" << endl;
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;
		}
	}
	

	if (test.correctLogin(username, password))
	{
		customerList[0].setAll("Bobber", "Chang", "51 stone street", "904-614-7571", "bobberChang@gmail.com");
		customerList[1].setAll("Clemente", "Smith", "91 dirt street", "904-555-5550", "ClementeIsHim@gmail.com");
		customerTracker++;
		customerTracker++;
		checkingList[0].setAll(0, 10000, &customerList[0], 100);
		checkingList[1].setAll(1, 5000, &customerList[0], 50.0);
		checkingTracker++;
		checkingTracker++;
		savingList[0].setAll(&customerList[0], 0, 8000, 0.01);
		savingList[1].setAll(&customerList[1], 1, 20000, 0.05);
		savingList[2].setAll(&customerList[0], 2, 1000, 0.005);
		savingTracker++;
		savingTracker++;
		savingTracker++;

		cout << "Prior to running menu we provided these customers and accounts..." << endl;
		customerList[0].PrintInfo();
		checkingList[0].PrintInfo();
		checkingList[1].PrintInfo();
		savingList[0].PrintInfo();
		customerList[1].PrintInfo();
		savingList[1].PrintInfo();
		savingList[2].PrintInfo();


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
							break;
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
							cout << "Customer found: " << customerList[i].getFname() << " " << customerList[i].getLname() << endl << endl;
							existingCustomer = true;
							bool existingAccount = false;
							for (int j = 0; j < 20; j++) // searching for checking and savings accounts associated with customer account
							{
								if (&customerList[i] == checkingList[j].returnAddress())
								{
									cout << "Checking Account:" << endl;
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
								cout << endl << "Customer has no associated accounts." << endl;
								cout << "Exiting to main menu..." << endl;
							}
							break;
						}
					}

					if (existingCustomer == false)
					{
						cout << endl << "Customer not found! Cannot display account information." << endl << endl;
					}
				}
				else
				{
					int displayOpt;
					cout << endl << "Which would you like to display?" << endl;
					cout << "1. Customers" << endl;
					cout << "2. Checking Accounts" << endl;
					cout << "3. Saving Accounts" << endl;
					cin >> displayOpt;

					if (displayOpt == 1)
					{
						if (customerTracker > 0)
						{
							for (int i = 0; i <= customerTracker; i++)
							{
								customerList[i].PrintInfo();
							}
						}
						else if (customerTracker == 0)
						{
							customerList[0].PrintInfo();
						}
						else
						{
							cout << endl << "No Customers Found." << endl;
							cout << "Exiting to Main Menu..." << endl;
						}
					}
					else if (displayOpt == 2)
					{
						if (checkingTracker > 0)
						{
							for (int i = 0; i <= checkingTracker; i++)
							{
								checkingList[i].PrintInfo();
							}
						}
						else if (checkingTracker == 0)
						{
							checkingList[0].PrintInfo();
						}
						else
						{
							cout << endl << "No Checking Accounts Found." << endl;
							cout << "Exiting to Main Menu..." << endl;
						}
					}
					else if (displayOpt == 3)
					{
						if (savingTracker > 0)
						{
							for (int i = 0; i <= savingTracker; i++)
							{
								savingList[i].PrintInfo();
							}
						}
						else if (savingTracker == 0)
						{
							savingList[0].PrintInfo();
						}
						else
						{
							cout << endl << "No Saving Accounts Found." << endl;
							cout << "Exiting to Main Menu..." << endl;
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

						if (modifyOption == 1 || modifyOption == 2) // don't necessarily think it's a great idea to have this as a loop. bank teller wants to commit one action and once that modification is done should go back to main menu not loop
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
							else if (accountType != 1 && accountType != 2)
							{
								cout << endl << "Entered invalid option!" << endl;
								cout << "Exiting to main menu..." << endl;
								break;
							}
							else
							{
								cout << endl << "Customer does not have an account of this type." << endl;
								cout << "Exiting to main menu..." << endl;
								break;
							}
						}
						else if (modifyOption == 3)
						{
							int accEditOpt;
							cout << endl << "What would you like to edit?" << endl;
							cout << "1. First Name" << endl;
							cout << "2. Last Name" << endl;
							cout << "3. Address" << endl;
							cout << "4. Phone Number" << endl;
							cout << "5. Email" << endl;
							cin >> accEditOpt;

							if (accEditOpt == 1)
							{
								string newFName;
								cout << endl << "New First Name: ";
								cin >> newFName;
								customerList[i].setFname(newFName);
							}
							else if (accEditOpt == 2)
							{
								string newLName;
								cout << endl << "New Last Name: ";
								cin >> newLName;
								customerList[i].setLname(newLName);
							}
							else if (accEditOpt == 3)
							{
								string newAddress;
								cout << endl << "New Address: ";
								cin >> newAddress;
								customerList[i].setAddress(newAddress);
							}
							else if (accEditOpt == 4)
							{
								string newPhone;
								cout << endl << "New Phone Number: ";
								cin >> newPhone;
								customerList[i].setPhone(newPhone);
							}
							else if (accEditOpt == 5)
							{
								string newEmail;
								cout << endl << "New Email: ";
								cin >> newEmail;
								customerList[i].setEmail(newEmail);
							}
							else
							{
								cout << endl << "Entered invalid option." << endl;
								cout << "Exiting to main menu..." << endl;
							}
						}
						else if (modifyOption < 1 || modifyOption > 4)
						{
							cout << endl << "Entered invalid option. Exiting to main menu..." << endl;
							break;
						}
						else
						{
							cout << endl << "Exiting to main menu..." << endl;
						}
					}
				}

				if (existingCustomer == false)
				{
					cout << endl << "No Exisiting Customer with that Email or Phone Number!";
					cout << "Exiting to main menu..." << endl;
				}
			}
			else if (userOpt == 5)
			{
				string custEmail;
				string custPhone;
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

						if (noOfCustCheckAccs == 0 && noOfCustSavAccs == 0)
						{
							cout << endl << "This customer has no associated accounts." << endl;
							cout << "Exiting to main menu..." << endl;
							break;
						}

						cout << endl << "Please select the account type you are deleting:" << endl;
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

							cout << endl << "Deleting account..." << endl;
							checkingList[i].setAll(0, 0, nullptr, 0);
							cout << "Account deleted!" << endl;
							cout << "Returning to main menu..." << endl;
							break;
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

							cout << endl << "Deleting account..." << endl;
							savingList[i].setAll(nullptr, 0, 0, 0);
							cout << "Account deleted!" << endl;
							cout << "Returning to main menu..." << endl;
							break;
						}
						else if (accountType != 1 && accountType != 2)
						{
							cout << endl << "Entered invalid option!" << endl;
							cout << "Exiting to main menu..." << endl;
							break;
						}
						else
						{
							cout << endl << "Customer does not have an account of this type." << endl;
							cout << "Exiting to main menu..." << endl;
							break;
						}
					}
				}

				if (existingCustomer == false)
				{
					cout << endl << "No Exisiting Customer with that Email or Phone Number!";
					cout << "Exiting to main menu..." << endl;
				}
			}
			else if (userOpt == 6) // continuing to nest this option was a horrible idea and now its a headache to read over. writing down helps to keep track
			{
				string custEmail;
				string custPhone;
				bool existingCustomer = false;
				bool transferExistingCustomer = false;
				int tCustTracker = 0;


				cout << endl << "Please Input Customer Email: ";
				cin >> custEmail;

				cout << "Please Input Customer Phone Number:";
				cin >> custPhone;

				for (int i = 0; i < 20; i++) // search for existing customer with matching phone number or email
				{
					if (customerList[i].getEmail() == custEmail || customerList[i].getPhone() == custPhone) // found existing customer 
					{
						cout << endl << "Customer Found: " << customerList[i].getFname() << " " << customerList[i].getLname() << endl;
						existingCustomer = true;

						int senderDisplayCount = 0;
						int senderAccounts[20];
						for (int j = 0; j < 20; j++) // searching for savings accounts associated with sender account
						{
							if (&customerList[i] == savingList[j].returnAddress())
							{
								senderAccounts[senderDisplayCount] = j;
								cout << endl << "Saving Account #" << senderDisplayCount + 1 << " :" << endl;
								savingList[j].PrintInfo();
								senderDisplayCount++;
							}
						}

						if (senderDisplayCount == 0) // if customer has no savings end transfer and exit to main menu
						{
							cout << endl << "Sender has no savings accounts. Transfer aborted." << endl;
							cout << "Exiting to main menu..." << endl;
							break;
						}

						string transferEmail;
						string transferPhone;
						cout << endl << "Now Please Enter Information for the Account the Customer Wishes to Transfer Funds To" << endl;
						cout << "Please Input Email: ";
						cin >> transferEmail;
						cout << "Please Input Phone Number:";
						cin >> transferPhone;

						for (int j = 0; j < 20; j++) // searching for customer and savings account we want to transfer money to
						{
							if (customerList[j].getEmail() == transferEmail || customerList[j].getPhone() == transferPhone)
							{
								transferExistingCustomer = true;
								cout << endl << "Customer Found: " << customerList[j].getFname() << " " << customerList[j].getLname() << endl;

								int transferDisplayCount = 0;
								int transferAccounts[20];
								for (int k = 0; k < 20; k++) {
									if (&customerList[j] == savingList[k].returnAddress())
									{
										transferAccounts[transferDisplayCount] = k;
										cout << endl << "Saving Account #" << transferDisplayCount + 1 << " :" << endl;
										savingList[k].PrintInfo();
										transferDisplayCount++;
									}
								}

								if (transferDisplayCount == 0)
								{
									cout << endl << "Acccount you want to transfer to has no associated savings accounts." << endl;
									cout << "Exiting to main menu..." << endl;
									break;
								}

								cout << endl << "*Transfer User Savings Account Found*" << endl;

								int senderChoice;
								cout << endl << "Enter sender account number you wish to transfer FROM: ";
								cin >> senderChoice;

								if (senderChoice > senderDisplayCount || senderChoice < 1) {
									cout << endl << "Invalid sender account choice. Transfer aborted." << endl;
									cout << "Returing to main menu..." << endl;
									break;
								}
								int senderAccIndex = senderAccounts[senderChoice - 1];

								int transferChoice;
								cout << endl << "Enter the transfer account number you wish to transfer TO: ";
								cin >> transferChoice;

								if (transferChoice > transferDisplayCount || transferChoice < 1)
								{
									cout << endl << "Invalid transfer account choice. Transfer aborted." << endl;
									cout << "Returing to main menu..." << endl;
									break;
								}
								int transferAccIndex = transferAccounts[transferChoice - 1];

								double transferAmount;
								cout << endl << "How much money do you want to transfer:" << endl;
								cin >> transferAmount;

								savingList[senderAccIndex].transfer(transferAmount, &savingList[transferAccIndex]);
								savingList[senderAccIndex].PrintInfo();
								savingList[transferAccIndex].PrintInfo();
							}
						}
						if (transferExistingCustomer == false)
						{
							cout << endl << "Recipient customer not found! Transfer aborted." << endl;
							break;
						}
					}
					else if (existingCustomer == false)
					{
						cout << endl << "Sender customer not found. Transfer aborted." << endl;
						cout << "Exiting to main menu..." << endl;
					}
				}
			}
			else
			{
				cout << endl << "Error invalid option entered!" << endl;
				cout << "Please make sure to enter an option from 1 to 7!" << endl;
			}

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
			cout << endl;
		}
	} 
	
	


	system("pause");
	return 0;
}
