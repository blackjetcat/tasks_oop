#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
#include "newnew.h"

using namespace std;


int main()
{
    int choice, choice_companies, choice_stuff, check_companies, swap_companies, choose_companies, zadanie_companies, view_cost;
    companies companies1(50, 1998, "Googol", "Paulson A.");
    companies companies2(25, 2014, "Creative Assembly", "Still H.");
    companies companies3(30, 1956, "EyeBM", "Amari P.");
    cout << "Enlisted companies: " << endl;
    companies1.show_companies();
    companies2.show_companies();
    companies3.show_companies();

    companies copy1 = companies1;
    companies copy2(companies2);
    companies copy3 = companies3;


    while (true)
    {
        cout << "What do you want to do? \n1 - View list of companies\n2 - Change entry\n3 - Do some stuff\n" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                companies1.show_companies();
                companies2.show_companies();
                companies3.show_companies();
                break;
            }
            case 2:

            {
                cout << "What entry would you like to change?\n1 - first\n2 - second\n3 - third\n";
                cin >> choice_companies;
                switch (choice_companies)
                {
                    case 1:
                    {
                        companies1.change_companies(companies1);
                        break;
                    }
                    case 2:
                    {
                        companies2.change_companies(companies2);
                        break;
                    }
                    case 3:
                    {
                        companies3.change_companies(companies3);
                        break;
                    }
                    default:
                    {
                        cout << "Something wrong, try again!\n";
                    }
                }
                break;
            }
            case 3:
            {
                cout << "Choose what you want to do:\n1 - Check list\n2 - View cost of pool\n3 - Swap data\n4 - Add 1 year to creation date\n5 - Special Task" << endl;
                cin >> choice_stuff;
                switch (choice_stuff)
                {
                    case 1:
                    {
                        cout << "What entry would you like to check?\n";
                        cin >> check_companies;
                        switch (check_companies)
                        {
                            case 1: { if (!companies1) cout << "It is fine!\n"; else cout << "Something wrong\n"; break; }
                            case 2: { if (!companies2) cout << "It is fine!\n"; else cout << "Something wrong\n"; break; }
                            case 3: { if (!companies3) cout << "It is fine!\n"; else cout << "Something wrong\n"; break; }
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "Which entry cost would you like to check?\n";
                        cin >> view_cost;
                        switch (view_cost)
                        {
                            case 1: { int cost = companies1; cout << "The cost is: " << cost << " mil $" << endl; break; }
                            case 2: { int cost = companies2; cout << "The cost is: " << cost << " mil $" << endl; break; }
                            case 3: { int cost = companies3; cout << "The cost is: " << cost << " mil $" << endl; break; }
                        }
                        break;
                    }
                    case 3:
                    {
                        cout << "Which companies would you like to swap?\n";
                        cin >> swap_companies;
                        switch (swap_companies)
                        {
                            case 1: { -companies1; cout << "Swapping ended!\n"; break; }
                            case 2: { -companies2; cout << "Swapping ended!\n"; break; }
                            case 3: { -companies3; cout << "Swapping ended!\n"; break; }
                        }
                        break;
                    }
                    case 4:
                    {
                        cout << "Which company would you like to add year?\n";
                        cin >> choose_companies;
                        switch (choose_companies)
                        {
                            case 1: { ++companies1; cout << "Year added!\n"; break; }
                            case 2: { ++companies2; cout << "Year added!\n"; break; }
                            case 3: { ++companies3; cout << "Year added!\n"; break; }
                        }
                        break;
                    }
                    case 5:
                    {
                        cout << "Which company would you like to perform the SPECIAL task?\n";
                        cin >> zadanie_companies;
                        switch (zadanie_companies) {
                            case 1: {companies1.show_companies();
                                companies1.zadanie(companies1);
                                companies1.show_companies(); break;}
                            case 2: {companies2.show_companies();
                                companies2.zadanie(companies2);
                                companies2.show_companies(); break;}
                            case 3: {companies3.show_companies();
                                companies3.zadanie(companies3);
                                companies3.show_companies(); break;}
                        }
                        break;
                    }
                    default:
                    {
                        cout << "Error! Something is wrong!\n";
                    }
                        break;
                }
            }
        }
    }

}