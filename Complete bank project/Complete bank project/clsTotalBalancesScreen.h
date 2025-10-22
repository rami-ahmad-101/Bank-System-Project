#pragma once

#include <iostream>
#include "clsScreen.h"

using namespace std;
class clsTotalBalancesScreen : protected clsScreen
{
	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(40) << Client.FirstName;
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}


public:


	static void ShowTotalBalancesScreen()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientList();

		string Title = "Total Balances";
		string SubTitle = "  " + to_string(vClients.size()) + " Client";

		_DrawScreenHeader(Title,SubTitle);

		cout << "\n_________________________________________________";
		cout << "_______________________________________\n\n";
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_________________________________________________";
		cout << "_______________________________________\n\n";

		long TotalBalances = 0;

		TotalBalances = clsBankClient::GetTotalBalances();
		
		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tThere is no Clients to show!" << endl;
		}
		else
		{
			for(clsBankClient c : vClients)
			{
				_PrintClientRecordBalanceLine(c);
				cout << endl;
			}
		}
		cout << "\n_______________________________";
		cout << "_________________________________________________________\n";

		cout << "\t\t\tTotal Balances is " << TotalBalances << endl;
	}




};