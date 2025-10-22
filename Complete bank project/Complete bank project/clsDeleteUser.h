#pragma once
#include <iostream>
#include "clsScreen.h"
using namespace std;


class clsDeleteUser:protected clsScreen
{

	static void Print(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n_________________________";
		cout << "\nUser Name      :" << User.UserName;
		cout << "\nFirst Name     :" << User.FirstName;
		cout << "\nLast Name      :" << User.LastName;
		cout << "\nFull Name      :" << User.FirstName << " " << User.LastName;
		cout << "\nEmail          :" << User.Email;
		cout << "\nPhone          :" << User.Phone;
		cout << "\nPassword       :" << User.Password;
		cout << "\nPermissions    :" << User.Permissions;
		cout << "\n_________________________\n";
	}


public:

	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("Delete Screen");

		string UserName = "";
		cout << "\nPlease Enter User Name:";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name is not found chose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		Print(User);

		cout << "\nAre you sure you want to delete this User [Y/N]?";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully\n";
				Print(User);

			}
			else
			{
				cout << "\nError User was not Deleted\n";
			}
		}

	}



};