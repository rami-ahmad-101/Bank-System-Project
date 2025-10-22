#pragma once
#include <iostream>

#include "clsScreen.h"

#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionScreen : protected clsScreen
{
	enum enTransactionOption {eDeposit = 1,eWithdraw = 2,eTotalBalances = 3,eTransfer = 4,eTransactionRecord = 5 ,eMainMenu = 6};

	static int _ReadTransactionMenuOption()
	{
		cout << "\t\t\tChose what do you want to do ?[1/6]";
		return clsInputValidate::ReadIntNumberBetween(1, 6);
	}


	static void _GoBackToTransactionMenu()
	{
		cout << "\npress any key to continue...";
		system("pause>0");
		system("cls");
		ShowTransactionMenu();
	}

	static void _ShowDepositScreen()
	{
		system("cls");
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen()
	{
		system("cls");
		clsWithdrawScreen::ShowDepositScreen();
	
	}
	static void _ShowTotalBalancesScreen()
	{
		system("cls");
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	
	}
	static void _ShowTransferScreen()
	{
		system("cls");
		clsTransferScreen::ShowTransactionScreen();
	}
	static void _ShowTransferLogScreen()
	{
		system("cls");
		clsTransferLogScreen::ShowLoginRegisterScreen();
	}

	static void _PerformTransactionMenuScreen(enTransactionOption TransactionOption)
	{
		switch (TransactionOption)
		{
		case clsTransactionScreen::eDeposit:
		{
			_ShowDepositScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case clsTransactionScreen::eWithdraw:
		{
			_ShowWithdrawScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case clsTransactionScreen::eTotalBalances:
		{
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenu();
			break;
		}
		case clsTransactionScreen::eTransactionRecord:
		{
			_ShowTransferLogScreen();
			_GoBackToTransactionMenu();
		}
		case clsTransactionScreen::eTransfer:
		{
			_ShowTransferScreen();
			_GoBackToTransactionMenu();
		}
		case clsTransactionScreen::eMainMenu:
		{
			break;
		}
		default:
			break;
		}
	}

public:

	static void ShowTransactionMenu()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return;
		}
		system("cls");

		_DrawScreenHeader("Transaction Screen");

		cout << "\t\t\t====================================\n";
		cout << "\t\t\t\t     Transaction Menu\n";
		cout << "\t\t\t====================================\n";
		cout << "\t\t\t[1] Deposit\n";
		cout << "\t\t\t[2] Withdraw\n";
		cout << "\t\t\t[3] Total Balances\n";
		cout << "\t\t\t[4] Transfer\n";
		cout << "\t\t\t[5] Transfer Record \n";
		cout << "\t\t\t[6] Main Menu\n";
		cout << "\t\t\t====================================\n";

		_PerformTransactionMenuScreen((enTransactionOption)_ReadTransactionMenuOption());
	}

};

