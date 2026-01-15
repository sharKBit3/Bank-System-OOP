#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsUserManagmentScreen.h"
#include "Global.h"


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"


using namespace std;



class clsMainMenu : protected clsScreen
{

private:

	enum _enMainMenuOptions { eFindCleint = 1, eUpdateClient = 2, eAddNewClient = 3, eDeleteClient = 4, eListClient = 5, eTransactions = 6,eUserManger = 7, eLoginRegister = 8, eExist = 9 };
	
	static short _ReadMainMenuOption() {
		
		cout << WHITE <<"\t\t\t->Please, enter a number to choose an Option: <[1] to [9]>: ";
		short Option = clsInputValidate::ReadIntNumberBetween(1, 9, "Enter number between <[1] to [9]>");
		return Option;
	}

	static void _GobackMainMenu() {
		cout << "\n\n<Press any key to back main menu>";
		system("pause>0");
		ShowMainMenuScreen();
	}

	
	
	
	
	
	static void _ShowFindClientScreen() {

		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowUpdateClientScreen() {

		clsUpdateClientScreen::ShowUpdateClient();
	}
	static void _ShowAddNewClient() {
		clsAddNewClientScreen::AddNewClient();
	}

	static void _ShowDeleteClientScreen() {
		clsDeleteScreen::ShowDeleteClientByAccountNumber();
	}
	
	static void _ShowListClient() {

		clsListScreen::ShowList();
	}

	static void _ShowTransactionScreen() {

		clsTransactionsScreen::ShowTransactionsScreen();
		
	} 

	static void _ShowUserManagmentScreen() {

		clsUserManagment::ShowUserManagmentScreen();
	}

	
	static void _ShowLoginRegister() {

		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}
	static void _Logout() {
		
		CurrentUser;
	
	}

	static void _PerformMainMenuScreen(_enMainMenuOptions MainMenuOption) {
		
		system("cls");
		switch (MainMenuOption) {

		case _enMainMenuOptions::eFindCleint:
			_ShowFindClientScreen();
			_GobackMainMenu();

			break;
		
		case _enMainMenuOptions::eUpdateClient:
			_ShowUpdateClientScreen();
			_GobackMainMenu();

			break;
		case _enMainMenuOptions::eAddNewClient:
			_ShowAddNewClient();
			_GobackMainMenu();

			break;

		case _enMainMenuOptions::eDeleteClient:
			_ShowDeleteClientScreen();
			_GobackMainMenu();

			break;

		case _enMainMenuOptions::eListClient:
			_ShowListClient();
			_GobackMainMenu();

			break;
		
		case _enMainMenuOptions::eTransactions:
			_ShowTransactionScreen();
			_GobackMainMenu();

			break;

		case _enMainMenuOptions::eUserManger:
			_ShowUserManagmentScreen();
			_GobackMainMenu();

			break;

		case _enMainMenuOptions::eLoginRegister:
			_ShowLoginRegister();
			_GobackMainMenu();

		
		case _enMainMenuOptions::eExist:
			_Logout();
			break;
		}

	}





public:

	static void ShowMainMenuScreen() {

		system("cls");
		cout << CYAN;
		_ScreenHeader("\t\t****** Welcome ******\n");

		cout << YELLOW;
		cout << setw(37) << left << "" << "===========================================\n";

		cout << BOLD << GREEN;
		cout << setw(37) << left << "" << "\t\t\tMain Menu\n";

		cout << YELLOW;
		cout << setw(37) << left << "" << "===========================================\n\n";

		cout << WHITE;
		cout << setw(37) << left << "" << "\t[" << GREEN << "1" << WHITE << "] Find Client\n";
		cout << setw(37) << left << "" << "\t[" << GREEN << "2" << WHITE << "] Update Client\n";
		cout << setw(37) << left << "" << "\t[" << GREEN << "3" << WHITE << "] Add New Client\n";
		cout << setw(37) << left << "" << "\t[" << GREEN << "4" << WHITE << "] Delete Client\n";
		cout << setw(37) << left << "" << "\t[" << GREEN << "5" << WHITE << "] Client List\n";
		cout << setw(37) << left << "" << "\t[" << GREEN << "6" << WHITE << "] Transactions\n";
		cout << setw(37) << left << "" << "\t[" << GREEN << "7" << WHITE << "] Manage Users\n";
		cout << setw(37) << left << "" << "\t[" << GREEN << "8" << WHITE << "] Registers\n";
		cout << setw(37) << left << "" << "\t[" << RED << "9" << WHITE << "] Logout\n\n";

		cout << YELLOW;
		cout << setw(37) << left << "" << "===========================================\n";

		cout << RESET;

		_PerformMainMenuScreen((_enMainMenuOptions)_ReadMainMenuOption());
	}

	


};