#pragma once

#include <iostream>

#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;


class clsAddNewClientScreen : protected clsScreen{


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


	static void AddNewClient()
	{

		if (!_CheckAccessRights(clsBankUser::enPermissions::_pClientList))
		{
			return;// this will exit the function and it will not continue
		}


		clsScreen::_ScreenHeader("\t\t Add New Client Screen\n");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadS();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Already Used, Choose another one: ";
			AccountNumber = clsInputValidate::ReadS();
		}


		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{

		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Addeded Successfully :-)\n";
			_PrintClientInfo(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;

		}
		}


	}



















};