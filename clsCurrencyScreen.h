#pragma once


#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculScreen.h"

class  clsCurrencyScreen : protected clsScreen {


private:


	enum enCurrency{ eCurrencyList = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3, eCurrencyCalcul = 4, eExist = 5 };



	static short ReadOption() {
		cout << WHITE << "\t\t\t->Please, enter a number to choose an Option: <[1] to [5]>: " << RESET;
		short Option = clsInputValidate::ReadIntNumberBetween(1, 5, RED "Enter number between <[1] - [5]>" RESET);
		return Option;
	}

	static void _GobackMainMenu() {
		cout << "\n\n<Press any key to back main menu>";
		system("pause>0");
		ShowCurrencyMenu();
	}


	static void _ShowCurrencyList() {

		clsCurrencyListScreen::ShowList();
	}

	static void _ShowFindCurrency() {

		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRate() {

		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}
	
	static void _ShowCurrencyCalcul() {

		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}



	static void _PerformCurrencyOptions(enCurrency SwitchOption) {
		
		system("cls");
		switch (SwitchOption) {

		    case enCurrency::eCurrencyList:
				_ShowCurrencyList();
				_GobackMainMenu();
				break;

			case enCurrency::eFindCurrency:
				_ShowFindCurrency();
				_GobackMainMenu();
				break;

			case enCurrency::eUpdateCurrencyRate:
				_ShowUpdateCurrencyRate();
				_GobackMainMenu();
				break;

			case enCurrency::eCurrencyCalcul:
				_ShowCurrencyCalcul();
				_GobackMainMenu();
				break;

			case enCurrency::eExist:
				break;
		}

	}



public:

	static void ShowCurrencyMenu() {


		system("cls");

		clsScreen::_ScreenHeader(WHITE BOLD "\t\t  Currency Main Screen\n" RESET);

		cout << WHITE << setw(44) << left << "" << "================================\n\n" RESET;
		cout << YELLOW << setw(47) << left << "" << "Currency Menu\n\n" RESET;
		cout << WHITE << setw(44) << left << "" << "================================\n\n" RESET;

		cout << GREEN << setw(47) << left << "" << "[1] Currency List\n" RESET;
		cout << GREEN << setw(47) << left << "" << "[2] Find Currency\n" RESET;
		cout << GREEN << setw(47) << left << "" << "[3] Update Currency Rate\n" RESET;
		cout << GREEN << setw(47) << left << "" << "[4] Currency Calculator\n" RESET;

		cout << RED << setw(47) << left << "" << "[5] Back\n\n" RESET;

		cout << WHITE << setw(44) << left << "" << "=================================\n" RESET;

		_PerformCurrencyOptions((enCurrency)ReadOption());
	}














};