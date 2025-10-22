#pragma once
#include <iostream>
#include "clsString.h"
#include "clsperson.h"
#include <fstream>
#include <vector>
#include <string>
#include "clsUtil.h"

using namespace std;

class clsUser : public clsPerson
{

	enum enMode {EmptyMode = 0,UpdateMode = 1,AddNewMode = 2};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;

	bool _MarkedForDelete = false;

	
	struct stLoginRegisterRecord;
	

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", -1);
	}

	static vector <clsUser> _LoadUserDataFromFile()
	{
		vector <clsUser> vUser;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				vUser.push_back(User);

			}
			MyFile.close();
			return vUser;
		}

	}

	static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
	{
		vector <string> vUserData;
		vUserData = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[3],
			vUserData[2], vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));

	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string stUserRecord = "";

		stUserRecord += User.FirstName + Seperator;
		stUserRecord += User.LastName + Seperator;
		stUserRecord += User.Email + Seperator;
		stUserRecord += User.Phone + Seperator;
		stUserRecord += User.UserName + Seperator;
		stUserRecord += clsUtil::EncryptText(User.Password) + Seperator;
		stUserRecord += to_string(User.Permissions);

		return stUserRecord;

	}

	static void _SaveUsersDataToFile(vector <clsUser> vClient)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::out);

		string DataLine;
		if (MyFile.is_open())
		{
			for (clsUser c : vClient)
			{
				if (!c._MarkedForDelete)
				{
					DataLine = _ConvertUserObjectToLine(c);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsUser>_vUser;
		_vUser = _LoadUserDataFromFile();
		for (clsUser& c : _vUser)
		{
			if (c.UserName == UserName)
			{
				c = *this;
				break;
			}

		}
		_SaveUsersDataToFile(_vUser);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	string _PrepareLogInRecord(string Seperator = "#//#")
	{
		string LoginHistory;
		LoginHistory = clsDate::GetSystemDateTimeString() + Seperator;
		LoginHistory += UserName + Seperator;
		LoginHistory += clsUtil::EncryptText(Password) + Seperator;
		LoginHistory += to_string(Permissions);

		return LoginHistory;

	}

	static stLoginRegisterRecord _ConvertLoginRegisterLinetoUserObject(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterDataLine;
		vector <string> vRecord;
		vRecord = clsString::Split(Line, Seperator);

		
		LoginRegisterDataLine.DateAndTime = vRecord[0];
		LoginRegisterDataLine.UserName = vRecord[1];
		LoginRegisterDataLine.Password= vRecord[2];
		LoginRegisterDataLine.Permissions = stoi(vRecord[3]);

		return LoginRegisterDataLine;
	}



public:

	static vector <stLoginRegisterRecord> GetLoginRegisterRecord()
	{
		vector <stLoginRegisterRecord> vRecord;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			stLoginRegisterRecord LoginRegisterRecord;

			while (getline(MyFile, Line))
			{
				LoginRegisterRecord = _ConvertLoginRegisterLinetoUserObject(Line);
				vRecord.push_back(LoginRegisterRecord);

			}
			MyFile.close();
			return vRecord;
		}
	}
	
	 struct stLoginRegisterRecord
	{
		string DateAndTime;
		string UserName;
		string Password;
		int Permissions;
	};

	enum enPermissions {eAll = -1,pListClients = 1,pAddNewClient = 2 , pDeleteClient = 4,
	pUpdateClient = 8 , pFindClient = 16 , pTransactions = 32 , pManageUsers = 64 , pLoginRegister = 128};

	clsUser(enMode Mode, string FirstName, string LastName,
		string Phone,string Email,  string UserName, string Password,
		int Permissions) :clsPerson(FirstName, LastName, Phone, Email)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	string GetUserName()
	{
		return _UserName;
	}
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName))string UserName;

	string GetPassword()
	{
		return _Password;
	}
	void SetPassword(string Password)
	{
		_Password = Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword))string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	static clsUser Find(string UserName)
	{
		vector <clsUser> vUser;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
				vUser.push_back(User);
			}
			MyFile.close();

			return _GetEmptyUserObject();
		}
	}

	static clsUser Find(string UserName,string Password)
	{
		vector <clsUser> vUser;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if ((User.UserName == UserName) && (User.Password == Password))
				{
					MyFile.close();
					return User;
				}
				vUser.push_back(User);
			}
			MyFile.close();

			return _GetEmptyUserObject();
		}
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		if (User.IsEmpty())
			return false;
		else
			return true;
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceded = 1, svFailUserExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFailUserExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceded;
			}

			break;
		}
		case enMode::UpdateMode:
		{
			_Update();

			return enSaveResults::svSucceded;

			break;
		}
		case enMode::AddNewMode:
		{

			if (clsUser::IsUserExist(UserName))
			{
				return enSaveResults::svFailUserExists;
			}
			else
			{
				_AddNew();
				return enSaveResults::svSucceded;
			}
			break;
		}

		}
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", -1);
	}

	bool Delete()
	{
		vector <clsUser> _vUser;
		_vUser = _LoadUserDataFromFile();

		for (clsUser& c : _vUser)
		{
			if (c.UserName == UserName)
			{
				c._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(_vUser);

		*this = _GetEmptyUserObject();
		return true;
	}

	static vector <clsUser> GetClientList()
	{
		return _LoadUserDataFromFile();
	}

	static vector <clsUser> GetUserList()
	{
		return _LoadUserDataFromFile();
	}

	bool CheckAccessPermissions(enPermissions Permissions)
	{
		if (Permissions == enPermissions::eAll)
			return true;
		if ((Permissions & this->Permissions) == Permissions)
			return true;
		else
			return false;
	}

	void SaveLoginInfoToFile()
	{
		string LoginHistory = _PrepareLogInRecord();
		fstream myfile;
		myfile.open("LoginRegister.txt", ios::out | ios::app);

		if (myfile.is_open())
		{
			myfile << LoginHistory << endl;
		}
		myfile.close();
	}

	

};

