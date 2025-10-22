#pragma once
#include <iostream>
#include "clsScreen.h"

using namespace std;
class clsAddNewClientScreen : protected clsScreen
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


public :

	static void ShowAddNewClientScreen()
	{
	
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("Add New Client");
		string AccountNumber = "";

		cout << "\n Please Enter Account Number :";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is Already Used choose another one :";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case  clsBankClient::enSaveResults::svSucceded:
		{
			cout << "\nAccount Added Successfully\n";
			Print(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's empty";
			break;
		}
		case clsBankClient::enSaveResults::svFailAccountNumberExists:
		{
			cout << "Error\n";
			break;
		}
		default:
			break;
		}
	



	}

};