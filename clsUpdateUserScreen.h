#pragma once


#include "clsScreen.h"
#include "clsBankUser.h"
#include "clsInputValidate.h"
#include "clsAddNewUserScreen.h"


class clsUpdateUserScreen : protected clsScreen {



private:


	static void _ReadUserInfo(clsBankUser& User) {


		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadS();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadS();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadS();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadS();


		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadS();

		cout << "\nPermission: ";
		User.Permissions = _ReadPermissions();

	}

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


	static int _ReadPermissions() {

		int Permissions = 0;
		char Answer = 'n';


		cout << "\nDo you want to give full access? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{


			Permissions += clsBankUser::enPermissions::_pFindClients;
		}

		cout << "\nAdd New Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsBankUser::enPermissions::_pUpdateClients;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsBankUser::enPermissions::_pAddNewClient;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsBankUser::enPermissions::_pDeleteClient;
		}

		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsBankUser::enPermissions::_pClientList;
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsBankUser::enPermissions::_pTransactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsBankUser::enPermissions::_pManageUser;
		}

		cout << "\nShow (Register Login) Screen? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsBankUser::enPermissions::_pRegisterLogScreen;
		}

		return Permissions;

	}


public:




	static void ShowUpdateUser()
	{

		clsScreen::_ScreenHeader("\t\t  Update User Screen\n");

		string Username = "";

		cout << "\nUsername: ";
		Username = clsInputValidate::ReadS();

		while (!clsBankUser::IsUserExist(Username))
		{
			cout << "\nUsername is not exist, choose another one: ";
			Username = clsInputValidate::ReadS();
		}

		clsBankUser User = clsBankUser::Find(Username);
		_PrintUserInfo(User);

		cout << "\n\nUpdate User Info:";
		cout << "\n____________________\n";
		_ReadUserInfo(User);


		clsBankUser::enSaveResults SaveResult;

		SaveResult = User.Save();

		switch (SaveResult)
		{

		case clsBankUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError username was not saved because it's Empty";

		}

		case  clsBankUser::enSaveResults::svSucceeded:
		{
			cout << "\nUser Updated Successfully :-)\n";
			_PrintUserInfo(User);
		}

		}
	}










};