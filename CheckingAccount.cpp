#include "Account.h"

class CheckingAccount :: Account()
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
};