
#include "Customer.h"
#include "Account.h"
#include <iostream>
using namespace std;

int main()
{
	Customer c1("Kate", "Eggenberg", "123 Happy Lane", "904-429-8970", "keggenb@jacksonville.edu");
	cout << c1.getFname() << " " << c1.getLname() << " " << c1.getAddress() << " " << c1.getPhone() << " " << c1.getEmail() << endl;
	c1.setAll("Grace", "Eggenberg", "102 Knights Lane", "904-451-8661", "graceeggenberg@ucf.edu");
	c1.PrintInfo();

	Account a1(&c1, 1, 20000);
	a1.depositMoney(30000);
}
