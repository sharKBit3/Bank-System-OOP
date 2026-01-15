#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsBankUser.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class clsLoginRegisterScreen :protected clsScreen
{

    private:
        static void _PrintLoginRegisterRecordLine(clsBankUser::stLoginRegisterRecord LoginRegisterRecord)
        {
            cout << setw(8) << left << ""
                << WHITE << "| " << setw(35) << left << LoginRegisterRecord.DateTime
                << CYAN << "| " << setw(20) << left << LoginRegisterRecord.Username
                << YELLOW << "| " << setw(20) << left << LoginRegisterRecord.Password
                << GREEN << "| " << setw(10) << left << LoginRegisterRecord.Permissions
                << RESET;
        }

    public:
        static void ShowLoginRegisterScreen()
        {
            if (!clsScreen::_CheckAccessRights(
                clsBankUser::enPermissions::_pRegisterLogScreen))
                return;

            vector<clsBankUser::stLoginRegisterRecord> vLoginRegisterRecord = clsBankUser::GetLoginRegisterList();

            string Title = CYAN BOLD "\t\t Login Register List Screen\n" RESET;
            string SubTitle = YELLOW "\t  (" + to_string(vLoginRegisterRecord.size()) + ") Record(s)." RESET;

            _ScreenHeader(Title, SubTitle);

            cout << BLUE << setw(8) << left << ""
                << "\n\t====================================================="
                << "=================================================\n\n"
                << RESET;

            cout << BOLD << setw(8) << left << ""
                << "| " << setw(35) << left << "Date/Time"
                << "| " << setw(20) << left << "Username"
                << "| " << setw(20) << left << "Password"
                << "| " << setw(10) << left << "Permissions"
                << RESET;

            cout << BLUE << setw(8) << left << ""
                << "\n\t===================================================="
                << "=================================================\n\n"
                << RESET;

            if (vLoginRegisterRecord.empty())
            {
                cout << RED << "\t\t\t\tNo Logins Available In the System!"
                    << RESET << endl;
            }
            else
            {
                for (const auto& Record : vLoginRegisterRecord)
                {
                    _PrintLoginRegisterRecordLine(Record);
                    cout << endl;
                }
            }

            cout << BLUE << setw(8) << left << ""
                << "\n\t===================================================="
                << "=================================================\n\n"
                << RESET;
        }




};


