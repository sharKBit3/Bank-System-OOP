#pragma once


#include "clsScreen.h"
#include "clsBankCurrency.h"


class clsCurrencyListScreen  : protected clsScreen{
	 

private:

	static void _PrintCurrecnyScreen(clsBankCurrency& Curr) {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Curr.Country();
        cout << "| " << setw(8) << left << Curr.CurrencyCode();
        cout << "| " << setw(45) << left << Curr.CurrencyName();
        cout << "| " << setw(10) << left << Curr.Rate();

    }




public:



	static void ShowList() {



        vector <clsBankCurrency> vCurrencys = clsBankCurrency::GetCurrenciesList();
        string Title = "\t\t  Currencies List Screen\n";
        string SubTitle = "\t    (" + to_string(vCurrencys.size()) + ") Currency.";

        _ScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vCurrencys.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsBankCurrency Currency : vCurrencys)
            {

                _PrintCurrecnyScreen(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

    }








};