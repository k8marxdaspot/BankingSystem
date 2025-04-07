#pragma once
#ifndef ACCOUNT
#include "Customer.h"
#include <string>
#include <iostream>
using namespace std;

class Account
{
	int id;
	double balance;
	int withdrawalCounter = 0, depositsCounter = 0;
	Customer* accountCustomer;

public:
	int getId() const;

	double getBalance() const;

	int getwithdrawalCounter() const;
	int getDepositsCounter() const;
	Customer* getAccountCustomer();

	void setId(int _id);
	void setBalance(double _balance);

	void setCustomer(Customer* cPtr);



	void setAll(Customer* cPtr, int _id, double _balance);

	Account();
	Account(Customer* cPtr, int _id, double _balance);

	void depositMoney(double a);

	void withdrawMoney(double w);

	void PrintInfo();


};
#endif // !ACCOUNT
<<<<<<< HEAD

=======
#pragma once
>>>>>>> bbd6eac61987c45d175cd7a9ff75c4d028cc669b
