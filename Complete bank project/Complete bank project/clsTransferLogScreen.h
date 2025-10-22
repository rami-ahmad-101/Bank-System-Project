#pragma once

#include <iostream>
#include "clsScreen.h"

using namespace std;

class clsTransferLogScreen:protected clsScreen
{

	static void _PrintTransferRegisterRecord(clsBankClient::stTransferLogRecord TransferRecord)
	{
		cout << "| " << left << setw(22) << TransferRecord.DateAndTime;
		cout << "| " << left << setw(8) << TransferRecord.FromAccNumber;
		cout << "| " << left << setw(8) << TransferRecord.ToAccNumber;
		cout << "| " << left << setw(8) << TransferRecord.Amount;
		cout << "| " << left << setw(10)<< TransferRecord.FromAccBalacnce;
		cout << "| " << left << setw(10)<< TransferRecord.ToAccBalance;
		cout << "| " << left << setw(8)  << TransferRecord.UserName;
	}


public:

	static void ShowLoginRegisterScreen()
	{
		system("cls");
		vector <clsBankClient::stTransferLogRecord> vRecord = clsBankClient::GetTransferRegisterRecord();

		string Title = "Transfer Register";
		string SubTitle = "(" + to_string(vRecord.size()) + ") In";
		_DrawScreenHeader(Title, SubTitle);

		cout << "\n_________________________________________________";
		cout << "_______________________________________\n\n";
		cout << "| " << left << setw(22) << "Date&Time";
		cout << "| " << left << setw(8) << "FromAccN";
		cout << "| " << left << setw(8)  << "ToAccN";
		cout << "| " << left << setw(8)  << "Amount";
		cout << "| " << left << setw(10)  << "FromAccB";
		cout << "| " << left << setw(10)  << "ToAccN";
		cout << "| " << left << setw(8) << "UserName";
		cout << "\n______________________________________________";
		cout << "__________________________________________\n\n";

		if (vRecord.size() == 0)
		{
			cout << "\t\t\t\tThere is no Search to show!" << endl;
		}
		else
		{
			for (clsBankClient::stTransferLogRecord t: vRecord)
			{
				_PrintTransferRegisterRecord(t);
				cout << endl;
			}
		}
		cout << "\n_______________________________";
		cout << "_________________________________________________________\n";

	}

};

