#pragma once
#include <iostream>
#include <string>

#include "InterfaceCommunication.h"

using namespace std;

class clsPerson : public InterfaceCommunication
{

private:

    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {

        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    //Property Set
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    //Property Get
    string GetFirstName()
    {
        return _FirstName;
    }
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    //Property Set
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    //Property Get
    string GetLastName()
    {
        return _LastName;
    }
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;

    //Property Set
    void SetEmail(string Email)
    {
        _Email = Email;
    }

    //Property Get
    string GetEmail()
    {
        return _Email;
    }
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;

    //Property Set
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    //Property Get
    string GetPhone()
    {
        return _Phone;
    }
    __declspec(property(get = GetPhone, put = SetPhone)) string Phone;

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void Print()
    {
        cout << "=======================";
        cout << "\n\tInfo:";
        cout << "=======================";
        cout << "\n___________________";
        cout << "\n\tFirstName: " << _FirstName;
        cout << "\n\tLastName : " << _LastName;
        cout << "\n\tFull Name: " << FullName();
        cout << "\n\tEmail    : " << _Email;
        cout << "\n\tPhone    : " << _Phone;
        cout << "\n___________________\n";

    }




    void SendEmail(string Text, string Body) {

    }

    void SendFax(string Text, string Body) {


    }

   

};

