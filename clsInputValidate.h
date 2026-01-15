#pragma once
#include <iostream>


#include "clsDate.h"
#include "clsUtility.h"

using namespace std;


class clsInputValidate {

public:



	static void Srand() {

		return clsUtility::Srand();
	}

	static int RandomNumber(int From, int To) {

		int randNum = rand() % (To - From + 1) + From;

		return randNum;
	}

	static char GetRandomCharacter(clsUtility::enCharType CharType) {

		return clsUtility::GetRandomCharacter(CharType);
	}

	static string GenerateWord(clsUtility::enCharType CharType, short Length) {

		return clsUtility::GenerateWord(CharType, Length);
	}

	static string GenerateKey(clsUtility::enCharType cType) {

		return clsUtility::GenerateKey(cType);
	}

	static void GenerateKeys(short NumberOfKeys, clsUtility::enCharType cType) {

		return clsUtility::GenerateKeys(NumberOfKeys, cType);
	}










	static void Swap1(int Num1, int Num2) {

		return clsUtility::Swap1(Num1, Num2);
	}

	static void Swap2(double Num1, double Num2) {

		return clsUtility::Swap2(Num1, Num2);
	}

	static void Swap3(char a, char b) {

		return clsUtility::Swap3(a, b);
	}

	static void Swap4(bool a, bool b) {

		return clsUtility::Swap4(a, b);
	}

	static void Swap5(string Name1, string Name2) {

		return clsUtility::Swap5(Name1, Name2);
	}






	static string  Tabs(short NumberOfTabs)
	{

		return clsUtility::Tabs(NumberOfTabs);
	}

	static string  EncryptText(string Text, short EncryptionKey)
	{

		return clsUtility::EncryptText(Text, EncryptionKey);
	}

	static string  DecryptText(string Text, short EncryptionKey)
	{

		return clsUtility::DecryptText(Text, EncryptionKey);
	}






	static bool IsNumberbetween(short Num, short From, short To) {
		if (From <= Num || Num <= To) {
			return true;
		}
		return false;
	}

	static bool IsNumberbetween(int Num, int From, int To) {

		if (From <= Num && Num <= To) {
			return true;
		}
		return false;


	}

	static bool IsNumberbetween(double Num, double From, double To) {

		if (From <= Num && Num <= To) {
			return true;
		}
		return false;
	}

	static bool IsNumberbetween(float Num, float From, float To) {

		if (From <= Num && Num <= To) {
			return true;
		}
		return false;
	}


	static bool IsDatebetween(clsDate Date, clsDate From, clsDate To) {

		if (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)
			&&
			clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
		{
			return false;
		}

		if (clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)
			&&
			clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
		{
			return false;
		}

		return true;
	}






