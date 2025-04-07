#pragma once
#ifndef CHECKINGACCOUNT
#include "Account.h"

class CheckingAccount : public Account
{
	double overDraftLimit;
public:
	void setOverDraftLimit(double _overDraftLimit);
	double getOverDraftLimit() const;
	CheckingAccount();
	CheckingAccount(int _id, double _balance, Customer* _customer, double _overDraftLimit);
	void setAll(int _id, double _balance, Customer* _customer, double _overDraftLimit);
	void WithdrawMoney(double amount);
};

#endif // !CHECKINGACCOUNT
