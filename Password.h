#pragma once
#ifndef PASSWORD
#include <iostream>
#include <string>
using namespace std;

class Password
{
	string employeeUsers[10] = {"jmoran10", "kfields56", "jfarnberg", "krashid5", "mrobinson47", "fdostoevsky", "nklein08", "aibrahim15", "erobanvitch", "szizek12"};
	string employeePasswords[10] = { "admin1", "ILoveYou", "p4ssw0rd", "REDFERRARI", "#1dodgersfan", "crimeandpunishment", "123456qwerty", "h@ppyb1rthd@y", "letmein", "Newpassword2025"};
public:
	bool correctLogin(string _username, string _password);
};
#endif // !PASSWORD

