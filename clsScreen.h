#pragma once


#include <iostream>
#include <iomanip>

#include "clsDate.h"
#include "Global.h"
#include "clsLoginScreen.h"


#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define WHITE   "\033[37m"

using namespace std;





class clsScreen {


protected:


    static void _PrintDate()
    {
        cout << WHITE << "\nDate: " << clsDate::DateToString(clsDate()) << RESET << "\n\n";
    }

	
    static void _ScreenHeader(string Title, string SubTitle = " ")
    {
        

        cout << "\t\t\t\t\t=======================================";
        cout << "\n\n\t\t\t\t " << Title;

        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
            
        }
        cout << "\n\t\t\t\t\t=======================================\n\n";
        


        if (clsBankUser::IsUserExist(CurrentUser.Username))
        {
            cout << GREEN << "Username: " << CurrentUser.Username << RESET;
        }
       

        _PrintDate();

    }

    static bool _CheckAccessRights(clsBankUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t=========================================";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.\n";
            cout << "\n\t\t\t\t=========================================\n\n";

            clsDate Date = clsDate::GetSystemDate();
            cout << "\nDate: " << clsDate::DateToString(Date) << "\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

















};