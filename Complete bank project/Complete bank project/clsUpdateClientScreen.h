#pragma once
#include <iostream>
#include "clsScreen.h"

using namespace std;


class clsUpdateClientScreen:protected clsScreen
{

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName :";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName :";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Phone:";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Email :";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter PinCode :";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance :";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();

	}

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

	static void ShowUpdateClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
		{
			return;
		}
		_DrawScreenHeader("Update Screen");

		string AccountNumber = "";
		cout << "\nPlease Enter Client AccountNumber :";
		AccountNumber = clsInputValidate::ReadString();
	
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found chose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
	
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		Client1.Print();
	
		cout << "\n\nUpdate Client Info :";
		cout << "\n_________________________\n";
	
		_ReadClientInfo(Client1);
		clsBankClient::enSaveResults SaveResult;
	
		SaveResult = Client1.Save();
	
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceded:
		{
			cout << "\nAccount Updated Successfully \n";
			Print(Client1);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		}
	
	
	}


};