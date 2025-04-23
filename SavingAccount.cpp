#include "SavingAccount.h"

void SavingAccount::setInterestRate(double _interestRate)
{
	if (interestRate >= 0.0 && interestRate < 10.0) // interest rate should not be 0 and it would be very unlikely for it to be greater than 10
	{											   // high yield savings accounts have around a maximum interest rate of 5ish	
		interestRate = _interestRate;
	}
	else
	{
		interestRate = 0.0;
	}
}

double SavingAccount::getInterestRate() const
{
	return interestRate;
}

SavingAccount::SavingAccount() : Account()
{
	interestRate = 0.0;
}

SavingAccount::SavingAccount(Customer * _customer, int _id, double _balance, double _interestRate) : Account(_customer, _id, _balance)
{
	setInterestRate(_interestRate);
}

void SavingAccount::setAll(Customer * _customer, int _id, double _balance, double _interestRate)
{
	Account::setAll(_customer, _id, _balance);
	setInterestRate(_interestRate);
}

void SavingAccount::payInterest()
{
	if (getBalance() > 0)
	{
		double interestAccrued = getBalance() * interestRate;
		cout << "Interest Accrued: " << interestAccrued << endl;
		DepositMoney(interestAccrued);
	}
}

void SavingAccount::transfer(double amount, SavingAccount* destinationAccount)
{
	if (getBalance() - amount >= 0.0)
	{
		WithdrawMoney(amount);
		(*destinationAccount).DepositMoney(amount);
		cout << endl << "Successful Transfer" << endl;
	}
	else
	{
		WithdrawMoney(amount);
		cout << endl << "Transfer failed!" << endl;
		cout << "Returning to main menu..." << endl;
	}
}
