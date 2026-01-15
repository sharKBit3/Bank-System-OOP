#pragma once



#include "clsMainMenu.h"
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsRegisterLoginScreen.h"


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"



class clsUserManagment : protected clsScreen {



private:

    enum _enManageUsersMenueOptions { eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenu = 6};

    static short _ReadUserManagmentOption() {

        cout << CYAN << "\t\t\t->Please, enter a number to choose an Option: <[1] to [6]>: " << RESET;
        short Option = clsInputValidate::ReadIntNumberBetween(1, 6, RED "Enter number between <[1] to [6]>" RESET);
        return Option;
    }

    static void _GobackMainMenu() {
        cout << "\n\n<Press any key to back main menu>";
        system("pause>0");
        ShowUserManagmentScreen();
    }



    static void _ShowUserLists() {

        clsUserListScreen::ShowList();
    }

    static  void _ShowAddNewUser() {

        clsAddNewUserScreen::AddNewUser();
    }

    static  void _ShowDeleteUser() {

        clsDeleteUserScreen::ShowDeleteUserByUsername();
    }

    static void _ShowUpdateUser() {

        clsUpdateUserScreen::ShowUpdateUser();
    }

    static void _ShowFindUser() {

        clsFindUserScreen::ShowFindUserScreen();
    }

   


    static void _PerformUserManagmentOptions(_enManageUsersMenueOptions UserManagment) {

        switch (UserManagment) {

        case _enManageUsersMenueOptions::eListUsers:
            system("cls");
            _ShowUserLists();
            _GobackMainMenu();
            break;

        case _enManageUsersMenueOptions::eAddNewUser:
            system("cls");
            _ShowAddNewUser();
            _GobackMainMenu();
            break;

        case _enManageUsersMenueOptions::eDeleteUser:
            system("cls");
            _ShowDeleteUser();
            _GobackMainMenu();
            break;

        case _enManageUsersMenueOptions::eUpdateUser:
            system("cls");
            _ShowUpdateUser();
            _GobackMainMenu();
            break;

        case _enManageUsersMenueOptions::eFindUser:
            system("cls");
            _ShowFindUser();
            _GobackMainMenu();
            break;
        case _enManageUsersMenueOptions::eMainMenu:
           
            break;

        }

    }

public:




    static void ShowUserManagmentScreen() {

        system("cls");

        if (!_CheckAccessRights(clsBankUser::enPermissions::_pClientList))
            return;

        clsScreen::_ScreenHeader(CYAN BOLD "\t\t User Management Screen\n" RESET);

        cout << BLUE << setw(44) << left << "" << "================================\n\n" RESET;
        cout << YELLOW << setw(47) << left << "" << "User Management Menu\n\n" RESET;
        cout << BLUE << setw(44) << left << "" << "================================\n\n" RESET;

        cout << GREEN << setw(47) << left << "" << "[1] Users List\n" RESET;
        cout << GREEN << setw(47) << left << "" << "[2] Add New User\n" RESET;
        cout << GREEN << setw(47) << left << "" << "[3] Delete User\n" RESET;
        cout << GREEN << setw(47) << left << "" << "[4] Update User\n" RESET;
        cout << GREEN << setw(47) << left << "" << "[5] Find User\n" RESET;

        cout << RED << setw(47) << left << "" << "[6] Back\n\n" RESET;

        cout << BLUE << setw(44) << left << "" << "=================================\n" RESET;

        _PerformUserManagmentOptions((_enManageUsersMenueOptions)_ReadUserManagmentOption());
    }








};