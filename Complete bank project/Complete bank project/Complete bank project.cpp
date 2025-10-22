#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsLoginScreen.h"

using namespace std;

void ReadClientInfo(clsBankClient &Client)
{
	cout << "\nEnter FirstName :";
	Client.FirstName = clsInputValidate::ReadString();

	cout << "\nEnter LastName :";
	Client.LastName = clsInputValidate::ReadString();

	cout << "\nEnter Phone:";
	Client.Phone = clsInputValidate::ReadString();

	cout << "\nEnter Email :";
	Client.Email= clsInputValidate::ReadString();

	cout << "\nEnter PinCode :";
	Client.PinCode= clsInputValidate::ReadString();

	cout << "\nEnter Account Balance :";
	Client.AccountBalance = clsInputValidate::ReadDblNumber();

}

void PrintClientRecordLine(clsBankClient Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber();
	cout << "| " << left << setw(12) << Client.FirstName;
	cout << "| " << left << setw(9) << Client.Phone;
	cout << "| " << left << setw(20) << Client.Email;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(9) << Client.AccountBalance;
}

void PrintClientRecordBalanceLine(clsBankClient Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber();
	cout << "| " << left << setw(40) << Client.FirstName;
	cout << "| " << left << setw(12) << Client.AccountBalance;
}

void UpdateClient()
{
	string AccountNumber = "";
	cout << "\nPlease Enter Client AccountNumber :";
	AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount number is not found chose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	Client1.Print();

	cout << "\n\nUpdate Client Info :";
	cout << "\n_________________________\n";

	ReadClientInfo(Client1);
	clsBankClient::enSaveResults SaveResult;

	SaveResult = Client1.Save();

	switch (SaveResult)
	{
	case clsBankClient::enSaveResults::svSucceded:
	{
		cout << "\nAccount Updated Successfully \n";
		Client1.Print();
		break;
	}
	case clsBankClient::enSaveResults::svFaildEmptyObject:
	{
		cout << "\nError account was not saved because it's Empty";
		break;
	}
	}

}

void AddNewClient()
{
	string AccountNumber = "";

	cout << "\n Please Enter Account Number :";
	AccountNumber = clsInputValidate::ReadString();

	while (clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount Number is Already Used choose another one :";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

	ReadClientInfo(NewClient);
		
	clsBankClient::enSaveResults SaveResult;

	SaveResult = NewClient.Save();

	switch (SaveResult)
	{
	case  clsBankClient::enSaveResults::svSucceded:
	{
		cout << "\nAccount Added Successfully\n";
		NewClient.Print();
		break;
	}
	case clsBankClient::enSaveResults::svFaildEmptyObject:
	{
		cout << "\nError account was not saved because it's empty";
		break;
	}
	case clsBankClient::enSaveResults::svFailAccountNumberExists:
	{

		break;
	}
	default:
		break;
	}
}

void DeleteClient()
{
	string AccountNumber = "";
	cout << "\nPlease Enter Client AccountNumber :";
	AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount number is not found chose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	Client1.Print();

	cout << "\nAre you sure you want to delete this client Y/n?";

	char Answer = 'n';
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		if (Client1.Delete())
		{
			cout << "\nClient Deleted Successfully\n";
			Client1.Print();

		}
		else
		{
			cout << "\nError Client was not Deleted\n";
		}
	}

}

void ShowClientsList()
{
	vector <clsBankClient> vClients = clsBankClient::GetClientList();
	 
	cout << "\n\t\t\t\tClient List (" << vClients.size() << ") Clients";
	cout << "\n_________________________________________________";
	cout<<"_______________________________________\n\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(12) << "Client Name";
	cout << "| " << left << setw(9) << "Phone";
	cout << "| " << left << setw(20) << "Email";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(9) << "Balance";
	cout << "\n______________________________________________";
	cout<<"__________________________________________\n\n";

	if (vClients.size() == 0)
	{
		cout << "\t\t\t\tThere is no Clients to show!" << endl;
	}
	else
	{
		for (clsBankClient c : vClients)
		{
			PrintClientRecordLine(c);
			cout << endl;
		}
	}
	cout << "\n_______________________________";
	cout<<"_________________________________________________________\n";

}

void ShowTotalBalances()
{
	vector <clsBankClient> vClients = clsBankClient::GetClientList();
	cout << "\n\t\t\t\tBalances List (" << vClients.size() << ") Client";
	cout << "\n_________________________________________________";
	cout << "_______________________________________\n\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_________________________________________________";
	cout << "_______________________________________\n\n";

	long TotalBalances = 0;

	if (vClients.size() == 0)
	{
		cout << "\t\t\t\tThere is no Clients to show!" << endl;
	}
	else
	{
		for (clsBankClient c : vClients)
		{
			PrintClientRecordBalanceLine(c);
			cout << endl;
			TotalBalances += c.AccountBalance;
		}
	}
	cout << "\n_______________________________";
	cout << "_________________________________________________________\n";

	cout << "\t\t\tTotal Balances is " << TotalBalances << endl;
}

int main()
{
	
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
			break;
	}


	return 0;
}