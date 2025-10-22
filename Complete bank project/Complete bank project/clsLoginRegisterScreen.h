#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;


class clsLoginRegisterScreen : protected clsScreen
{
	static void _PrintLoginRegisterRecord(clsUser::stLoginRegisterRecord Record)
	{
		cout << "| " << left << setw(25) << Record.DateAndTime;
		cout << "| " << left << setw(12) << Record.UserName;
		cout << "| " << left << setw(12) << Record.Password;
		cout << "| " << left << setw(5) << Record.Permissions;
	}
public:

	static void ShowLoginRegisterScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}
		system("cls");
		vector <clsUser::stLoginRegisterRecord> vRecord = clsUser::GetLoginRegisterRecord();

		string Title = "Login Register";
		string SubTitle = "(" + to_string(vRecord.size()) + ") In";
		_DrawScreenHeader(Title, SubTitle);

		cout << "\n_________________________________________________";
		cout << "_______________________________________\n\n";
		cout << "| " << left << setw(25) << "Date And Time";
		cout << "| " << left << setw(12) << "User Name";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(5) << "Permissions";
		cout << "\n______________________________________________";
		cout << "__________________________________________\n\n";

		if (vRecord.size() == 0)
		{
			cout << "\t\t\t\tThere is no Search to show!" << endl;
		}
		else
		{
			for (clsUser::stLoginRegisterRecord L : vRecord)
			{
				_PrintLoginRegisterRecord(L);
				cout << endl;
			}
		}
		cout << "\n_______________________________";
		cout << "_________________________________________________________\n";

	}


};