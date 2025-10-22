#pragma once

#include <iostream>

using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Phone;
	string _Email;


public:
	clsPerson() {}

	clsPerson(string FirstName,string LastName,string Phone , string Email)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Phone = Phone;
		_Email = Email;
	}

	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	void setLastName(string LastName)
	{
		_LastName = LastName;
	}
	void setPhone(string Phone)
	{
		_Phone = Phone;
	}
	void setEmail(string Email)
	{
		_Email = Email;
	}

	string getFirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = getFirstName, put = setFirstName))string FirstName;
	string getLastName()
	{
		return _LastName;
	}
	__declspec(property(get = getLastName, put = setLastName))string LastName;
	string getPhone()
	{
		return _Phone;
	}
	__declspec(property(get = getPhone, put = setPhone))string Phone;
	string getEmail()
	{
		return _Email;
	}
	__declspec(property(get = getEmail, put = setEmail))string Email;


};