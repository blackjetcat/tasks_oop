#include<stdio.h>
#include<iostream> 
#include<math.h> 
#include<stdlib.h>
#include<string>
#include <cstring>
#include "newnew.h"
#include <iomanip>
using namespace std;

tour& tour::operator= (const tour &tmp)
{
	agent_name = new char[strlen(tmp.get_agent()) + 1];
	strcpy(agent_name, tmp.get_agent());
	tour_name = new char[strlen(tmp.get_tour()) + 1];
	strcpy(tour_name, tmp.get_tour());
	day = tmp.get_day();
	price = tmp.get_price();
	return *this;
}

char* tour::operator=(char* tmp)
{
	char* newtour;
	newtour = new char[strlen(tmp) + strlen(tour_name) + 1];
	strcpy(newtour, tour_name);
	strcpy(newtour, tmp);
	return newtour;
}


bool operator!(tour tmp)
{
	if ((!tmp.price) && (!tmp.day) && (!tmp.tour_name) && (!tmp.agent_name))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void tour::operator++()
{
	int n = 10;
	day++;
	while (n != 0)
	{
		price++;
		n--;
	}
}



void tour::zadanie(tour & tmp)
{
	tmp.day = 10 + tmp.price;
}

tour operator+(tour obj, int i)
{
	tour tmp;
	tmp.day = obj.price + i;
	return tmp;
}
tour operator+(int i, tour obj)
{
	tour tmp;
	tmp.day = i + obj.price;
	return tmp;
}

//4 ????

void *operator new(size_t tip, int size)
{
	return new char[tip*size];
}
void operator delete(void *p, size_t tip)
{
	delete p; 
}
void tour::operator delete[](void *p)
{
	delete [] p;
}

istream &operator >> (istream &stream, tour &obj)
{
	stream >> obj.tour_name >> obj.agent_name >> obj.day >> obj.price;
	return stream;
}
ostream &operator<<(ostream &stream, tour obj)
{
	stream << "Tour name: " << obj.tour_name << "\n";
	stream << "Agent:" << obj.agent_name << "\n";
	stream << "Cout of days: "<< obj.day << "\n";
	stream << "Price: "<< obj.price << "\n";
	return stream;
}
float tour::operator()(tour & tmp)
{
	return (static_cast<float>(tmp.price) / tmp.day);
}
bool tour::operator[](tour & tmp)
{
	int cost; 
	char* name = new char;
	cout << "Input agent name & tour price:\n";
	cin >> name >> cost;
	if ((strcmp(tmp.agent_name, name) == 0) && (tmp.price == cost))
	{
		return true;
	}
	else
	{
		return false;
	}
}



void tour::operator-()
{
	char* mid_char_tour;
	char* mid_char_agent;
	int mid_int;

	mid_char_tour = new(strlen(tour_name) + 1) char;
	//mid_char_tour = new char[strlen(tour_name) + 1];
	strcpy(mid_char_tour, tour_name);
	mid_char_agent = new (strlen(agent_name) + 1) char;
	strcpy(mid_char_agent, agent_name);
	delete[]tour_name;
	delete[]agent_name;
	tour_name = new (strlen(mid_char_agent) + 1) char;
	strcpy(tour_name, mid_char_agent);
	agent_name = new (strlen(mid_char_tour) + 1) char;
	strcpy(agent_name, mid_char_tour);

	mid_int = day;
	day = price;
	price = mid_int;

}

void tour::show_tour()
{
	cout << "Tour name: " << tour_name << setw(5) << " Agent: " << agent_name << setw(5) << " Cout of days: " << day << setw(5) << " Price: " << price << endl;
}

void tour::show_tour(int key)
{
	cout << "That's emergency tour show" << endl;
	cout << "Tour name: " << tour_name << setw(5) << " Agent: " << agent_name << setw(5) << " Cout of days: " << day << setw(5) << " Price: " << price << endl;
}

void tour::change_tour(tour & tmp)
{
	int ch;
	cout << "What do you want to change? \n1 - Tour name\n2 - Agent\n3 - Cout of days\n4 - Price\n5 - Everything\n";
	cin >> ch;
	switch (ch)
	{
	case 1:
		{
		char change[25];
		cout << "Input new tour name: ";
		cin >> change;
		tmp.set_tour_name(change);
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
	case 5:
	{
		cout << "Input new tour:\n ";
		cin >> tmp;

		cout << "\nDone!\nResult is:\n ";
		cout << tmp << "\n(made with peregruzka)\n";
		break;
	}
	default:
		{
		cout << "Something wrong, please try again.";
		break;
		}

	}
}