#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "clsPerson.h"
#include "clsString.h"
#include "clsUtility.h"

using namespace std;


class clsBankUser : public clsPerson {

private:

	enum _enMode { _eUpdateMode = 0, _eEmptyMode = 1, _eAddNewMode = 2 };
	_enMode _Mode;

	string _Username;
	string _Password;

	int _Permissions;

	bool _MarkForDelete = false;

	

	static clsBankUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsString::Split(Line, Seperator);

		if (vUserData.size() != 7)
		{
			return _GetEmptyUserObject();
		}

		return clsBankUser(_enMode::_eUpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

	}

	static string _ConverUserObjectToLine(clsBankUser User, string Seperator = "#//#")
	{

		string UserRecord = "";

		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User.Username + Seperator;
		UserRecord += User.Password + Seperator;
		UserRecord += to_string(User.Permissions);



		return UserRecord;

	}

	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;


		vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);

		LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.Username = LoginRegisterDataLine[1];
		LoginRegisterRecord.Password = clsUtility::DecryptText(LoginRegisterDataLine[2]);
		LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

		return LoginRegisterRecord;

	}

	string _PrepareLogInRecord(string Seperator = "#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += Username + Seperator;
		LoginRecord += clsUtility::EncryptText(Password) + Seperator;
		LoginRecord += to_string(Permissions);
		return LoginRecord;
	}

	static  vector <clsBankUser> _LoadUsersDataFromFile()
	{

		vector <clsBankUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankUser User = _ConvertLinetoUserObject(Line);

				vUsers.push_back(User);
			}

			MyFile.close();

		}

		return vUsers;

	}

	static void _SaveUsersDataToFile(vector <clsBankUser> vUsers)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankUser U : vUsers)
			{
				if (U.MarkForDelete() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConverUserObjectToLine(U);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsBankUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsBankUser& U : _vUsers)
		{
			if (U.Username == Username)
			{
				U = *this;
				break;
			}

		}

		_SaveUsersDataToFile(_vUsers);

	}

	void _AddNew()
	{

		_AddDataLineToFile(_ConverUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static clsBankUser _GetEmptyUserObject()
	{
		return clsBankUser(_enMode::_eEmptyMode, "", "", "", "", "", "", 0);
	}











public:

	clsBankUser(_enMode Mode, string FirstName, string LastName, string Email, string Phone, string Username, string Password, int Permissions):
	      clsPerson(FirstName, LastName, Email, Phone)
	{

		_Mode = Mode;
		_Username = Username;
		_Password = Password;
		_Permissions = Permissions;

	}

	bool IsEmpty() {
		return (_Mode == _enMode::_eEmptyMode);
	}

	bool MarkForDelete() {
		return _MarkForDelete;
	}
	void SetUsername(string Username) {

		_Username = Username;
	}

	string GetUsername() {
		return _Username;
	}
	__declspec(property(get = GetUsername, put = SetUsername))string Username;


	void SetPassword(string Password) {

		_Password = Password;
	}
	string GetPassword() {

		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermission(int Permissions) {
		_Permissions = Permissions;
	}
	int GetPermission() {
		return _Permissions;
	}
	__declspec(property(get = GetPermission, put = SetPermission)) int Permissions;


	/* 	 
	    void Print() {
		cout << "=================================\n";
		cout << "\nUsers Info\n";
		cout << "=================================\n";
		cout << "\nFirstname: " << FirstName;
		cout << "\nLastname: " << LastName;
		cout << "\nEmail: " << Email;
		cout << "\nPhone: " << Phone;
		cout << "\nUsername: " << _Username;
		cout << "\nPassword: " << _Password;
		cout << "\nPermission: " << _Permissions;
		cout << "=================================\n";

	
	}

	*/



	 static clsBankUser Find(string Username)
	 {
		 fstream MyFile;
		 MyFile.open("Users.txt", ios::in);//read Mode

		 if (MyFile.is_open())
		 {
			 string Line;
			 while (getline(MyFile, Line))
			 {
				 clsBankUser User = _ConvertLinetoUserObject(Line);
				 if (User.Username == Username)
				 {
					 MyFile.close();
					 return User;
				 }
			 }

			 MyFile.close();

		 }

		 return _GetEmptyUserObject();
	 }

	 static clsBankUser Find(string Username, string Password)
	 {

		 fstream MyFile;
		 MyFile.open("Users.txt", ios::in);//read Mode

		 if (MyFile.is_open())
		 {
			 string Line;
			 while (getline(MyFile, Line))
			 {
				 clsBankUser User = _ConvertLinetoUserObject(Line);
				 if (User.Username == Username && User.Password == Password)
				 {
					 MyFile.close();
					 return User;
				 }

			 }

			 MyFile.close();

		 }
		 return _GetEmptyUserObject();
	 }










	 enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

	 enSaveResults Save()
	 {

		 switch (_Mode)
		 {
		 case _enMode::_eEmptyMode:
		 {
			 if (IsEmpty())
			 {
				 return enSaveResults::svFaildEmptyObject;
			 }
		 }

		 case _enMode::_eUpdateMode:
		 {
			 _Update();
			 return enSaveResults::svSucceeded;

			 break;
		 }

		 case _enMode::_eAddNewMode:
		 {
			 //This will add new record to file or database
			 if (clsBankUser::IsUserExist(_Username))
			 {
				 return enSaveResults::svFaildUserExists;
			 }
			 else
			 {
				 _AddNew();
				 //We need to set the mode to update after add new
				 _Mode = _enMode::_eUpdateMode;
				 return enSaveResults::svSucceeded;
			 }

			 break;
		 }
		 }

	 }






	 static bool IsUserExist(string UserName)
	 {

		 clsBankUser User = clsBankUser::Find(UserName);
		 return (!User.IsEmpty());
	 }







	 bool Delete()
	 {
		 vector <clsBankUser> _vUsers;
		 _vUsers = _LoadUsersDataFromFile();

		 for (clsBankUser& U : _vUsers)
		 {
			 if (U.Username == _Username)
			 {
				 U._MarkForDelete = true;
				 break;
			 }

		 }

		 _SaveUsersDataToFile(_vUsers);

		 *this = _GetEmptyUserObject();

		 return true;

	 }








	 static clsBankUser GetAddNewUserObject(string UserName)
	 {
		 return clsBankUser(_enMode::_eAddNewMode, "", "", "", "", UserName, "", 0);
	 }








	 static vector <clsBankUser> GetUsersList()
	 {
		 return _LoadUsersDataFromFile();
	 }




	 bool IsUserExist() {

		 return (!IsEmpty());
	 }


	 enum enPermissions { _pAll = -1, _pFindClients = 1, _pUpdateClients = 2, _pAddNewClient = 4, _pDeleteClient = 8, _pClientList = 16, _pTransactions = 32, _pManageUser = 64, _pRegisterLogScreen = 128 };


	  bool CheckAccessPermission(enPermissions Permission)
	 {
		 if (this->Permissions == enPermissions::_pAll)
			 return true;

		 if ((Permission & this->Permissions) == Permission)
			 return true;
		 else
			 return false;

	 }

	  

	 void RegisterLogIn()
	 {

		 string stDataLine = _PrepareLogInRecord();

		 fstream MyFile;
		 MyFile.open("LoginRegister.txt", ios::out | ios::app);

		 if (MyFile.is_open())
		 {

			 MyFile << stDataLine << endl;

			 MyFile.close();
		 }

	 }

	 struct stLoginRegisterRecord
	 {
		 string DateTime;
		 string Username;
		 string Password;
		 int Permissions;

	 };





	 static  vector <stLoginRegisterRecord> GetLoginRegisterList()
	 {
		 vector <stLoginRegisterRecord> vLoginRegisterRecord;

		 fstream MyFile;
		 MyFile.open("LoginRegister.txt", ios::in);//read Mode

		 if (MyFile.is_open())
		 {

			 string Line;

			 stLoginRegisterRecord LoginRegisterRecord;

			 while (getline(MyFile, Line))
			 {

				 LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

				 vLoginRegisterRecord.push_back(LoginRegisterRecord);

			 }

			 MyFile.close();

		 }

		 return vLoginRegisterRecord;

	 }


};