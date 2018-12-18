#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include <cstring>

using namespace std;

class catalogue
{
private:

    int price, day;
    char *catalogue_name, *agent_name;

    friend bool operator!(catalogue);

    friend catalogue operator+(catalogue obj, int i);
    friend catalogue operator+(int i, catalogue obj);


public:

    catalogue() : price(100), day(1)
    {
        this->catalogue_name = new char[6];
        this->catalogue_name = "House, 1 floor";
        this->agent_name = new char[6];
        this->agent_name = "Lena";
    }

    catalogue(int input_price, int input_day, char input_name[], char input_agent[])
    {
        this->catalogue_name = new char[strlen(input_name) + 1];
        strcpy(this->catalogue_name, input_name);
        this->agent_name = new char[strlen(input_agent) + 1];
        strcpy(this->agent_name, input_agent);
        this->day = input_day;
        this->price = input_price;

    }

    int get_price() const { return price; };
    int get_day() const { return day; };
    char* get_catalogue() const { return catalogue_name; };
    char* get_agent() const { return agent_name; };

    void change_catalogue(catalogue&);
    void show_catalogue();
    void show_catalogue(int);
    void zadanie(catalogue&);

    //перегрузки
    catalogue& operator=(const catalogue&);
    char* operator=(char*);
    void operator++();
    void operator-();
    operator int() { return price; };



    void set_day(int tmp) { day = tmp; };
    void set_price(int tmp) { price = tmp; };
    void set_catalogue_name(char tmp[]) { strcpy(catalogue_name, tmp); };
    void set_agent_name(char tmp[]) { strcpy(agent_name, tmp); };

    catalogue(const catalogue & copy)
    {
        catalogue_name = new char[strlen(copy.get_catalogue()) + 1];
        strcpy(catalogue_name, copy.get_catalogue());
        agent_name = new char[strlen(copy.get_catalogue()) + 1];
        strcpy(agent_name, copy.get_agent());
        price = copy.get_price();
        day = copy.get_day();
    }

    ~catalogue()
    {
        delete[]catalogue_name;
        delete[]agent_name;
    }
};