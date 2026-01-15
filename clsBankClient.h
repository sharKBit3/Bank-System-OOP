#pragma once


#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "clsString.h"
#include "clsPerson.h"
#include "clsInputValidate.h"

using namespace std;



class clsBankClient : public clsPerson{



private:

	enum enMode { _eUpdateMode = 0, _eEmptyMode = 1, AddNewMode = 2 };
	
	enMode _Mode;
	string _AccountNumber;
	string _Password;

	double _AccountBalance;
	
	bool _MarkForDelete = false;



	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::_eUpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::_eEmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.GetAccountNumber() + Seperator;
		stClientRecord += Client.Password + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}







	static  vector <clsBankClient> _LoadClientsDataFromFile()
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLinetoClientObject(Line);

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;

	}

	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient C : vClients)
			{
				if(C.MarkForDelete() == false)
				DataLine = _ConverClientObjectToLine(C);
				MyFile << DataLine << endl;

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C = *this;
				break;
			}

		}

		_SaveCleintsDataToFile(_vClients);

	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}




	void _AddNew()
	{

		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}


	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient, string UserName, string Seperator = "#//#") {


		string TransferLogRecord = "";

		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += AccountNumber + Seperator;
		TransferLogRecord += DestinationClient.AccountNumber + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;

		return TransferLogRecord;

	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{

		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}



	struct stTrnsferLogRecord;
	static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTrnsferLogRecord TransferLogRecord;

		vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
		TransferLogRecord.DateTime = vTrnsferLogRecordLine[0];
		TransferLogRecord.SrcAccountNumber = vTrnsferLogRecordLine[1];
		TransferLogRecord.DeAccountNumber = vTrnsferLogRecordLine[2];
		TransferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
		TransferLogRecord.SrcTransBalance = stod(vTrnsferLogRecordLine[4]);
		TransferLogRecord.DeTransBalance = stod(vTrnsferLogRecordLine[5]);
		TransferLogRecord.Username = vTrnsferLogRecordLine[6];

		return TransferLogRecord;

	}





public:


	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string Passsword, double AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)	
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_Password = Passsword;
		_AccountBalance = AccountBalance;
	}


	void SetAccountNumber(string AccNumber) {
		_AccountNumber = AccNumber;
	}

	string GetAccountNumber() {
		return _AccountNumber;
	}
	__declspec(property(get = GetAccountNumber, put = SetAccountNumber)) string AccountNumber;

	void SetPassword(string Passw) {
		_Password = Passw;
	}
	string GetPassword() {
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetAccountBalance(double AccBalance) {
		_AccountBalance = AccBalance;
	}

	double GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;


	/* 
	void Print() {
		cout << "======================\n";
		cout << "Client Info: \n";
		cout << "======================\n";
		cout << "\nFirstName: " << FirstName;
		cout << "\nLastName : " << LastName;
		cout << "\nFull Name: " << FullName();
		cout << "\nEmail    : " << Email;
		cout << "\nPhone    : " << Phone;
		cout << "\nAccount Number: " << _AccountNumber;
		cout << "\nPassword: " << _Password;
		cout << "\nAccount Balance: " << _AccountBalance;
		cout << "\n\n=======================\n";
	}
	*/
	//-----------------------------------------------------------------------------------

	 bool IsEmpty() {
		return (_Mode == enMode::_eEmptyMode);
	}

	 bool MarkForDelete() {
		 return _MarkForDelete;
	 }

	
	 static clsBankClient Find(string AccountNumber)
	 {
		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::in);//read Mode

		 if (MyFile.is_open())
		 {
			 string Line;
			 while (getline(MyFile, Line))
			 {
				 clsBankClient Client = _ConvertLinetoClientObject(Line);
				 if (Client.GetAccountNumber() == AccountNumber)
				 {
					 MyFile.close();
					 return Client;
				 }

			 }

			 MyFile.close();

		 }

		 return _GetEmptyClientObject();
	 }

	 static clsBankClient Find(string AccountNumber, string Password)
	 {
		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::in);//read Mode

		 if (MyFile.is_open())
		 {
			 string Line;
			 while (getline(MyFile, Line))
			 {
				 clsBankClient Client = _ConvertLinetoClientObject(Line);
				 if (Client.GetAccountNumber() == AccountNumber && Client.Password == Password)
				 {
					 MyFile.close();
					 return Client;
				 }

			 }

			 MyFile.close();

		 }
		 return _GetEmptyClientObject();
	 }


	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2};
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::_eEmptyMode:
			return svFaildEmptyObject;

		case enMode::_eUpdateMode:
			_Update();
			return svSucceeded;

		case enMode::AddNewMode:
			if (IsClientExist(_AccountNumber)){ 
				return svFaildAccountNumberExists;
			}
			else {
				_AddNew();
				_Mode = enMode::_eUpdateMode;
				return svSucceeded;
			}
		}


	}

	void Deposit(double Amount) {
		
		 _AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount) {
		if (Amount > _AccountBalance) {
			return false;
		}
		else {
			_AccountBalance -= Amount;
			Save();
		}
	
	}

	static bool IsClientExist(string AccountNumber)
	{

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}




	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}



	 bool Delete()
	{
	
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients) {

			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C._MarkForDelete = true;
			}
		}

		_SaveCleintsDataToFile(_vClients);
		*this = _GetEmptyClientObject();

		return true;
	}


	 static vector <clsBankClient>  GetClientsList() {

		return _LoadClientsDataFromFile();

	}


	 static void PrintClientRecordLine(clsBankClient Client)
	 {

		 cout << "| " << setw(15) << left << Client.AccountNumber;
		 cout << "| " << setw(15) << left << Client.FullName();
		 cout << "| " << setw(10) << left << Client.Password;
		 cout << "| " << setw(25) << left << Client.Phone;
		 cout << "| " << setw(25) << left << Client.Email;
		 cout << "| " << setw(35) << left << Client.AccountBalance;


	 }



	

	static double GetClientBalance() {

		vector <clsBankClient> vClients = GetClientsList();

		double TotalBalances = 0;

		for (clsBankClient& Client : vClients) {

			TotalBalances += Client.AccountBalance;

		}

		return TotalBalances;
	}


	bool Transfer(double Amount, clsBankClient& DestiniationClient, string Username) {

		if (Amount > _AccountBalance) {
			return false;
		}


		Withdraw(Amount);
		DestiniationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestiniationClient, Username);
		return true;
	}


	struct stTrnsferLogRecord {
		string DateTime;
		
		string SrcAccountNumber;
		string DeAccountNumber;

		double Amount;

		double SrcTransBalance;
		double DeTransBalance;

		string Username;

	};

	static  vector <stTrnsferLogRecord> GetTransfersLogList()
	{
		vector <stTrnsferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stTrnsferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{

				TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);

			}

			MyFile.close();

		}

		return vTransferLogRecord;

	}








};