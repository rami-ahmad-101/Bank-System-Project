#pragma once
#include <iostream>

#include "clsScreen.h"

using namespace std;

class clsFindUserScreen : protected clsScreen
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

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("Find User Screen");

		string UserName = "";
		cout << "\nPlease Enter User Name:";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name is not found chose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		if (User.IsEmpty())
		{
			cout << "User not found!\n";
		}
		else
		{
			cout << "User Found !\n";
			Print(User);
		}
	}


};