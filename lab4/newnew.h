#include<stdio.h>
#include<iostream> 
#include<math.h> 
#include<stdlib.h>
#include<string>
#include <cstring>
using namespace std;



class tour
{
private:

	int price, day;
	char *tour_name, *agent_name;

	friend bool operator!(tour);

	friend tour operator+(tour obj, int i);
	friend tour operator+(int i, tour obj);

	friend ostream &operator<<(ostream &stream, tour obj);
	friend istream &operator>>(istream &stream, tour &obj);

	

public:

	tour() : price(100), day(1)
	{
		this->tour_name = new char[6];
		this->tour_name = "Poland";
		this->agent_name = new char[6];
		this->agent_name = "Olivia";
	}

	tour(int input_price, int input_day, char input_name[], char input_agent[])
	{
		this->tour_name = new char[strlen(input_name) + 1];
		strcpy(this->tour_name, input_name);
		this->agent_name = new char[strlen(input_agent) + 1];
		strcpy(this->agent_name, input_agent);
		this->day = input_day;
		this->price = input_price;

	}

	int get_price() const { return price; };
	int get_day() const { return day; };
	char* get_tour() const { return tour_name; };
	char* get_agent() const { return agent_name; };

	void change_tour(tour&);
	void show_tour();
	void show_tour(int);
	void zadanie(tour&);

	//перегрузки
	tour& operator=(const tour&);
	char* operator=(char*);
	void operator++();
	void operator-();

	//4 лаба
	operator int() { return price; };
	void operator delete[](void *p);
	float operator()(tour&);
	bool operator[](tour&);




	void set_day(int tmp) { day = tmp; };
	void set_price(int tmp) { price = tmp; };
	void set_tour_name(char tmp[]) { strcpy(tour_name, tmp); };
	void set_agent_name(char tmp[]) { strcpy(agent_name, tmp); };

	tour(const tour & copy)
	{
		tour_name = new char[strlen(copy.get_tour()) + 1];
		strcpy(tour_name, copy.get_tour());
		agent_name = new char[strlen(copy.get_tour()) + 1];
		strcpy(agent_name, copy.get_agent());
		price = copy.get_price();
		day = copy.get_day();
	}

	~tour()
	{
		delete[]tour_name;
		delete[]agent_name;
	}
};