	static int ReadIntNumber(string ErrorMessage = "\nPlease Enter a Number:\n")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberbetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}


	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadIntNumber();

		while (!IsNumberbetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}


	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberbetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}


	static string ReadString() {

		string EnterAccNumber;

		cout << "Enter Account Number: \n";
		getline(cin >> ws, EnterAccNumber);

		return EnterAccNumber;


	}


	static string ReadS() {
		string S1 = " ";

		getline(cin >> ws, S1);

		return S1;
	}





	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}





	static string DateToString(clsDate Date) {

		return clsDate::DateToString(Date);
	}

	static bool isleapYear(short Year) {

		return clsDate::isLeapYear(Year);
	}





	static short NumberOfDaysInYear(short Year) {
		return clsDate::NumberOfDaysInAYear(Year);
	}

	static short NumberOfHoursInYear(short Year) {

		return clsDate::NumberOfHoursInAYear(Year);
	}

	static int NumberOfMinutesInYear(short Year) {

		return clsDate::NumberOfMinutesInAYear(Year);
	}

	static int NumberOfSecondsInYear(short Year) {

		return clsDate::NumberOfSecondsInAYear(Year);
	}




	static short NumberOfDaysInMonth(short Month, short Year) {

		return clsDate::NumberOfDaysInAMonth(Month, Year);

	}

	static short NumberOfHoursInMonth(short Month, short Year) {

		return  clsDate::NumberOfHoursInAMonth(Month, Year);

	}

	static int NumberOfMinutesInMonth(short Month, short Year) {

		return clsDate::NumberOfMinutesInAMonth(Month, Year);

	}

	static int NumberOfSecondsInMonth(short Month, short Year) {

		return clsDate::NumberOfSecondsInAMonth(Month, Year);
	}






	static string DayShortName(short DayOfWeekOrder) {

		return clsDate::DayShortName(DayOfWeekOrder);
	}

	static string DayShortName(short Day, short Month, short Year) {

		return clsDate::DayShortName(Day, Month, Year);
	}

	static string MonthShortName(short MonthNumber) {

		return clsDate::MonthShortName(MonthNumber);
	}





	static void PrintMonthCalendar(short Month, short Year) {

		clsDate::PrintMonthCalendar(Month, Year);
	}

	static void PrintYearCalendar(short Year) {

		clsDate::PrintYearCalendar(Year);
	}





	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {

		return clsDate::IsDate1BeforeDate2(Date1, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {

		return clsDate::IsDate1EqualDate2(Date1, Date2);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {

		return clsDate::IsDate1AfterDate2(Date1, Date2);
	}



	static bool IsLastDayInMonth(clsDate Date) {

		return clsDate::IsLastDayInMonth(Date);
	}

	static bool IsLastMonthInYear(short Day, short Month, short Year) {

		return clsDate::IsLastMonthInYear(Day, Month, Year);
	}





	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {

		return clsDate::GetDifferenceInDays(Date1, Date2, IncludeEndDay);
	}






	static short CalculateAgeInYears(clsDate Birthday) {

		return clsDate::CalculateAgeInYears(Birthday);
	}

	static short CalculateAgeInMonths(clsDate Birthday) {

		return clsDate::CalculateAgeInMonths(Birthday);
	}

	static short CalculateAgeInDays(clsDate Birthday) {

		return clsDate::CalculateMyAgeInDays(Birthday);

	}







	static clsDate IncreaseDateByOneDay(clsDate Date) {

		return clsDate::IncreaseDateByOneDay(Date);
	}

	static clsDate IncreaseDatebyOneWeek(clsDate Date) {

		return clsDate::IncreaseDateByOneWeek(Date);
	}

	static clsDate IncreaseDateByXWeek(short Weeks, clsDate Date) {

		return clsDate::IncreaseDateByXWeeks(Weeks, Date);
	}

	static clsDate IncreaseDateByOneMonth(clsDate Date) {

		return clsDate::IncreaseDateByOneMonth(Date);
	}

	static clsDate IncreaseDateByXMonths(short Months, clsDate Date) {

		return clsDate::IncreaseDateByXMonths(Months, Date);
	}

	static clsDate IncreaseDateByXDays(short Days, clsDate Date) {
		return clsDate::IncreaseDateByXDays(Days, Date);
	}

	static clsDate IncreaseDateByOneYear(clsDate Date) {

		return clsDate::IncreaseDateByOneYear(Date);
	}

	static clsDate IncreaseDateByXYears(short Years, clsDate Date) {

		return clsDate::IncreaseDateByXYears(Years, Date);
	}

	static clsDate IncreaseDateByOneDecade(clsDate Date) {

		return clsDate::IncreaseDateByOneDecade(Date);
	}

	static clsDate IncreaseDateByXDecades(short Decades, clsDate Date) {

		return clsDate::IncreaseDateByXDecades(Decades, Date);
	}

	static clsDate IncreaseDateByOneCentury(clsDate Date) {

		return clsDate::IncreaseDateByOneCentury(Date);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate Millennium) {

		return clsDate::IncreaseDateByOneMillennium(Millennium);
	}









	static clsDate DecreaseDateByOneDay(clsDate Date) {

		return clsDate::DecreaseDateByOneDay(Date);
	}

	static clsDate DecreaseDatebyOneWeek(clsDate Date) {

		return clsDate::DecreaseDateByOneWeek(Date);
	}

	static clsDate DecreaseDateByXWeek(short Weeks, clsDate Date) {

		return clsDate::DecreaseDateByXWeeks(Weeks, Date);
	}

	static clsDate DecreaseDateByOneMonth(clsDate Date) {

		return clsDate::DecreaseDateByOneMonth(Date);
	}

	static clsDate DecreaseDateByXMonths(short Months, clsDate Date) {

		return clsDate::DecreaseDateByXMonths(Months, Date);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate Date) {
		return clsDate::DecreaseDateByXDays(Days, Date);
	}

	static clsDate DecreaseDateByOneYear(clsDate Date) {

		return clsDate::DecreaseDateByOneYear(Date);
	}

	static clsDate DecreaseDateByXYears(short Years, clsDate Date) {

		return clsDate::DecreaseDateByXYears(Years, Date);
	}

	static clsDate DecreaseDateByOneDecade(clsDate Date) {

		return clsDate::DecreaseDateByOneDecade(Date);
	}

	static clsDate DecreaseDateByXDecades(short Decades, clsDate Date) {

		return clsDate::DecreaseDateByXDecades(Decades, Date);
	}

	static clsDate DecreaseDateByOneCentury(clsDate Date) {

		return clsDate::DecreaseDateByOneCentury(Date);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate Millennium) {

		return clsDate::DecreaseDateByOneMillennium(Millennium);
	}










	static short IsEndOfWeek(clsDate Date) {

		return clsDate::IsEndOfWeek(Date);
	}


	static bool IsWeekend(clsDate Date) {

		return clsDate::IsWeekEnd(Date);
	}


	static bool IsBusinessDay(clsDate Date) {

		return clsDate::IsBusinessDay(Date);
	}

	static short DayUntilTheEndOfWeek(clsDate Date) {

		return clsDate::DaysUntilTheEndOfWeek(Date);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date) {

		return clsDate::DaysUntilTheEndOfMonth(Date);
	}

	static short DaysUntilTheEndOfYear(clsDate Date) {

		return clsDate::DaysUntilTheEndOfYear(Date);
	}


	static short CalculateBusinessDaysBetween2Dates(clsDate DateFrom, clsDate DateTo) {

		return clsDate::CalculateBusinessDays(DateFrom, DateTo);
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo) {

		return clsDate::CalculateVacationDays(DateFrom, DateTo);
	}


	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays) {

		return clsDate::CalculateVacationReturnDate(DateFrom, VacationDays);
	}


	static clsDate::enDateCompare Compare2Dates(clsDate Date1, clsDate Date2) {

		return clsDate::CompareDates(Date1, Date2);
	}


















};

