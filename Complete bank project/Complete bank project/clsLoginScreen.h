#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include <fstream>
using namespace std;

class clsLoginScreen:protected clsScreen
{


	static bool _Login()
	{
		bool LoginFaild = false;

		short FaildLoginCount = 0;

		string UserName, Password;

		do
		{
			if (LoginFaild)
			{ 
				FaildLoginCount++;
				cout << "\nInvalid User Name / Password\n";
				cout << "You have " << 3 - FaildLoginCount << " Trials to login\n\n";
			}

			if (FaildLoginCount == 3)
			{
				cout << "\n You are locked after 3 faild trails \n\n";
				return false;
			}

			cout << "Enter User Name?";
			cin >> UserName;

			cout << "Enter Password?";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);
		CurrentUser.SaveLoginInfoToFile();

		clsMainScreen::ShowMainMenue();
		return true;
	}


public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");

		return _Login();


	}

};

