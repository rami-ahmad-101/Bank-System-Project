#pragma once
#include <iostream>

#include "clsScreen.h"

#include "clsCurrencyListScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrency.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyMainScreen : protected clsScreen
{
	enum enCurrencyOption { eListCurrenies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyClaculator = 4,eMainMenu = 5 };

	static int _ReadCurrencyMenuOption()
	{
		cout << "\t\t\tChose what do you want to do ?[1/5]";
		return clsInputValidate::ReadIntNumberBetween(1, 5);
	}


	static void _GoBackToCurrencyMenu()
	{
		cout << "\npress any key to continue...";
		system("pause>0");
		system("cls");
		ShowCurrencyMenu();
	}

	static void _ShowListCurrencyScreen()
	{
		system("cls");
		clsCurrencyListScreen::ShowCurrencyList();
	}
	static void _ShowFindCurrencyScreen()
	{
		system("cls");
		clsFindCurrency::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateCurrencyScreen()
	{
		system("cls");
		clsUpdateCurrency::ShowUpdateRateScreen();
	}
	static void _ShowCurrencyCalculatorScreen()
	{
		system("cls");
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	

	static void _PerformCurrencyMenuScreen(enCurrencyOption CurrencyOption)
	{
		switch (CurrencyOption)
		{
		case clsCurrencyMainScreen::eListCurrenies:
		{
			_ShowListCurrencyScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case clsCurrencyMainScreen::eFindCurrency:
		{
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case clsCurrencyMainScreen::eUpdateRate:
		{
			_ShowUpdateCurrencyScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case clsCurrencyMainScreen::eCurrencyClaculator:
		{
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMenu();
			break;
		}
		case clsCurrencyMainScreen::eMainMenu:
		{
			
			break;
		}
		}

	}

public:

	static void ShowCurrencyMenu()
	{

		

		system("cls");

		_DrawScreenHeader("Currency Exchange");

		cout << "\t\t\t====================================\n";
		cout << "\t\t\t\t     Currency Exchange Menu\n";
		cout << "\t\t\t====================================\n";
		cout << "\t\t\t[1] List Currencies\n";
		cout << "\t\t\t[2] Find Currency\n";
		cout << "\t\t\t[3] Update Rate\n";
		cout << "\t\t\t[4] Currency Calculator\n";
		cout << "\t\t\t[5] Main Menu\n";
		cout << "\t\t\t====================================\n";

		_PerformCurrencyMenuScreen((enCurrencyOption)_ReadCurrencyMenuOption());
	}

};

