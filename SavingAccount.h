#pragma once
#ifndef SAVINGACCOUNT
#include "Account.h"

class SavingAccount : public Account
{
	double interestRate;
public:
	void setInterestRate(double _interestRate);
	double getInterestRate() const;
	SavingAccount();
	SavingAccount(Customer * _customer, int _id, double _balance, double _interestRate);
	void setAll(Customer * _customer, int _id, double _balance, double _interestRate);
	void payInterest();
	void transfer(double amount, SavingAccount* destinationAccount);
};
#endif // !SAVINGACCOUNT

