#pragma once


#include <iostream>

#include "clsScreen.h" 
#include "clsBankUser.h"
#include "clsInputValidate.h"



class clsDeleteUserScreen : protected clsScreen {



private:

	static void _PrintUserInfo(clsBankUser& User) {
		cout << "======================\n";
		cout << "Client Info: \n";
		cout << "======================\n";
		cout << "\nFirstName: " << User.FirstName;
		cout << "\nLastName : " << User.LastName;
		cout << "\nFull Name: " << User.FullName();
		cout << "\nPhone    : " << User.Phone;
		cout << "\nEmail    : " << User.Email;
		cout << "\nUsername: " << User.Username;
		cout << "\nPassword:"<< User.Password;
		cout << "\n\n=======================\n";
	}

public:




	static void ShowDeleteUserByUsername() {

		clsScreen::_ScreenHeader("\t\t  Delete User Screen\n");

		string Username = " ";

		 cout << "\nUsername: ";
		 Username = clsInputValidate::ReadS();

		while (!clsBankUser::IsUserExist(Username)) {

			cout << "<Error> Username isn't available! choose another:  ";
			Username = clsInputValidate::ReadS();
		}

		clsBankUser User = clsBankUser::Find(Username);
		_PrintUserInfo(User);


		char Answer = 'n';
		cout << "Are you sure you want to delete this user? Press <[Y] / [N]>  :  ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {

			if (User.Delete()) {

				cout << "\nUser has been deleted successfully\n";
				_PrintUserInfo(User);
			}
			else {

				cout << "\n<Error> User still exist..\n";
			}
		}
		else {
			cout << "Exist...";
		}



	}






};