#pragma once

#include <iomanip>

#include "clsScreen.h"
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen {




private:

	static void _PrintTransferLogScreen(clsBankClient::stTrnsferLogRecord TransferLogRec) {

		cout << setw(8) << left << "" << "| " << left << setw(23) << TransferLogRec.DateTime;
		cout << "| " << setw(8) << left << TransferLogRec.SrcAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRec.DeAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRec.Amount;
		cout << "| " << setw(12) << TransferLogRec.SrcTransBalance;
		cout << "| " << setw(18) << TransferLogRec.DeTransBalance;
		cout << "| " << setw(18) << left << TransferLogRec.Username;

	}




public:


	static void ShowTransferLogScreen() {

		vector <clsBankClient::stTrnsferLogRecord> vTransferLogRec = clsBankClient::GetTransfersLogList();


		string Title = "\t\t Transfer Log List Screen";
		string SubTitle = "\t    (" + to_string(vTransferLogRec.size()) + ") Record(s).\n";

		_ScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t====================================================";
		cout << "====================================================\n\n";
		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "Src.Acc";
		cout << "| " << left << setw(8) << "Des.Acc";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(12) << "Src.Balance";
		cout << "| " << left << setw(18) << "Des.Balance";
		cout << "| " << left << setw(17) << "Username";

		cout << setw(8) << left << "" << "\n\t====================================================";
		cout << "====================================================\n" << endl;


		if (vTransferLogRec.size() == 0)
			cout << "\t\t\t\tNo Transfers Available In the System!";
		else


		for (clsBankClient::stTrnsferLogRecord& T : vTransferLogRec) {

			_PrintTransferLogScreen(T);

		}

		cout << setw(8) << left << "" << "\n\t====================================================";
		cout << "====================================================\n" << endl;

	}










};