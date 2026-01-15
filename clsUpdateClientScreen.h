#pragma once

#include <iostream>

#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;


class clsUpdateClientScreen : protected clsScreen{


private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadS();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadS();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadS();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadS();

		cout << "\nEnter PinCode: ";
		Client.Password = clsInputValidate::ReadS();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();
	}

	static void _PrintClientInfo(clsBankClient& Client) {
		cout << "======================\n";
		cout << "Client Info: \n";
		cout << "======================\n";
		cout << "\nFirstName: " << Client.FirstName;
		cout << "\nLastName : " << Client.LastName;
		cout << "\nFull Name: " << Client.FullName();
		cout << "\nEmail    : " << Client.Email;
		cout << "\nPhone    : " << Client.Phone;
		cout << "\nAccount Number: " << Client.AccountNumber;
		cout << "\nPassword: " << Client.Password;
		cout << "\nAccount Balance: " << Client.AccountBalance;
		cout << "\n\n=======================\n";
	}

public:

	static void ShowUpdateClient()
	{
		if (!_CheckAccessRights(clsBankUser::enPermissions::_pClientList))
		{
			return;// this will exit the function and it will not continue
		} 

		clsScreen::_ScreenHeader("\t\t Update Client Screen\n");

		string AccountNumber = "";

		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadS();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not exist, choose another one: ";
			AccountNumber = clsInputValidate::ReadS();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientInfo(Client);

		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";
		_ReadClientInfo(Client);


		clsBankClient::enSaveResults SaveResult;

		SaveResult = Client.Save();

		switch (SaveResult)
		{

		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";

		}

		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Updated Successfully :-)\n";
			_PrintClientInfo(Client);
		}

		}
	}




















};
