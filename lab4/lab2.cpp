#include<stdio.h>
#include<iostream> 
#include<math.h> 
#include<stdlib.h>
#include<string>
#include <cstring>
#include "newnew.h"

using namespace std;


int main()
{
	int choice, choice_tour, choice_stuff, check_tour, swap_tour, choose_tour, view_cost, choose_cost;
	tour tour1(50, 4, "Russia", "Anna");
	tour tour2(250, 3, "Sweeden", "Kris");
	tour tour3(100, 2, "Poland", "Kate");
	cout << "Available tours: " << endl;
	tour1.show_tour();
	tour2.show_tour();
	tour3.show_tour();

	tour copy1 = tour1;
	tour copy2(tour2);
	tour copy3 = tour3;
	
	
	while (true)
	{
		cout << "What do you want to do? \n1 - View tours\n2 - Change tour\n3 - Do some stuff\n" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			{
			tour1.show_tour();
			tour2.show_tour();
			tour3.show_tour();
			break;
			}
		case 2:

			{
			cout << "What tour would you like to change?\n1 - first\n2 - second\n3 - third\n";
			cin >> choice_tour;
			switch (choice_tour)
			{
			case 1:
				{
				tour1.change_tour(tour1);
				break;
				}
			case 2:
				{
				tour2.change_tour(tour2);
				break;
				}
			case 3:
			{
				tour3.change_tour(tour3);
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
			cout << "Choose what you want to do:\n1 - Check tours\n2 - View cost of tour\n3 - Swap data\n4 - Add 1 day to tour\n5 - Search" << endl;
			cin >> choice_stuff;
			switch (choice_stuff)
			{
			case 1:
			{
				cout << "What tour would you like to check?\n";
				cin >> check_tour;
				switch (check_tour)
				{
				case 1: { if (!tour1) cout << "It is fine!\n"; else cout << "Something wrong\n"; break; }
				case 2: { if (!tour2) cout << "It is fine!\n"; else cout << "Something wrong\n"; break; }
				case 3: { if (!tour3) cout << "It is fine!\n"; else cout << "Something wrong\n"; break; }
				}
				break;
			}
			case 2:
			{
				cout << "Do you like to check cost in a day (1) or all cost (2)?\n";
				cin >> choose_cost;
				switch (choose_cost)
				{
				case 1:
					{
					cout << "What tour's cost would you like to check?\n";
					cin >> view_cost;
					switch (view_cost)
					{
					case 1: { cout << "The cost is: " << tour1(tour1) << endl; break; }
					case 2: { cout << "The cost is: " << tour2(tour2) << endl; break; }
					case 3: {  cout << "The cost is: " << tour3(tour3) << endl; break; }
					}
					break;
					}
				case 2:
					{
						cout << "What tour's cost would you like to check?\n";
						cin >> view_cost;
						switch (view_cost)
							{
							case 1: { int cost = tour1; cout << "The cost is: " << cost << endl; break; }
							case 2: { int cost = tour2; cout << "The cost is: " << cost << endl; break; }
							case 3: { int cost = tour3; cout << "The cost is: " << cost << endl; break; }
							}
						break;
					}
				default: 
				{
					cout << "Error! Something is wrong!\n";
				}
			
				}
				break;
			}
			case 3:
			{
				cout << "What tour would you like to swap?\n";
				cin >> swap_tour;
				switch (swap_tour)
				{
				case 1: { -tour1; cout << "Swapping ended!\n"; break; }
				case 2: { -tour2; cout << "Swapping ended!\n"; break; }
				case 3: { -tour3; cout << "Swapping ended!\n"; break; }
				}
				break;
			}
			case 4:
			{
				cout << "What tour would you like to add day?\n";
				cin >> choose_tour;
				switch (choose_tour)
				{
				case 1: { ++tour1; cout << "Day added!\n"; break; }
				case 2: { ++tour2; cout << "Day added!\n"; break; }
				case 3: { ++tour3; cout << "Day added!\n"; break; }
				}
				break;
			}
			case 5:
			{
					cout << "What tour would you like to check (agent name & cost)?\n";
					int ch;
					cin >> ch;
					switch (ch)
					{
					case 1: { if (tour1[tour1]) { cout << " It's true\n"; break;
					}
							else { cout << "It's false\n";  break; } }
					case 2: {  if (tour2[tour2]) { cout << " It's true\n"; break;
					}
							else { cout << "It's false\n";  break; } }
					case 3: {  if (tour3[tour3]) { cout << " It's true\n"; break;
					}
							else { cout << "It's false\n";  break; } }
					}
				/*tour1.show_tour();
				tour1.zadanie(tour1);
				tour1.show_tour();*/
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