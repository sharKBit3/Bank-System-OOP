#pragma once


#include <iostream>


#include "clsScreen.h"
#include "clsTransactionsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDepositScreen : protected clsScreen {




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

	static string _ReadAccountNumber(){

		string AccountNumber;
		cout << "Please, Enter your account number: ";
		cin >> AccountNumber;
		return AccountNumber;
	}

public:

	static void ShowDepositScreen() {

		clsScreen::_ScreenHeader("\t\t   Deposite Screen\n");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Client with ["<< AccountNumber << "] wasn't found!, try again";
			cin >> AccountNumber;
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientInfo(Client);


		double Amount = 0;
		cout << "Please, enter deposite amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this operation? <[Y] / [N]>:  ";
		cin >> Answer;
		
		if (Answer == 'y' || Answer == 'Y') {
			Client.Deposit(Amount);
			cout << "\nOpertion has been Successfully!\n";
			cout << "\n->Your Balance Now is : " << Client.AccountBalance;
		}
		else {
			cout << "\nOperation was incompleted";
		}


	}














};