#pragma once
#include <iostream>
#include "clsScreen.h"

using namespace std;

class clsTransferScreen:protected clsScreen
{

	static void PrintClientCard(clsBankClient Client)
	{
		cout << "Client Card :" << endl;
		cout << "__________\n";
		cout << "Full Name : " << Client.FirstName << " " << Client.LastName << endl;
		cout << "Account Number : " << Client.AccountNumber() << endl;
		cout << "Account Balance : " << Client.AccountBalance << endl;
		cout << "__________\n";
	}

public:

	static void ShowTransactionScreen()
	{
		system("cls");

		_DrawScreenHeader("Transfer Screen");

		string AccountNumber = "";
		cout << "\nPlease Enter Client AccountNumber to Transfer From:";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found chose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient ClientFrom = clsBankClient::Find(AccountNumber);
		PrintClientCard(ClientFrom);
		
		AccountNumber = "";
		cout << "\nPlease Enter Client AccountNumber to Transfer To:";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found chose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient ClientTo = clsBankClient::Find(AccountNumber);
		PrintClientCard(ClientTo);


		float TransferAmont = 0;

		cout << "Enter Transfer Amont ?\n";
		cin >> TransferAmont;
		

		cout << "\nAre you sure you want to perform this transaction ?\n";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (ClientFrom.Transfer(TransferAmont, ClientTo, CurrentUser.UserName))
			{

				cout << "\n\nTransfer Done Successfully \n";
				PrintClientCard(ClientFrom);
				PrintClientCard(ClientTo);
			}
			else
			{
				cout << "Error";
			}
		}
		else
		{
			cout << "\nOperation was cancelled\n";
		}

	}


};