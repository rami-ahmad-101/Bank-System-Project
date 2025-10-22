#pragma once

#include <iostream>
#include "clsScreen.h"
using namespace std;

class clsWithdrawScreen : protected clsScreen
{

	static void _Print(clsBankClient client)
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

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cin >> AccountNumber;
		return AccountNumber;
	}

public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("Withdraw Screen");
		cout << "Enter your Account Number :\n";

		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found chose another one: ";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_Print(Client1);

		cout << "please enter Withdraw Amount!\n";

		double WithdrawAmount = 0;
		cin >> WithdrawAmount;

		while (Client1.AccountBalance < WithdrawAmount)
		{
			cout << "Withdraw Amount is bigger than your balance try another amount!\n";
			cout << "\nYour balance is :" << Client1.AccountBalance;
			cout << "\nYour Withdraw is :" << WithdrawAmount << endl;
			
			cin >> WithdrawAmount;
		}

		cout << "\nAre you sure you want to perform this transaction ?\n";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			Client1.Withdraw(WithdrawAmount);
			cout << "Amount Withdraw done Successfully.\n";
			cout << "\nNew Balance is " << Client1.AccountBalance;
		}
		else
		{
			cout << "\nOperation was cancelled\n";
		}


	}


};