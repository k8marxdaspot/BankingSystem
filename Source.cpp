#include "Customer.h"
#include "Account.h"
#include <iostream>
using namespace std;

int main()
{
	Customer customerlist[20];
	CheckingAccount checkingList[20];
	SavingAccount savinglist[20];
	int tracker;

	customerlist[0].setAll("Bobber", "Chang", "51 stone street", "904-614-7571", "bobberChang@gmail.com");
	customerlist[1].setAll("Clemente", "Smith", "91 dirt street", "904-555-5550", "ClementeIsHim@gmail.com");
	customerlist[0].PrintInfo();
	customerlist[1].PrintInfo();


	for (int i = 0; i < sizeof(customerlist); i++)
	{
		if ((customerlist[i].getFname() = "") && (customerlist[i].getAddress() == "") && (customerlist[i].getLname() = "") && (customerlist))
		{
			tracker = i;
		}
	}
	customerlist[2] 





		//MAKE SURE TO DO GET LINE FOR ADDRESS AND CIN>IGNORE AFTER

}
