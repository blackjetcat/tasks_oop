#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include <cstring>

using namespace std;

class companies
{
private:

    int income, day;
    char *companies_name, *ceo_name;

    friend bool operator!(companies);

    friend companies operator+(companies obj, int i);
    friend companies operator+(int i, companies obj);


public:

    companies() : income(100), day(1)
    {
        this->companies_name = new char[6];
        this->companies_name = "Detective agency";
        this->ceo_name = new char[6];
        this->ceo_name = "Kellog";
    }

    companies(int input_income, int input_day, char input_name[], char input_ceo[])
    {
        this->companies_name = new char[strlen(input_name) + 1];
        strcpy(this->companies_name, input_name);
        this->ceo_name = new char[strlen(input_ceo) + 1];
        strcpy(this->ceo_name, input_ceo);
        this->day = input_day;
        this->income = input_income;

    }

    int get_income() const { return income; };
    int get_day() const { return day; };
    char* get_companies() const { return companies_name; };
    char* get_ceo() const { return ceo_name; };

    void change_companies(companies&);
    void show_companies();
    void show_companies(int);
    void zadanie(companies&);

    //перегрузки
    companies& operator=(const companies&);
    char* operator=(char*);
    void operator++();
    void operator-();
    operator int() { return income; };



    void set_day(int tmp) { day = tmp; };
    void set_income(int tmp) { income = tmp; };
    void set_companies_name(char tmp[]) { strcpy(companies_name, tmp); };
    void set_ceo_name(char tmp[]) { strcpy(ceo_name, tmp); };

    companies(const companies & copy)
    {
        companies_name = new char[strlen(copy.get_companies()) + 1];
        strcpy(companies_name, copy.get_companies());
        ceo_name = new char[strlen(copy.get_companies()) + 1];
        strcpy(ceo_name, copy.get_ceo());
        income = copy.get_income();
        day = copy.get_day();
    }

    ~companies()
    {  
        delete[]companies_name;
        delete[]ceo_name;
    }
};