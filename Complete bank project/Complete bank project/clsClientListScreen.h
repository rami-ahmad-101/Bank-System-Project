#pragma once
#include <iostream>
#include "clsScreen.h"

using namespace std;


class clsClientListScreen : protected clsScreen
{
	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(12) << Client.FirstName;
		cout << "| " << left << setw(9) << Client.Phone;
		cout << "| " << left << setw(20) << Client.Email;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(9) << Client.AccountBalance;
	}


public:

	static void ShowClientsList()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;
		}

		vector <clsBankClient> vClients = clsBankClient::GetClientList();

		string Title = "Client List";
		string SubTitle = "("+to_string(vClients.size()) + ") Clients";
		_DrawScreenHeader(Title, SubTitle);
	
		cout << "\n_________________________________________________";
		cout << "_______________________________________\n\n";
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(12) << "Client Name";
		cout << "| " << left << setw(9) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(9) << "Balance";
		cout << "\n______________________________________________";
		cout << "__________________________________________\n\n";

		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tThere is no Clients to show!" << endl;
		}
		else
		{
			for (clsBankClient c : vClients)
			{
				_PrintClientRecordLine(c);
				cout << endl;
			}
		}
		cout << "\n_______________________________";
		cout << "_________________________________________________________\n";

	}


};