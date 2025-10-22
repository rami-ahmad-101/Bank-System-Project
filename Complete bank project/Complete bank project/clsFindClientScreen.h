#pragma once

#include <iostream>
#include "clsScreen.h"

using namespace std;


class clsFindClientScreen : protected clsScreen
{
	static void Print(clsBankClient client)
	{
		cout << "\nClient Card:";
		cout << "\n_________________________";
		cout << "\nFirst Name   :" << client.FirstName;
		cout << "\nLast Name    :" << client.LastName;
		cout << "\nFull Name    :" << client.FirstName << " " << client.LastName;
		cout << "\nEmail        :" << client.Email;
		cout << "\nPhone        :" << client.Phone;
		cout << "\nAcc Number   :" << client.AccountNumber();
		cout << "\nPassword     :" << client.PinCode;
		cout << "\nAcc Balance  :" << client.AccountBalance;
		cout << "\n_________________________\n";
	}


public:

	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		_DrawScreenHeader("Find Client Screen");

		string AccountNumber = "";
		cout << "\nPlease Enter Client AccountNumber :";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found chose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		if (Client1.IsEmpty())
		{
			cout << "Client not found!\n";

		}
		else
		{
			cout << "Client Found !\n";
			Print(Client1);
		}
	}


};