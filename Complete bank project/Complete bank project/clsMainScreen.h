#pragma once

#include <iostream>
#include "clsScreen.h"

#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyMainScreen.h"


using namespace std;


class clsMainScreen : protected clsScreen
{

	enum enMainMenuOption {
		eClientList = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionMenu = 6,
		eManageUsers = 7, eLoginRegister = 8,eCurrency = 9, eExit = 10
	};

	static int _ReadMainMenuOption() 
	{
		cout << "\t\t\tChose what do you want to do ?[1,10]";
		return clsInputValidate::ReadIntNumberBetween(1, 10);
	}
	
	static void _GoBackToMainMenu()
	{
		cout << "\npress any key to continue...";
		system("pause>0");
		system("cls");
		ShowMainMenue();
	}

	static void _PerformMainMenuScreen(enMainMenuOption option)
	{
		switch (option)
		{
		case clsMainScreen::eClientList:
		{
			_ShowClientListScreen();
			_GoBackToMainMenu();
			break;
		}
		case clsMainScreen::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case clsMainScreen::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case clsMainScreen::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case clsMainScreen::eFindClient:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToMainMenu();
			break;
		}
		case clsMainScreen::eShowTransactionMenu:
		{
			system("cls");
			_ShowTransactionScreen();
			_GoBackToMainMenu();
			break;
		}
		case clsMainScreen::eManageUsers:
		{
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::eCurrency:
		{
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenu();
		}
		case clsMainScreen::eExit:
		{
			system("cls");
			_Logout();
			break;
		}
		default:
			break;
		}
	}

	static void _ShowClientListScreen()
	{
		system("cls");
		clsClientListScreen::ShowClientsList();
		
	}
	static void _ShowAddNewClientsScreen()
	{
		system("cls");

		clsAddNewClientScreen::ShowAddNewClientScreen();
	
	} 
	static void _ShowDeleteClientScreen()
	{
		system("cls");

		clsDeleteClientScreen::ShowDeleteClientScreen();

	}
	static void _ShowUpdateClientScreen()
	{
		system("cls");
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	static void _ShowFindUserScreen()
	{
		system("cls");
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowTransactionScreen()
	{
		system("cls");
		clsTransactionScreen::ShowTransactionMenu();
	}
	static void _ShowManageUsersScreen()
	{
		system("cls");
		clsManageUsersScreen::ShowManageUsersMenu();
	
	}
	static void _ShowLoginRegisterScreen()
	{
		system("cls");
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
		
	}
	static void _ShowCurrencyExchangeScreen()
	{
		system("cls");
		clsCurrencyMainScreen::ShowCurrencyMenu();
	}
	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		//clsLoginScreen::ShowLoginScreen();
	}

public:
	 
	static void ShowMainMenue()
	{
		system("cls");

		_DrawScreenHeader("Main Screen");
		
		cout << "\t\t\t====================================\n";
		cout << "\t\t\t\t     Main Screen\n";
		cout << "\t\t\t====================================\n";
		cout << "\t\t\t[1] Show Client List\n";
		cout << "\t\t\t[2] Add New Client\n";
		cout << "\t\t\t[3] Delete Client\n";
		cout << "\t\t\t[4] Update Client\n";
		cout << "\t\t\t[5] Find Client\n";
		cout << "\t\t\t[6] TransAction\n";
		cout << "\t\t\t[7] Manage Users\n";
		cout << "\t\t\t[8] Login Register\n";
		cout << "\t\t\t[9] Currency Exchange\n";
		cout << "\t\t\t[10] Logout\n";
		cout << "\t\t\t====================================\n";

		_PerformMainMenuScreen((enMainMenuOption)_ReadMainMenuOption());

	}

};

