#pragma once


#include "clsScreen.h"
#include "clsString.h"
#include "clsBankCurrency.h"


class clsFindCurrencyScreen : protected  clsScreen {




private:

	static void _PrintCurrInfo(clsBankCurrency& Curr) {
		cout << "======================\n";
		cout << "Currency Type: \n";
		cout << "======================\n";
		cout << "\nCountry: " << Curr.Country();
		cout << "\nCurrency Code : " << Curr.CurrencyCode();
		cout << "\nCurrency Name: " << Curr.CurrencyName();
		cout << "\nRate    : " << Curr.Rate();
		cout << "\n\n=======================\n";
	}


	static void _Res(clsBankCurrency& Curr) {
		
		if (!Curr.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrInfo(Curr);
		}
		else
		{
			cout << "\nCurrency Wasn't Found :-(\n";
		}
   }
	


public:



	static void ShowFindCurrencyScreen()
	{



		clsScreen::_ScreenHeader("\t\t  Find Currency Screen\n");


		short Answer = 1;
		string CurrencyCode;
		string CurrencyCountry;

		cout << "Find by: [1]Code / [2]Country: ";
		cin >> Answer;

		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease Enter CurrencyCode: ";
			CurrencyCode = clsInputValidate::ReadS();
			clsBankCurrency Currency = clsBankCurrency::FindByCode(CurrencyCode);
			_Res(Currency);
		}
		else
		{
			string Country;
			cout << "\nPlease Enter Country Name: ";
			Country = clsInputValidate::ReadS();
			clsBankCurrency Currency = clsBankCurrency::FindByCountry(Country);
			_Res(Currency);
		}




	}





};