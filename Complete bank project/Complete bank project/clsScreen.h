#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsUtil.h"
#include <iomanip>
#include <string>
#include "Global.h"
#include "clsDate.h"


using namespace std;



class clsScreen
{


protected:

	static void _DrawScreenHeader(string title,string subTitle = "")
	{
		cout << "\t\t\t------------------------------------\n";
		cout << "\t\t\t\t     " << title << endl;
		if (subTitle != "")
		{
			cout << "\t\t\t\t     " << subTitle << endl;
		}
		cout << "\t\t\t------------------------------------\n";

		cout << "\n\t\t\tUser : " << CurrentUser.UserName;
		cout << "\n\t\t\tData : " << clsDate::DateToString(clsDate()) << endl;
		
		cout << endl;
	}

	static bool CheckAccessRights(clsUser::enPermissions Permissions)
	{
		if (!CurrentUser.CheckAccessPermissions(Permissions))
		{
			_DrawScreenHeader("Access Denied\n\t\t\t\tContact Your Admin");
			return false;
		}
		else
		{
			return true;
		}
	}

};

