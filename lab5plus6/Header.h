#pragma once
#pragma once
#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cstring>



struct default_list {
	char spa[40];
	int stars;
	int food;
	int date;
	int days;
	int num_of_people;
	char comment[600];
};

class price_list {
	char spa[40];
	int stars;
	int food;
	int date;
	int days;
	int num_of_people;
	char comment[600];
public:
};

struct add_cost {
	int price;
	char * name;
};

struct mass {
	add_cost * info;
	int len;
};

class vector {
	int len;
	add_cost * info;
};

class party {
	//default_list list;
	mass * cost;
	char * name;
	char * country_to_visit;
	int *id;
public:
	add_cost & operator[](int);
	//party & operator[](int);
	party & operator()(int i) {
		*id = i;
		return *this;
	};
	void *operator new(rsize_t);
	void *operator new[](rsize_t);
	void operator delete(void *);
	void operator delete[](void *);
	friend double money_per_people(party);
	friend std::ostream &operator<<(std::ostream &, party);
	friend std::istream &operator>>(std::istream &, party &);
	void view();
	party();
	party(const party &);
	~party();
	void retatd_func();
	//void set_name(char *);
	//void set_c_name(char *);
	//int get_id();
	char * get_name();
	void fill_list();
	party operator=(party);
	party * operator+(party *);
	bool operator==(party *);
	party * operator+(char *);
};

template <class T> void _input(const std::string &, T &);

/////////////// наследование

class mainparty {
	//char * c_name;
public:
	//mainparty();
	virtual void fill() = 0;
	virtual void view() = 0;
	virtual ~mainparty() = default;
};

class aditional_cost :virtual public mainparty {
protected:
	std::list<double> price;
	std::list<std::string> prod_name;
	std::list<std::string> state;
	int len;
public:
	void fill();
	void view();
	aditional_cost();
	~aditional_cost();
};


class default_cost : virtual public mainparty {
protected:
	char spa[40];
	int stars;
	int food;
	int date;
	int days;
	int num_of_people;
	char comment[600];
public:
	default_cost();
	~default_cost();
	void fill();
	void view();
};

class independent :public aditional_cost, public default_cost {
    std::string name;
    std::string c_name;
public:
    friend std::istream &operator>>(std::istream &, independent &);

    void fill();
    independent();
    ~independent();
    void get_sale();
    std::string get_name();
    std::string get_c_name();
    void view();
};

class not_independent : public default_cost {
	std::string name;
	std::string c_name;
public:
	friend std::istream &operator>>(std::istream &, not_independent &);
	std::string get_name();
	std::string get_c_name();
	void fill();
	void view();
	not_independent();
	~not_independent();
};
