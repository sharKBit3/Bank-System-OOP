#pragma once



#include "clsScreen.h"
#include "clsBankUser.h"



class clsTransferScreen : protected clsScreen {


private:


	static void _PrintClient(clsBankClient& Client) {


		cout << "=================================\n";
		cout << "\nClient Info \n\n";
		cout << "=================================\n";
		cout << "\nFullname: " << Client.FullName();
		cout << "\nAccount Number: "<< Client.AccountNumber;
		cout << "\nAccount Balance:  " << Client.AccountBalance;
		cout << "\n=================================\n";


	}


    static string _ReadAccountNumber()
    {
        string AccountNumber;
        cout << "\nPlease Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate::ReadS();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadS();
        }
        return AccountNumber;
    }


    static float _ReadAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadDblNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }

    


public:

    static void ShowTransferScreen()
    {

        _ScreenHeader("\t\t  Transfer Screen\n");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClient(DestinationClient);



        float Amount = _ReadAmount(SourceClient);


        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.Username))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild! \n";
            }
        }

        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);


    }






};