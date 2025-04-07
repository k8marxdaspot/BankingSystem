#include "Account.h"
#include "CheckingAccount.h"
#include <string>
#include <iostream>


class CheckingAccount : public Account
{
	double overDraftLimit;

public:
	void setOverDraftLimit(double _overDraftLimit)
	{
		if (_overDraftLimit <= 100)
		{
			overDraftLimit = _overDraftLimit;
		}
		else
		{
			overDraftLimit = 100.0;
		}
		
	}
	double getOverDraftLimit() const
	{
		return overDraftLimit;
	}
	CheckingAccount() : Account()
	{
		overDraftLimit = 0.0;
	}
	CheckingAccount(int _id, double _balance, Customer* _customer, double _overDraftLimit) : Account(_id, _balance, _withdrawCounter, _depositsCounter, _customer)
	{
		setOverDraftLimit(_overDraftLimit);
	}
	void setAll(int _id, double _balance, Customer* _customer, double _overDraftLimit)
	{
		Account::Account(_id, _balance, _customer);
		overDraftLimit = _overDraftLimit;
	}
	void WithdrawMoney(double amount)
	{
		if (amount > 0 && getBalance() - amount > 0)
		{
			Account::WithdrawMoney(amount);

		}
		else if (abs(getBalance() - amount) <= overDraftLimit)
		{
			cout << "Overdraft Warning!" << endl;
			cout << "Fee: $20" << endl;
			Account::WithdrawMoney(amount + 20);
		}
		else if (abs(getBalance() - amount) > overDraftLimit)
		{
			cout << "Withdrawal not allowed!" << endl;
			cout << "Withdrawal amount over over draft limit." << endl;
		}
	}

};

void CheckingAccount::setOverDraftLimit(double _overDraftLimit)
{
	if (_overDraftLimit <= 100)
	{
		overDraftLimit = _overDraftLimit;
	}
	else
	{
		overDraftLimit = 100.0;
	}

}
double CheckingAccount::getOverDraftLimit() const
{
	return overDraftLimit;
}
CheckingAccount::CheckingAccount() : Account()
{
	overDraftLimit = 0.0;
}
CheckingAccount::CheckingAccount(int _id, double _balance, Customer* _customer, double _overDraftLimit) : Account(_id, _balance, _withdrawCounter, _depositsCounter, _customer)
{
	setOverDraftLimit(_overDraftLimit);
}
void CheckingAccount::setAll(int _id, double _balance, Customer* _customer, double _overDraftLimit)
{
	Account::Account(_id, _balance, _customer);
	overDraftLimit = _overDraftLimit;
}
void CheckingAccount::WithdrawMoney(double amount)
{
	if (amount > 0 && getBalance() - amount > 0)
	{
		Account::WithdrawMoney(amount);

	}
	else if (abs(getBalance() - amount) <= overDraftLimit)
	{
		cout << "Overdraft Warning!" << endl;
		cout << "Fee: $20" << endl;
		Account::WithdrawMoney(amount + 20);
	}
	else if (abs(getBalance() - amount) > overDraftLimit)
	{
		cout << "Withdrawal not allowed!" << endl;
		cout << "Withdrawal amount over over draft limit." << endl;
	}
}