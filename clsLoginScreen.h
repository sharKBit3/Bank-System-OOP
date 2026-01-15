#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsMainMenu.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen {

private:


	

	static bool _ShowLoginScreen() {

		string _Username, _Password;
		bool _LoginFaild = false;
		
		short _Counter = 0;
		do {

			if (_Counter == 3) {
				cout << "Your Account has been locked, <Call Admin for more support>..\n";
				return 0;
			}

			if (_LoginFaild)
			{
				_Counter++;

				cout << "\n<Error> Try again...\n";
				cout << "\nYou still have " << (3 - _Counter) << " Trails\n";
			}
		
			cout << "Username: ";
			cin >> _Username;

			cout << "Password: ";
			cin >> _Password;


			

		
			CurrentUser = clsBankUser::Find(_Username, _Password);
			_LoginFaild = CurrentUser.IsEmpty();

		} while (_LoginFaild);
		
		CurrentUser.RegisterLogIn();
		clsMainMenu::ShowMainMenuScreen();
		return 1;
	}







public:

	static bool Login() {
		
		system("cls");
		clsScreen::_ScreenHeader("\t\t      Login Screen\n");
		_ShowLoginScreen();

		return _ShowLoginScreen();
	}



};