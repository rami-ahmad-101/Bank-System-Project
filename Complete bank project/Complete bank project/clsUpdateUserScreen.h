#pragma once
#include <iostream>
#include "clsScreen.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{


	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName :";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName :";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Phone:";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Email :";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter PinCode :";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions :";
		User.Permissions = _ReadPermissionsToSet();


	}

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

	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'n';

		cout << "\nDo you want to give full acess ? [Y/N]";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to :\n";

		cout << "\nShow Client List ? [Y/N]";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}


		cout << "\nAdd New User ? [Y/N]";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? [Y/N]";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}


		cout << "\nUpdate Client? [Y/N]";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClient;
		}


		cout << "\nFind Client? [Y/N]";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}


		cout << "\nTransaction ? [Y/N]";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}


		cout << "\nManage User? [Y/N]";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}


		cout << "\nLogin Register ? [Y/N]";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pLoginRegister;
		}
		return Permissions;
	}


public:

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("Update Screen");

		string UserName = "";
		cout << "\nPlease Enter User Name :";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nAccount number is not found chose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		Print(User);

		char Answer = 'n';
		cin >> Answer;
		if(Answer == 'Y'||Answer == 'y')
		{
			cout << "\n\nUpdate User Info :";
			cout << "\n_________________________\n";

			_ReadUserInfo(User);
			clsUser::enSaveResults SaveResult;

			SaveResult = User.Save();

			switch (SaveResult)
			{
			case clsUser::enSaveResults::svSucceded:
			{
				cout << "\nUser Updated Successfully \n";
				Print(User);
				break;
			}
			case clsUser::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError User was not saved because it's Empty";
				break;
			}
			}
		}
		else
		{
			cout << "Operation Canceled .. \n";
		}


	}


};