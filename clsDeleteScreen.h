#pragma once
#include <iostream>

#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;


class clsDeleteScreen  : protected clsScreen{


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




	static void ShowDeleteClientByAccountNumber() {

		if (!_CheckAccessRights(clsBankUser::enPermissions::_pClientList))
		{
			return;// this will exit the function and it will not continue
		}

		clsScreen::_ScreenHeader("\t\t Delete Client Screen\n");

		string AccountNumber = " ";

		cout << "Please, enter Account Number: ";
		AccountNumber = clsInputValidate::ReadS();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "<Error> account number wasn't found! choose another:  ";
			AccountNumber = clsInputValidate::ReadS();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientInfo(Client);


		char Answer = 'n';
		cout << "Are you sure you want to delete this account? Press <[Y] / [N]>  :  ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {

			if (Client.Delete()) {

				cout << "\nAccount has been deleted successfully\n";
				_PrintClientInfo(Client);
			}
			else {
				cout << "\n<Error> Account still exist..\n";

			}
		}
		else {
			cout << "Exist...";
		}



	}














};