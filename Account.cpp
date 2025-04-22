#include "Customer.h"
#include "Account.h"

int Account::getId() const
{
	return id;
}

double Account::getBalance() const
{
	return balance;
}

int Account::getwithdrawalCounter() const
{
	return withdrawalCounter;
}
int Account::getDepositsCounter() const
{
	return depositsCounter;
}
Customer* Account::getAccountCustomer()
{
	return accountCustomer;
}

void Account::setId(int _id)
{
	if (_id > 0)
	{
		id = _id;
	}
	else
	{
		id = 0;
	}
}
void Account::setBalance(double _balance)
{
	balance = _balance;
}

void Account::setCustomer(Customer* cPtr)
{
	accountCustomer = cPtr;
}



void Account::setAll(Customer* cPtr, int _id, double _balance)
{
	accountCustomer = cPtr;

	if (_id > 0)
	{
		id = _id;
	}
	else
	{
		id = 0;
	}
	balance = _balance;
}

Account::Account()
{
	id = 0;
	balance = 0.0;
	withdrawalCounter = 0;
	depositsCounter = 0;
	accountCustomer = nullptr;

}
Account::Account(Customer* cPtr, int _id, double _balance)
{
	setAll(cPtr, _id, _balance);
}

void Account::DepositMoney(double a)
{
	if (a >= 0)
	{
		balance = balance + a;
		depositsCounter++;
		cout << endl << "DEPOSIT SUCCESSFUL!" << endl;
		cout << "ACCOUNT BALANCE NOW: $" << balance << endl;
	}
	else
	{
		cout << endl << "*ERROR NEGATIVE DEPOSIT AMOUNT*";
	}
}

void Account::WithdrawMoney(double w)
{
	if (w <= balance)
	{
		balance = balance - w;
		withdrawalCounter++;
		cout << endl << "WITHDRAWAL SUCCESSFUL!" << endl;
		cout << "ACCOUNT BALANCE NOW: $" << balance << endl;
	}
	else
	{
		cout << endl << "*INSUFFICIENT FUNDS*";
	}
}

void Account::PrintInfo()
{
	cout << setw(5) << "ID" << setw(10) << "Balance" << setw(20) << "Withdrawals Made" << setw(15) << "Deposits Made" << endl;
	for (int i = 0; i < 50; i++)
	{
		cout << "=";
	}
	cout << endl;
	cout << setw(5) << id << setw(10) << balance << setw(20) << withdrawalCounter << setw(15) << depositsCounter << endl;
	(*accountCustomer).PrintInfo();
	cout << endl;
}

Customer* Account::returnAddress()
{
	return accountCustomer;
}