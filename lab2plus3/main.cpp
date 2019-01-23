#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
#include "newnew.h"
#include <iomanip>

using namespace std;

//перегрузки = (можно перегружать только в кач-ве методов)
companies& companies::operator= (const companies &tmp)
{
    ceo_name = new char[strlen(tmp.get_ceo()) + 1];
    strcpy(ceo_name, tmp.get_ceo());
    companies_name = new char[strlen(tmp.get_companies()) + 1];
    strcpy(companies_name, tmp.get_companies());
    day = tmp.get_day();
    income = tmp.get_income();
    return *this;
}

char* companies::operator=(char* tmp)
{
    char* newcompanies;
    newcompanies = new char[strlen(tmp) + strlen(companies_name) + 1];
    strcpy(newcompanies, companies_name);
    strcpy(newcompanies, tmp);
    return newcompanies;
}

//перегрузки унарных операторов
bool operator!(companies tmp) //friend функция
{
    if ((!tmp.income) && (!tmp.day) && (!tmp.companies_name) && (!tmp.ceo_name))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void companies::operator++()
{
    int n = 10;
    day++;
    while (n != 0)
    {
        income++;
        n--;
    }
}

void companies::operator-()
{
    char* mid_char_companies;
    char* mid_char_ceo;
    int mid_int;

    mid_char_companies = new char[strlen(companies_name) + 1];
    strcpy(mid_char_companies, companies_name);
    mid_char_ceo = new char[strlen(ceo_name) + 1];
    strcpy(mid_char_ceo, ceo_name);
    delete[]companies_name;
    delete[]ceo_name;
    companies_name = new char[strlen(mid_char_ceo) + 1];
    strcpy(companies_name, mid_char_ceo);
    ceo_name = new char[strlen(mid_char_companies) + 1];
    strcpy(ceo_name, mid_char_companies);

    mid_int = day;
    day = income;
    income = mid_int;

}

void companies::zadanie(companies & tmp)
{
    tmp.day = 1965 + tmp.income;
}

companies operator+(companies obj, int i) // обработка class+int
{
    companies tmp;
    tmp.day = obj.income + i;
    return tmp;
}
companies operator+(int i, companies obj) // обработка int+class
{
    companies tmp;
    tmp.day = i + obj.income;
    return tmp;
}

void companies::show_companies()
{
    cout << "companies name: " << companies_name << setw(5) << " . ceo: " << ceo_name << setw(5) << ". Year of creation: " << day << setw(5) << ". income, mil$: " << income << endl;
}

void companies::show_companies(int key)
{
    cout << "That's emergency companies show" << endl;
    cout << "company name: " << companies_name << setw(5) << ". ceo: " << ceo_name << setw(5) << ". Year of creation: " << day << setw(5) << ". income, mil$: " << income << endl;
}

void companies::change_companies(companies & tmp)
{
    int ch;
    cout << "What do you want to change? \n1 - company name\n2 - ceo\n3 - Year of creation\n4 - income";
    cin >> ch;
    switch (ch)
    {
        case 1:
        {
            char change[25];
            cout << "Input new company name: ";
            cin >> change;
            tmp.set_companies_name(change);
            break;
        }
        case 2:
        {
            char change[25];
            cout << "Input new ceo name: ";
            cin >> change;
            tmp.set_ceo_name(change);
            break;
        }
        case 3:
        {
            int change;
            cout << "Input other year of creation: ";
            cin >> change;
            tmp.set_day(change);
            break;
        }
        case 4:
        {
            int change;
            cout << "Input new income: ";
            cin >> change;
            tmp.set_income(change);
            break;
        }
        default:
        {
            cout << "Something wrong, please try again.";
        }

            cout << "Result: " << endl;
            tmp.show_companies(1);
    }
}