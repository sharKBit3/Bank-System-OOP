#pragma once
#include <iostream>

#include "clsScreen.h"
#include "clsBankClient.h"

class clsFindClientScreen : protected clsScreen {


private:

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


	
	static void ShowFindClientScreen()
	{

		if (!_CheckAccessRights(clsBankUser::enPermissions::_pClientList))
		{
			return;// this will exit the function and it will not continue
		}

		clsScreen::_ScreenHeader("\t\t  Find Client Screen\n");

		string AccountNumber;
		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadS();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not exist, choose another one: ";
			AccountNumber = clsInputValidate::ReadS();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient Was not Found :-(\n";
		}

		_PrintClientInfo(Client);

	}










};