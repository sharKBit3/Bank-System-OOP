#pragma once

#include <iostream>


#include "clsBankClient.h"
#include "clsScreen.h"


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"



class clsTotalBalance : protected clsScreen {


private:

	static void _PrintClientRecordBalanceLine(clsBankClient Client) {

		cout << setw(8) << left << "" << "| " << left << setw(23) << Client.AccountNumber;
		cout << "|" << left << setw(39) << Client.FullName();
		cout << "|" << left << setw(25) << Client.AccountBalance;
	}

public:


	static void ShowTotalBalance() {

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t\t Clients Balance Screen\n";
		string Subtitle = "\t  (" + to_string(vClients.size()) + ") Client(s)\n";

		cout << BOLD << CYAN
			<< "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s)."
			<< RESET;

		cout << YELLOW
			<< setw(8) << left << "" << "\n\t===================================================="
		    << "====================================================\n\n"
			<< RESET << endl;

		cout << BOLD << WHITE;
		cout << setw(8) << left << "" << "| " << left << setw(23) << "Account Number";
		cout << "| " << left << setw(38) << "Client Name";
		cout << "| " << left << setw(25) << "Total Balance";
		cout << RESET << endl;

		cout << YELLOW
			 << setw(8) << left << "" << "\n\t===================================================="
		     << "====================================================\n\n"
			 << RESET << endl;


		double TotalBalances = clsBankClient::GetClientBalance();

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}

		cout << YELLOW
			<< setw(8) << left << "" << "\n\t===================================================="
		    << "====================================================\n\n"
			<< RESET << endl;

		cout << BOLD << GREEN
			<< "Total Balances = " << TotalBalances
			<< RESET << endl;

		cout << BOLD << CYAN << "Total Balances = " << clsUtility::NumberToText(TotalBalances) << "!" << RESET << endl;


	}





















};