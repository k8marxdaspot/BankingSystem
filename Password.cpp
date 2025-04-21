#include "Password.h"

bool Password::correctLogin(string _username, string _password)
{
	for (int i = 0; i < 10; i++)
	{
		if (_username == employeeUsers[i])
		{
			if (_password == employeePasswords[i])
			{
				cout << endl << "Successful login!" << endl;
				return true;
			}
		}
	}
	return false;
}