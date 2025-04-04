#include "Customer.h"

Customer::Customer()
{
	fname = "";
	lname = "";
	address = "";
	phone = "";
	email = "";
}
Customer::Customer(string _fname, string _lname, string _address, string _phone, string _email)
{
	setAll(_fname, _lname, _address, _phone, _email);
}
void Customer::setFname(string _fname)
{
	fname = _fname;
}
void Customer::setLname(string _lname)
{
	lname = _lname;
}
void Customer::setAddress(string _address)
{
	address = _address;
}
void Customer::setPhone(string _phone)
{
	phone = _phone;
}
void Customer::setEmail(string _email)
{
	email = _email;
}
string Customer::getFname() const
{
	return fname;
}
string Customer::getLname() const
{
	return lname;
}
string Customer::getAddress() const
{
	return address;
}
string Customer::getPhone() const
{
	return phone;
}
string Customer::getEmail() const
{
	return email;
}
void Customer::setAll(string _fname, string _lname, string _address, string _phone, string _email)
{
	fname = _fname;
	lname = _lname;
	address = _address;
	phone = _phone;
	email = _email;
}
void Customer::PrintInfo()
{
	cout << setw(15) << "First Name" << setw(15) << "Last Name" << setw(20) << "Address" << setw(15) << "Phone Number" << setw(20) << "Email" << endl;
	for (int i = 0; i < 50; i++)
	{
		cout << "=";
	}
	cout << endl;
	cout << setw(15) << fname << setw(15) << lname << setw(20) << address << setw(15) << phone << setw(20) << email << endl;
}