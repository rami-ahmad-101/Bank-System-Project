#pragma once
#include <iostream>
#include <string >
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsCurrency
{
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static vector <clsCurrency> _LoadCurrencysDataFromFile()
	{

		vector <clsCurrency> vCurrency;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency= _ConvertLineToCurrencyObject(Line);
				vCurrency.push_back(Currency);

			}
			MyFile.close();
			return vCurrency;
		}

	}

	void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrency)
	{
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::out);

		string DataLine;
		if (MyFile.is_open())
		{
			for (clsCurrency c : vCurrency)
			{
				
				DataLine = _ConvertCurrenyObjectToLine(c);
				MyFile << DataLine << endl;
				
			}
			MyFile.close();
		}
	
	}

	static clsCurrency _ConvertLineToCurrencyObject(string Line , string Seperator = "#//#")
	{
		vector <string> vCurrency;
		vCurrency = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2],
			stof(vCurrency[3]));

	}

	static string _ConvertCurrenyObjectToLine(clsCurrency c, string Seperator = "#//#")
	{
		string stCurrencyRecord = "";

		stCurrencyRecord += c.Country() + Seperator;
		stCurrencyRecord += c.CurrencyCode() + Seperator;
		stCurrencyRecord += c.CurrencyName() + Seperator;
		stCurrencyRecord += to_string(c.Rate());

		return stCurrencyRecord;

	}

	void _Update()
	{
		vector <clsCurrency> _vCurrency;
		_vCurrency = _LoadCurrencysDataFromFile();
		for (clsCurrency& C : _vCurrency)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(_vCurrency);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	float Rate()
	{
		return _Rate;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}
		}
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}
		}
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{

		return _LoadCurrencysDataFromFile();

	}


};