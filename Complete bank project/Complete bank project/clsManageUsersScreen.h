#pragma once

#include <iostream>
#include "clsScreen.h"

#include "clsListUserScreen.h"
#include "clsAddNewUser.h"
#include "clsDeleteUser.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{
	enum enManageUsersOptions{eListUsers = 1,eAddNewUsers = 2,eDeleteUsers = 3,eUpdateUsers = 4,
	eFindUsers = 5 ,eMainMenu = 6 };

	static int _ReadManageUsersOption()
	{
		cout << "\t\t\tChose what do you want to do ?";
		return clsInputValidate::ReadIntNumberBetween(1, 6);
	}

	static void _GoBackToManageUsersScreen()
	{
		cout << "\npress any key to continue...";
		system("pause>0");
		system("cls");
		ShowManageUsersMenu();
	}


	static void ShowListUserScreen()
	{
		system("cls");
		clsListUserScreen::ShowListUser();
	}
	static void ShowAddNewUserScreen()
	{
		system("cls");
		clsAddNewUser::ShowAddNewUserScreen();
	}
	static void ShowDeleteUserScreen()
	{
		system("cls");
	
		clsDeleteUser::ShowDeleteUserScreen();

	}
	static void ShowUpdateUserScreen()
	{
		system("cls");
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void ShowFindUserScreen()
	{
		system("cls");
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersScreen(enManageUsersOptions ManageUsersOptions)
	{
		switch (ManageUsersOptions)
		{
		case clsManageUsersScreen::eListUsers:
		{
			ShowListUserScreen();
			_GoBackToManageUsersScreen();
			break;
		}
		case clsManageUsersScreen::eAddNewUsers:
		{
			ShowAddNewUserScreen();
			_GoBackToManageUsersScreen();
			break;
		}
		case clsManageUsersScreen::eDeleteUsers:
		{
			ShowDeleteUserScreen();
			_GoBackToManageUsersScreen();
			break;
		}
		case clsManageUsersScreen::eUpdateUsers:
		{
			ShowUpdateUserScreen();
			_GoBackToManageUsersScreen();
			break;
		}
		case clsManageUsersScreen::eFindUsers:
		{
			ShowFindUserScreen();
			_GoBackToManageUsersScreen();
			break;
		}
		case clsManageUsersScreen::eMainMenu:
		{
			break;
		}
		}
	}

public:

	static void ShowManageUsersMenu()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		system("cls");

		_DrawScreenHeader("Manage Users Screen");

		cout << "\t\t\t====================================\n";
		cout << "\t\t\t\t     Manage Users Menu\n";
		cout << "\t\t\t====================================\n";
		cout << "\t\t\t[1] List Users\n";
		cout << "\t\t\t[2] Add New User\n";
		cout << "\t\t\t[3] Delete Users\n";
		cout << "\t\t\t[4] Update Users\n";
		cout << "\t\t\t[5] Find Users\n";
		cout << "\t\t\t[6] Main Menu\n";
		cout << "\t\t\t====================================\n";

		_PerformManageUsersScreen((enManageUsersOptions)_ReadManageUsersOption());
	}

};