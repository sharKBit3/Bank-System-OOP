#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainMenu.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTransferScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionsScreen : protected clsScreen
{


private:

	enum _enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2,  eShowTransferScreen = 3, eShowTransferLog = 4, eShowTotalBalance = 5, eShowMainMenu = 6 };

	
	
	static short _ReadTransactionsMenu() {

		cout << "\t\t\t->Please, enter a number to choose an Option: <[1] to [4]>: ";
		short Option = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter number between <[1] to [4]>");
		return Option;
	}

	
	
	static void _ShowDepositScreen() {

		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen() {

		clsWithdrawScreen::WithdrawScreen();
	}

	static void _ShowTransferScreen() {

		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen() {

		clsTransferLogScreen::ShowTransferLogScreen();

	}


	static void _ShowTotalBalanceScreen() {

		clsTotalBalance::ShowTotalBalance();
	}

	
	
	
	static void _GobackTransactionsMenu() {
		cout << "\n\n<Press any key to back main menu>";
		system("pause>0");
		ShowTransactionsScreen();
	}

	
	static void _PerformTransactionsScreen(_enTransactionsMenueOptions Transactions) 
	{

		switch (Transactions) {

		case _enTransactionsMenueOptions::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GobackTransactionsMenu();
			break;
		case _enTransactionsMenueOptions::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GobackTransactionsMenu();
			break;


		case _enTransactionsMenueOptions::eShowTransferScreen:
			system("cls");
			_ShowTransferScreen();
			_GobackTransactionsMenu();
			break;

		case _enTransactionsMenueOptions::eShowTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GobackTransactionsMenu();
			break;

		case _enTransactionsMenueOptions::eShowTotalBalance:
			system("cls");
			_ShowTotalBalanceScreen();
			_GobackTransactionsMenu();
			break;


		case _enTransactionsMenueOptions::eShowMainMenu:

			break;

		}
	}

	

public:



	static void ShowTransactionsScreen() {
		
		if (!_CheckAccessRights(clsBankUser::enPermissions::_pClientList))
		{
			return;// this will exit the function and it will not continue
		}

		system("cls");

		cout << CYAN;
		clsScreen::_ScreenHeader("\t\t Transactions Screen\n");

		cout << YELLOW;
		cout << setw(37) << left << "" << "===========================================\n\n";

		cout << WHITE;
		cout << setw(37) << left << "" << "\t[" << GREEN << "1" << WHITE << "] Deposit\n";
		cout << setw(37) << left << "" << "\t[" << GREEN << "2" << WHITE << "] Withdraw\n";
		cout << setw(37) << left << "" << "\t[" << GREEN << "3" << WHITE << "] Transfer\n";
		cout << setw(37) << left << "" << "\t[" << GREEN << "4" << WHITE << "] Transfer Log \n";
		cout << setw(37) << left << "" << "\t[" << GREEN << "5" << WHITE << "] Total Balance\n";
		cout << setw(37) << left << "" << "\t[" << RED << "6" << WHITE << "] Back\n\n";

		cout << YELLOW;
		cout << setw(37) << left << "" << "===========================================\n";

		cout << RESET;

		_PerformTransactionsScreen((_enTransactionsMenueOptions)_ReadTransactionsMenu());
	}
















};