#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsCurrencyListScreen : protected clsScreen
{
	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << "| " << left << setw(30) << Currency.Country();
		cout << "| " << left << setw(5) << Currency.CurrencyCode();
		cout << "| " << left << setw(30) << Currency.CurrencyName();
		cout << "| " << left << setw(8) << Currency.Rate();
	}


public:

	static void ShowCurrencyList()
	{

		vector <clsCurrency> vector = clsCurrency::GetCurrenciesList();

		string Title = "Currency List";
		string SubTitle = "(" + to_string(vector.size()) + ") Currencies";
		_DrawScreenHeader(Title, SubTitle);

		cout << "\n_________________________________________________";
		cout << "_______________________________________\n\n";
		cout << "| " << left << setw(30) << "Contry";
		cout << "| " << left << setw(5) << "Code";
		cout << "| " << left << setw(30) << "Name";
		cout << "| " << left << setw(8) << "Rate(1$)";
		cout << "\n______________________________________________";
		cout << "__________________________________________\n\n";

		if (vector.size() == 0)
		{
			cout << "\t\t\t\tThere is no Currencies to show!" << endl;
		}
		else
		{
			for (clsCurrency c : vector)
			{
				_PrintCurrencyRecordLine(c);
				cout << endl;
			}
		}
		cout << "\n_______________________________";
		cout << "_________________________________________________________\n";

	}


};

