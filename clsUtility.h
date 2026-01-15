#pragma once
#include <iostream>
using namespace std;


class clsUtility {

public:

    enum enCharType {
        SmallLetter = 1,
        CapitalLetter = 2,
        SpecialCharacter = 3,
        Digit = 4
    };


    static void Srand()
    {
        srand((unsigned)time(NULL));

    }

    static int RandomNumber(int From, int To) {

        int randNum = rand() % (To - From + 1) + From;

        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType) {

        switch (CharType)
        {
        case enCharType::SmallLetter:
        {
            // Generate a random lowercase letter (ASCII codes 97 to 122).
            return char(RandomNumber(97, 122));
            break;  // break is not strictly needed after a return.
        }
        case enCharType::CapitalLetter:
        {
            // Generate a random uppercase letter (ASCII codes 65 to 90).
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            // Generate a random special character (ASCII codes 33 to 47).
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            // Generate a random digit (ASCII codes 48 to 57).
            return char(RandomNumber(48, 57));
            break;
        }
        }
        // If an invalid type is passed, return a null character.
        return '\0';
    }

    static string GenerateWord(enCharType CharType, short Length) {

        string Word;

        for (int i = 1; i <= Length; i++)
        {
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }

    static string GenerateKey(enCharType cType = CapitalLetter)
    {
        string Key = "";

        Key = GenerateWord(cType, 4) + "-";
        Key = Key + GenerateWord(cType, 4) + "-";
        Key = Key + GenerateWord(cType, 4) + "-";
        Key = Key + GenerateWord(cType, 4);

        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType cType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(cType) << endl;
        }

    }






    static void Swap1(int Num1, int Num2) {

        int Temp;
        Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;

        cout << Num1 << "\n";
        cout << Num2 << "\n";

    }

    static void Swap2(double Num1, double Num2) {

        double Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;

        cout << Num1 << "\n";
        cout << Num2 << "\n";
    }

    static void Swap3(char a, char b) {
        char Temp;

        Temp = a;
        a = b;
        b = Temp;

        cout << a << "\n";
        cout << b << "\n";
    }

    static void Swap4(bool a, bool b) {
        bool Temp;

        Temp = a;
        a = b;
        b = Temp;

        cout << a << "\n";
        cout << b << "\n";
    }

    static void Swap5(string Name1, string Name2) {
        string Temp = Name1;
        Name1 = Name2;
        Name2 = Temp;

        cout << Name1 << "\n";
        cout << Name2 << "\n";
    }





    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

    static string  EncryptText(string Text, short EncryptionKey = 4)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey = 4)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }



    static string NumberToText(int Number) {
        return clsString::NumberToText(Number);
    }



};



