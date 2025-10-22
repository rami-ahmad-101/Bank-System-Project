#pragma once
#include <iostream>
#include "clsScreen.h"

using namespace std;


class clsUpdateCurrency : protected clsScreen
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


public:


	static void ShowUpdateRateScreen()
	{
		_DrawScreenHeader("Update Currency Code");

		cout << "Enter Currency Code :";
		string CurrencyCode;
		cin >> CurrencyCode;

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "Error .. try again\n";
			cin >> CurrencyCode;
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrencyRecord(Currency);

		char answer = 'n';
		cout << "Are you sure you want to update this rate of this currency [Y/N]:";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			cout << "Update Currency Rate :\n";
			cout << "_________________________\n";
			cout << "Enter New Rate :";
			float NewRate = 0;
			cin >> NewRate;
			Currency.UpdateRate(NewRate);
			cout << "\nCrrency Rate Updated Successfully\n";
			_PrintCurrencyRecord(Currency);
			
		}
		else
		{
			cout << "Operation Canceled !" << endl;
		}
	
	}


};

