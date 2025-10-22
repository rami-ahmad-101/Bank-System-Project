#pragma once
#include <iostream>
#include "clsUser.h"

#include "clsScreen.h"
using namespace std;

class clsListUserScreen : protected clsScreen
{

	static void _PrintUserRecordLine(clsUser c)
	{
		cout << "| " << left << setw(10) << c.UserName;
		cout << "| " << left << setw(12) << c.FirstName;
		cout << "| " << left << setw(20) << c.Email;
		cout << "| " << left << setw(9)  << c.Phone;
		cout << "| " << left << setw(10) << c.Password;
		cout << "| " << left << setw(3)  << c.Permissions;
	}
	  
public:

	static void ShowListUser()
	{
		vector <clsUser> vUsers = clsUser::GetUserList();

		string Title = "User List";
		string SubTitle = "(" + to_string(vUsers.size()) + ") User";
		_DrawScreenHeader(Title, SubTitle);

		cout << "\n_________________________________________________";
		cout << "_______________________________________\n\n";
		cout << "| " << left << setw(10) << "UserName";
		cout << "| " << left << setw(12) << "Full Name";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(9)  << "Phone";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(3)  << "Permissions";
		cout << "\n______________________________________________";
		cout << "__________________________________________\n\n";

		if (vUsers.size() == 0)
		{
			cout << "\t\t\t\tThere is no Users to show!" << endl;
		}
		else
		{
			for (clsUser c : vUsers)
			{
				_PrintUserRecordLine(c);
				cout << endl;
			}
		}
		cout << "\n_______________________________";
		cout << "_________________________________________________________\n";

	}


};

