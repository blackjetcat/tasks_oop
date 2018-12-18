#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
#include "newnew.h"

using namespace std;


int main()
{
    int choice, choice_catalogue, choice_stuff, check_catalogue, swap_catalogue, choose_catalogue, view_cost;
    catalogue catalogue1(50, 1, "Flat, 5 rooms", "Anna");
    catalogue catalogue2(250, 3, "House, 2 floors", "Kris");
    catalogue catalogue3(100, 2, "Flat, 2 rooms", "Kate");
    cout << "Available catalogues: " << endl;
    catalogue1.show_catalogue();
    catalogue2.show_catalogue();
    catalogue3.show_catalogue();

    catalogue copy1 = catalogue1;
    catalogue copy2(catalogue2);
    catalogue copy3 = catalogue3;


    while (true)
    {
        cout << "What do you want to do? \n1 - View catalogues\n2 - Change catalogue\n3 - Do some stuff\n" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                catalogue1.show_catalogue();
                catalogue2.show_catalogue();
                catalogue3.show_catalogue();
                break;
            }
            case 2:

            {
                cout << "What catalogue would you like to change?\n1 - first\n2 - second\n3 - third\n";
                cin >> choice_catalogue;
                switch (choice_catalogue)
                {
                    case 1:
                    {
                        catalogue1.change_catalogue(catalogue1);
                        break;
                    }
                    case 2:
                    {
                        catalogue2.change_catalogue(catalogue2);
                        break;
                    }
                    case 3:
                    {
                        catalogue3.change_catalogue(catalogue3);
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
                cout << "Choose what you want to do:\n1 - Check catalogues\n2 - View cost of catalogue\n3 - Swap data\n4 - Add 1 day to catalogue" << endl;
                cin >> choice_stuff;
                switch (choice_stuff)
                {
                    case 1:
                    {
                        cout << "What catalogue would you like to check?\n";
                        cin >> check_catalogue;
                        switch (check_catalogue)
                        {
                            case 1: { if (!catalogue1) cout << "It is fine!\n"; else cout << "Something wrong\n"; break; }
                            case 2: { if (!catalogue2) cout << "It is fine!\n"; else cout << "Something wrong\n"; break; }
                            case 3: { if (!catalogue3) cout << "It is fine!\n"; else cout << "Something wrong\n"; break; }
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "What catalogue's cost would you like to check?\n";
                        cin >> view_cost;
                        switch (view_cost)
                        {
                            case 1: { int cost = catalogue1; cout << "The cost is: " << cost << endl; break; }
                            case 2: { int cost = catalogue2; cout << "The cost is: " << cost << endl; break; }
                            case 3: { int cost = catalogue3; cout << "The cost is: " << cost << endl; break; }
                        }
                        break;
                    }
                    case 3:
                    {
                        cout << "What catalogue would you like to swap?\n";
                        cin >> swap_catalogue;
                        switch (swap_catalogue)
                        {
                            case 1: { -catalogue1; cout << "Swapping ended!\n"; break; }
                            case 2: { -catalogue2; cout << "Swapping ended!\n"; break; }
                            case 3: { -catalogue3; cout << "Swapping ended!\n"; break; }
                        }
                        break;
                    }
                    case 4:
                    {
                        cout << "What catalogue would you like to add day?\n";
                        cin >> choose_catalogue;
                        switch (choose_catalogue)
                        {
                            case 1: { ++catalogue1; cout << "Day added!\n"; break; }
                            case 2: { ++catalogue2; cout << "Day added!\n"; break; }
                            case 3: { ++catalogue3; cout << "Day added!\n"; break; }
                        }
                        break;
                    }
                    case 5:
                    {
                        catalogue1.show_catalogue();
                        catalogue1.zadanie(catalogue1);
                        catalogue1.show_catalogue();
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