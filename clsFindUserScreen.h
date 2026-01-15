#pragma once


#include "clsScreen.h"
#include "clsBankUser.h"
#include "clsInputValidate.h"



class clsFindUserScreen : protected clsScreen {




private:

	static void _PrintUserInfo(clsBankUser& User) {
		cout << "======================\n";
		cout << "User Info: \n";
		cout << "======================\n";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.Username;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n\n=======================\n";
	}


public:



	static void ShowFindUserScreen()
	{

		clsScreen::_ScreenHeader("\t\t  Find User Screen\n");

		string Username;
		cout << "\nUsername: ";
		Username = clsInputValidate::ReadS();
		while (!clsBankUser::IsUserExist(Username))
		{
			cout << "\nUsername is not exist, choose another one: ";
			Username = clsInputValidate::ReadS();
		}

		clsBankUser Client = clsBankUser::Find(Username);

		if (!Client.IsEmpty())
		{
			cout << "\nUser Found :-)\n";
		}
		else
		{
			cout << "\nUser Was not Found :-(\n";
		}

		_PrintUserInfo(Client);

	}







};