class Account
{
	int id;
	double balance;
	int withdrawalCounter = 0, depositsCounter = 0;
	Customer* accountCustomer;

public: 
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
	Customer * Account::getAccountCustomer()
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

	void Account::setWithdrawalcounter(int _wc)
	{
		withdrawalCounter = _wc;
	}
	void Account::setDepositsCounter(int _dc)
	{
		depositsCounter = _dc;
	}
	void Account::setCustomer(Customer * cPtr)
	{
		accountCustomer = cPtr;
	}



	void Account::setAll(Customer* cPtr, int _id, double _balance, int _wc, int _dc)
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
		withdrawalCounter = _wc;
		depositsCounter = _dc;
	}

	Account::Account()
	{
		id = 0;
		balance = 0.0;
		withdrawalCounter = 0;
		depositsCounter = 0;
		accountCustomer = nullptr;

		Account::Account(Customer * cPtr, int _id, double _balance, int _wc, int _dc)
		{
			SetAll(cPtr, _id, _balance, _wc, _dc)
		}
	}
};
