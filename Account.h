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
	void DepositMoney(double a);
	void WithdrawMoney(double w);
	void PrintInfo();
	Customer* returnAddress();
};
#endif // !ACCOUNT

