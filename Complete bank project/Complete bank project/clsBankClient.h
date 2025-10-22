#pragma once

#include <iostream>
#include "clsString.h"
#include "clsperson.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class clsBankClient : public clsPerson
{
	enum enMode { EmptyMode = 0,UpdateMode = 1 ,AddNewMode = 2};

	struct stTransferLogRecord;

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	bool _MarkForDelete = false;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsBankClient> _LoadClientDataFromFile()
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				vClients.push_back(Client);

			}
			MyFile.close();
			return vClients;
		}
		
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";

		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClient)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out);

		string DataLine;
		if (MyFile.is_open())
		{
			for (clsBankClient c : vClient)
			{
				if(!c._MarkForDelete)
				{
					DataLine = _ConvertClientObjectToLine(c);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> _vClient;
		_vClient = _LoadClientDataFromFile();
		for (clsBankClient& c : _vClient)
		{
			if (c.AccountNumber() == AccountNumber())
			{
				c = *this;
				break;
			}

		}
		_SaveClientsDataToFile(_vClient);
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	string _PrepareTransferInfoRecord(float Amount, clsBankClient ClientTo, string UserName, string Seperator = "#//#")
	{
		string TransferHistory;
		TransferHistory = clsDate::GetSystemDateTimeString() + Seperator;
		TransferHistory += AccountNumber() + Seperator;
		TransferHistory += ClientTo.AccountNumber() + Seperator;
		TransferHistory += to_string(Amount) + Seperator;
		TransferHistory += to_string(AccountBalance) + Seperator;
		TransferHistory += to_string(ClientTo.AccountBalance) + Seperator;
		TransferHistory += UserName;

		return TransferHistory;
	}

	void _SaveTransferInfoToFile(float Amount ,clsBankClient ClientTo , string UserName)
	{
		string TransferInfo = _PrepareTransferInfoRecord(Amount , ClientTo , UserName);
		fstream myfile;
		myfile.open("TransferLog.txt", ios::out | ios::app);

		if (myfile.is_open())
		{
			myfile << TransferInfo << endl;
		}
		myfile.close();
	}


	static stTransferLogRecord _ConvertTransferRegisterLinetoUserObject(string Line, string Seperator = "#//#")
	{
		stTransferLogRecord TransferLogRecord;
		vector <string> vRecord;
		vRecord = clsString::Split(Line, Seperator);


		TransferLogRecord.DateAndTime = vRecord[0];
		TransferLogRecord.FromAccNumber = vRecord[1];
		TransferLogRecord.ToAccNumber = vRecord[2];
		TransferLogRecord.Amount = stoi(vRecord[3]);
		TransferLogRecord.FromAccBalacnce = stoi(vRecord[4]);
		TransferLogRecord.ToAccBalance = stoi(vRecord[5]);
		TransferLogRecord.UserName = (vRecord[6]);

		return TransferLogRecord;
	}


public:
	
	clsBankClient() {}

	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	struct stTransferLogRecord
	{
		string DateAndTime;
		string FromAccNumber;
		string ToAccNumber;
		float Amount;
		float FromAccBalacnce;
		float ToAccBalance;
		string UserName;
	};

	static vector <stTransferLogRecord> GetTransferRegisterRecord()
	{
		vector <stTransferLogRecord> vRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			stTransferLogRecord TransferLogRecord;

			while (getline(MyFile, Line))
			{
				TransferLogRecord = _ConvertTransferRegisterLinetoUserObject(Line);
				vRecord.push_back(TransferLogRecord);

			}
			MyFile.close();
			return vRecord;
		}
	}


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n_________________________";
		cout << "\nFirst Name   :" << FirstName;
		cout << "\nLast Name    :" << LastName;
		cout << "\Full Name   :" << FirstName << " " << LastName;
		cout << "\nEmail        :" << Email;
		cout << "\nPhone        :" << Phone;
		cout << "\nAcc Number   :" << AccountNumber();
		cout << "\nPassword     :" << PinCode;
		cout << "\nAcc Balance  :" << AccountBalance;
		cout << "\n_________________________\n";
	 }

	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients;
	
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();

			return _GetEmptyClientObject();
		}
	}

	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read only Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();

		}
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		if (Client.IsEmpty())
			return false;
		else
			return true;
	}

	enum enSaveResults {svFaildEmptyObject = 0 , svSucceded = 1 , svFailAccountNumberExists = 2};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;

		}
		case enMode::UpdateMode:
		{
			_Update();

			return enSaveResults::svSucceded;

			break;
		}
		case enMode::AddNewMode:
		{

			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFailAccountNumberExists;
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

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> _vClient;
		_vClient = _LoadClientDataFromFile();

		for (clsBankClient& c : _vClient)
		{
			if (c.AccountNumber() == _AccountNumber)
			{
				c._MarkForDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(_vClient);

		*this = _GetEmptyClientObject();
		return true;
	}

	static 	vector
		<clsBankClient> GetClientList()
	{
		return _LoadClientDataFromFile();
	}

	void Deposit(float DepositAmount)
	{
		_AccountBalance += DepositAmount;
		Save();
	}

	bool Withdraw(float Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool Transfer(float Amount,clsBankClient & ClientTo , string UserName)
	{
		if (Amount < AccountBalance)
		{
			ClientTo.Deposit(Amount);
			this->Withdraw(Amount);
			_SaveTransferInfoToFile(Amount, ClientTo, UserName);
			return true;
		}
		else
		{
			return false;
		}
	}

	static float GetTotalBalances()
	{
		vector
			<clsBankClient> vClients = GetClientList();
		float TotalBalances = 0;


		for (clsBankClient c : vClients)
		{
			TotalBalances += c.AccountBalance;
		}
		return TotalBalances;
	}


};