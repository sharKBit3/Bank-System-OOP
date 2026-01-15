#pragma once

#include <iostream>
#include <iomanip>

#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainMenu.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"


using namespace std;

class clsListScreen : clsScreen{

private:

	static void _PrintClientRecordLine(clsBankClient Client)
	{

		cout << "| " << setw(15) << left << Client.AccountNumber;
		cout << "| " << setw(15) << left << Client.FullName();
		cout << "| " << setw(10) << left << Client.Password;
		cout << "| " << setw(25) << left << Client.Phone;
		cout << "| " << setw(25) << left << Client.Email;
		cout << "| " << setw(35) << left << Client.AccountBalance;


	}

public:

	static void ShowList() {


		if (!_CheckAccessRights(clsBankUser::enPermissions::_pClientList))
		{
			return;// this will exit the function and it will not continue
		}

		cout << BOLD << CYAN;
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		
		string Title = "\t\tClients List Screen\n";
		string Subtitle = "\t  (" + to_string(vClients.size()) + ") Client(s)\n";
		
		cout << BOLD << CYAN;
		
		_ScreenHeader(Title, Subtitle);

		cout << YELLOW << "\n__________________________________________________________________"
		     << "_____________________________________________________\n" << RESET << endl;

		cout << BOLD << WHITE;
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(15) << "Client Name";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(25) << "Phone";
		cout << "| " << left << setw(25) << "E-mail";
		cout << "| " << left << setw(35) << "Balance";
		cout << RESET << endl;

		cout << YELLOW << "__________________________________________________________________";
		cout << "_____________________________________________________\n" << RESET << endl;

		if (vClients.size() == 0)
			cout << RED << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient& Client : vClients)
			{

				_PrintClientRecordLine(Client);
				cout << endl;
			}
		cout << "\n__________________________________________________________________";
		cout << "_____________________________________________________\n" << endl;


	}










};
