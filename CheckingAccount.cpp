#include "CheckingAccount.h"

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
CheckingAccount::CheckingAccount(int _id, double _balance, Customer* _customer, double _overDraftLimit) : Account(_customer, _id, _balance)
{
	setOverDraftLimit(_overDraftLimit);
}
void CheckingAccount::setAll(int _id, double _balance, Customer* _customer, double _overDraftLimit)
{
	Account::setAll(_customer, _id, _balance);
	overDraftLimit = _overDraftLimit;
}
void CheckingAccount::WithdrawMoney(double amount)
{
	if (amount > 0 && getBalance() - amount > 0)
	{
		Account::withdrawMoney(amount);

	}
	else if (abs(getBalance() - amount) <= overDraftLimit)
	{
		cout << "Overdraft Warning!" << endl;
		cout << "Fee: $20" << endl;
		Account::withdrawMoney(amount + 20);
	}
	else if (abs(getBalance() - amount) > overDraftLimit)
	{
		cout << "Withdrawal not allowed!" << endl;
		cout << "Withdrawal amount over over draft limit." << endl;
	}
}