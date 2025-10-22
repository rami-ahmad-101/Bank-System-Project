#pragma once

#include <iostream>
#include "clsScreen.h"

using namespace std;

class clsFindCurrency : protected clsScreen
{
	
	static void _PrintCurrencyRecord(clsCurrency Currency)
	{
		cout << "\nCurrency Card :\n";
		cout << "_________________________________\n";
		cout << "\nCountry    :" << Currency.Country();
		cout << "\nCode       :" << Currency.CurrencyCode();
		cout << "\nName       :" << Currency.CurrencyName();
		cout << "\nRate (1$)  :" << Currency.Rate();
		cout << "\n_________________________________\n";

	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found ! \n";
			_PrintCurrencyRecord(Currency);
		}
		else
		{
			cout << "\nCurrency was not Found\n";
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");

		cout << "\nFind By : [1] Code or [2] Country ?\n";
		short Answer = 1;
		Answer = clsInputValidate::ReadIntNumberBetween(1, 2);

		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease Enter CurrencyCode .\n";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			string Country;
			cout << "\nPlease Enter Country .\n";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}
	}

};

