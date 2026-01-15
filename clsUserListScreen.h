#pragma once


#include <iostream>


#include "clsScreen.h"
#include "clsBankUser.h"





#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"


using namespace std;


class clsUserListScreen : protected clsScreen {


private:

	static void _PrintUserRecordLine(clsBankUser User)
	{

		cout << setw(8) << left << "" << "| " << left << setw(15) << User.Username;
		cout << "| " << setw(15) << left << User.FullName();
		cout << "| " << setw(18) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(12) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;


	}





public:



	static void ShowList() {


		cout << BOLD << CYAN;
		vector <clsBankUser> vUsers = clsBankUser::GetUsersList();

		string Title = "\t\t  Users List Screen\n";
		string Subtitle = "\t    (" + to_string(vUsers.size()) + ") User(s)\n";

		cout << BOLD << CYAN;

		_ScreenHeader(Title, Subtitle);

		cout << YELLOW 
			 << setw(8) << left << "" << "\n\t===================================================="
		     << "====================================================\n\n" << RESET << endl;

		cout << BOLD << WHITE;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "UserName";
		cout << "| " << left << setw(15) << "Full Name";
		cout << "| " << left << setw(18) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(12) << "Permissions";

		cout << RESET << endl;

		cout << YELLOW << setw(8) << left << "" << "\n\t===================================================="
		     << "====================================================\n\n" RESET << endl;

		if (vUsers.size() == 0)
			cout << RED << "\t\t\t\tNo Users Available In the System!";
		else

			for (clsBankUser& User : vUsers)
			{

				_PrintUserRecordLine(User);
				cout << endl;
			}
		     cout << YELLOW << setw(8) << left << "" << "\n\t===================================================="
		     << "====================================================\n\n" RESET << endl;


	}














};