#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
#include "newnew.h"
#include <iomanip>

using namespace std;

//перегрузки = (можно перегружать только в кач-ве методов)
catalogue& catalogue::operator= (const catalogue &tmp)
{
    agent_name = new char[strlen(tmp.get_agent()) + 1];
    strcpy(agent_name, tmp.get_agent());
    catalogue_name = new char[strlen(tmp.get_catalogue()) + 1];
    strcpy(catalogue_name, tmp.get_catalogue());
    day = tmp.get_day();
    price = tmp.get_price();
    return *this;
}

char* catalogue::operator=(char* tmp)
{
    char* newcatalogue;
    newcatalogue = new char[strlen(tmp) + strlen(catalogue_name) + 1];
    strcpy(newcatalogue, catalogue_name);
    strcpy(newcatalogue, tmp);
    return newcatalogue;
}

//перегрузки унарных операторов
bool operator!(catalogue tmp) //friend функция
{
    if ((!tmp.price) && (!tmp.day) && (!tmp.catalogue_name) && (!tmp.agent_name))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void catalogue::operator++()
{
    int n = 10;
    day++;
    while (n != 0)
    {
        price++;
        n--;
    }
}

void catalogue::operator-()
{
    char* mid_char_catalogue;
    char* mid_char_agent;
    int mid_int;

    mid_char_catalogue = new char[strlen(catalogue_name) + 1];
    strcpy(mid_char_catalogue, catalogue_name);
    mid_char_agent = new char[strlen(agent_name) + 1];
    strcpy(mid_char_agent, agent_name);
    delete[]catalogue_name;
    delete[]agent_name;
    catalogue_name = new char[strlen(mid_char_agent) + 1];
    strcpy(catalogue_name, mid_char_agent);
    agent_name = new char[strlen(mid_char_catalogue) + 1];
    strcpy(agent_name, mid_char_catalogue);

    mid_int = day;
    day = price;
    price = mid_int;

}

void catalogue::zadanie(catalogue & tmp)
{
    tmp.day = 10 + tmp.price;
}

catalogue operator+(catalogue obj, int i) // обработка class+int
{
    catalogue tmp;
    tmp.day = obj.price + i;
    return tmp;
}
catalogue operator+(int i, catalogue obj) // обработка int+class
{
    catalogue tmp;
    tmp.day = i + obj.price;
    return tmp;
}

void catalogue::show_catalogue()
{
    cout << "catalogue name: " << catalogue_name << setw(5) << " . Agent: " << agent_name << setw(5) << ". Enlisted, days ago: " << day << setw(5) << ". Price: " << price << endl;
}

void catalogue::show_catalogue(int key)
{
    cout << "That's emergency catalogue show" << endl;
    cout << "catalogue name: " << catalogue_name << setw(5) << ". Agent: " << agent_name << setw(5) << ". Enlisted, days ago: " << day << setw(5) << ". Price: " << price << endl;
}

void catalogue::change_catalogue(catalogue & tmp)
{
    int ch;
    cout << "What do you want to change? \n1 - catalogue name\n2 - Agent\n3 - Enlisted, days ago\n4 - Price";
    cin >> ch;
    switch (ch)
    {
        case 1:
        {
            char change[25];
            cout << "Input new catalogue name: ";
            cin >> change;
            tmp.set_catalogue_name(change);
            break;
        }
        case 2:
        {
            char change[25];
            cout << "Input new agent name: ";
            cin >> change;
            tmp.set_agent_name(change);
            break;
        }
        case 3:
        {
            int change;
            cout << "Input new day cout: ";
            cin >> change;
            tmp.set_day(change);
            break;
        }
        case 4:
        {
            int change;
            cout << "Input new price: ";
            cin >> change;
            tmp.set_price(change);
            break;
        }
        default:
        {
            cout << "Something wrong, please try again.";
        }

            cout << "Result: " << endl;
            tmp.show_catalogue(1);
    }
}