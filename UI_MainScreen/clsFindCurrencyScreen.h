
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen :protected clsScreen
{

private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:";
        cout << "\n___________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRates(1$)  : " << Currency.Rate();

        cout << "\n___________________\n";

    }

    static enum enFindOptions { eFindByCode = 1, eFindByCountry = 2 };


    static void _PerfomFindOptions(enFindOptions FindOptions)
    {
        switch (FindOptions)
        {
        case enFindOptions::eFindByCode:
            cout << "Find By Code";

        case enFindOptions::eFindByCountry:
            cout << "Find By Country";


        }

    }

    static enFindOptions _ReadFindOption()
    {
        cout << "Find By: [1] Code or [2] Country ? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number between 1 to 2? ");
        return enFindOptions (Choice);
    }

public:


    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\t  Find Currency Screen");


        enFindOptions Choice = _ReadFindOption();

        string CurrencyCode = "";
        string CurrencyCountry = "";

        switch (Choice)
        {
        case enFindOptions::eFindByCode:
        {

            cout << "Please Enter Currency Code: ";
            CurrencyCode = clsInputValidate::ReadString();
            while (!clsCurrency::IsCurrencyExistByCode(CurrencyCode))
            {
                cout << "Currency is not Found, Enter another code: ";
                CurrencyCode = clsInputValidate::ReadString();
            }

            clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
            if (!Currency1.IsEmpty())
            {
                cout << "\nCurrency Found :-)\n";
                _PrintCurrency(Currency1);
            }
            else
            {
                cout << "\nCurrency Was not Found\n";
            }
            break;
        }

        case enFindOptions::eFindByCountry:
        {

            cout << "Please Enter Currency Country: ";
            CurrencyCountry = clsInputValidate::ReadString();
            
            while (!clsCurrency::IsCurrencyExistByCountry(CurrencyCountry))
            {
                cout << "Currency is not Found, Enter another country: ";
                CurrencyCountry = clsInputValidate::ReadString();
            }

            clsCurrency Currency1 = clsCurrency::FindByCountry(CurrencyCountry);
            if (!Currency1.IsEmpty())
            {
                cout << "\nCurrency Found :-)\n";
                _PrintCurrency(Currency1);
            }
            else
            {
                cout << "\nCurrency Was not Found\n";
            }
            break;

        }


        }  

    }

};


