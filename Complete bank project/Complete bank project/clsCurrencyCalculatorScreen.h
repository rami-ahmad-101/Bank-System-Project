#pragma once
#include <iostream>
#include "clsScreen.h"


using namespace std;


class clsCurrencyCalculatorScreen : protected clsScreen
{


public:

	static void ShowCurrencyCalculatorScreen()
	{
		_DrawScreenHeader("Currency Calculator");

		cout << "Enter Currency Code [From]";
		string CurrencyCode = clsInputValidate::ReadString();
		clsCurrency CurrencyFrom = clsCurrency::FindByCode(CurrencyCode);
		while (CurrencyFrom.IsEmpty())
		{
			cout << "Empty Object try again ..\n";
			cout << "Enter Currency Code [From]";
			CurrencyCode = clsInputValidate::ReadString();
			CurrencyFrom = clsCurrency::FindByCode(CurrencyCode);
		}

		cout << "Enter Currency Code [To]";
		CurrencyCode = clsInputValidate::ReadString();
		clsCurrency CurrencyTo = clsCurrency::FindByCode(CurrencyCode);
		while (CurrencyFrom.IsEmpty())
		{
			cout << "Empty Object try again ..\n";
			cout << "Enter Currency Code [To]";
			 CurrencyCode = clsInputValidate::ReadString();
			CurrencyTo = clsCurrency::FindByCode(CurrencyCode);
		}

		int Amount = 0;
		cout << "Enter Amount to exchange :";
		cin >> Amount;

		if (clsString::UpperAllString(CurrencyTo.CurrencyCode()) == "USD")
		{
			cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << (Amount / CurrencyFrom.Rate()) << " USD" << endl;
		}
		else
		{
			cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << (Amount / CurrencyFrom.Rate()) << " USD" << endl;
			cout << Amount << " " << "USD" << " = " << (Amount / CurrencyFrom.Rate())/CurrencyTo.Rate() << " " <<CurrencyTo.CurrencyCode() << endl;

		}
	}

};

