#include "Header.h"
#include <iostream>
#include <ctime>
#include <cstring>



party::party() {
	name = nullptr;
	country_to_visit = nullptr;
	id = new int;
	*id = rand() % 100000;
	cost = new mass;
	cost->len = 0;
	cost->info = nullptr;
}

party::~party() {
	//delete []name;
	//delete [] country_to_visit;
	for (int i = 0; i < cost->len; i++) {
		//delete[] cost->info[i].name;
	}
	delete cost->info;
	delete cost;
	delete id;
}


party::party(const party &obj) {
	/*if (obj.name) {

		name = new char[strlen(obj.name)];
		strcpy(name, obj.name);
	}
	else name = nullptr;
	if (obj.country_to_visit) {
		country_to_visit = new char[strlen(obj.country_to_visit)];
		strcpy(country_to_visit, obj.country_to_visit);
	}
	else country_to_visit = nullptr;
	cost = new mass;
	cost->len = obj.cost->len;
	cost->info = nullptr;
	if (cost->len) cost->info = (add_cost*)realloc(cost->info, cost->len * sizeof(add_cost));
	else cost->info = nullptr;
	for (int i = 0; i < cost->len; i++) {
		cost->info[i] = add_cost();
		cost->info[i].price = obj.cost->info[i].price;
		cost->info[i].name = new char[strlen(obj.cost->info[i].name)];
		strcpy(cost->info[i].name, obj.cost->info[i].name);
	}
	if (obj.id) {
		id = new int;
		*id = *obj.id;
	}*/
}

void party::fill_list() {
	char name_[35], *name;
	int price;
	std::cout << "now you are filling list with clients orders.\n You can leave by pressing [Enter] instead of name";
	do {
		std::cout << "\nenter name [Enter] price\n ";
		std::cin >> name_ >> price;
		if (strcmp(name_, "0") == 0)
			break;
		cost->info = (add_cost *)realloc(cost->info, (cost->len + 1) * sizeof(add_cost));

		cost->info[cost->len].price = price;
		name = new char[strlen(name_)];
		strcpy(name, name_);
		cost->info[cost->len].name = name;
		std::cout << " new order " << name << " --//-- " << price << "$";
		cost->len++;
	} while (true);
}


char * party::get_name() {
	return name;
}

void party::view() {
	std::cout << "ID " << *id << " name" << name << " country to visit " << country_to_visit;
	for (int i = 0; i < cost->len; i++) {
		std::cout << cost->info[i].name << " --//-- " << cost->info[i].price << "$";
	}
}

std::ostream &operator << (std::ostream &stream, party obj) {
	int money = 0;
	stream << "ID " << *obj.id << "\nname " << obj.name << "\ncountry you want to visit " << obj.country_to_visit;
	for (int i = 0; i < obj.cost->len; i++) {
		stream << " \n" << obj.cost->info[i].name << " --//-- " << obj.cost->info[i].price << " $";
		money += obj.cost->info[i].price;
	}
	if (money) stream << "\n" << money << " $";
	return stream;
}

std::istream &operator >> (std::istream &stream, party &obj) {
	char name_[20], c_name_[20];
	//obj.cost->len = 0; // ��������
	std::cout << "\nenter name ";
	stream >> name_;
	obj.name = new char[strlen(name_)];
	strcpy(obj.name, name_);
	std::cout << "enter country client likes to visit ";
	stream >> c_name_;
	obj.country_to_visit = new char[strlen(c_name_)];
	strcpy(obj.country_to_visit, c_name_);
	return stream;
}

void * party::operator new(rsize_t size) {
	std::cout << "overload new for one obj";
	void *p;
	p = malloc(size);
	if (!p) {
		std::bad_alloc ba;
		throw ba;
	}
	return p;
}

void * party::operator new[](rsize_t size) {
	std::cout << "overload new for array";
	void *p;
	p = malloc(size);
	if (!p) {
		std::bad_alloc ba;
		throw ba;
	}
	return p;
}

void party::operator delete(void *p) {
	std::cout << "overload delete";
	free(p);
}
void party::operator delete[](void *p) {
	std::cout << "overload delete[]";
	free(p);
}

party party::operator=(party ob) {
	std::cout << "\n=";
	if (ob.name) {
		name = new char[strlen(ob.name)];
		strcpy(name, ob.name);
	}
	else name = nullptr;
	if (ob.country_to_visit) {
		country_to_visit = new char[strlen(ob.country_to_visit)];
		strcpy(country_to_visit, ob.country_to_visit);
	}
	else country_to_visit = nullptr;
	cost = new mass;
	cost->len = ob.cost->len;
	if (ob.cost->len)cost->info = (add_cost*)realloc(cost->info, ob.cost->len * sizeof(add_cost));
	else cost->info = nullptr;
	for (int i = 0; i < cost->len; i++) {
		cost->info[i] = add_cost();
		cost->info[i].name = (char*)realloc(cost->info[i].name, strlen(ob.cost->info[i].name));
		strcpy(cost->info[i].name, ob.cost->info[i].name);
		cost->info[i].price = ob.cost->info[i].price;
	}
	if (ob.id) {
		id = new int;
		*id = *ob.id;
	}
	else id = nullptr;
	return *this;
}

double money_per_people(party ob) {
	int total = 0, number_of_people;
	double money_per_people;
	std::cout << "enter number of people";
	std::cin >> number_of_people;
	for (int i = 0; i < ob.cost->len; i++) {
		total += ob.cost->info[i].price;
	}
	money_per_people = static_cast<double>  (total) / number_of_people;
	return money_per_people;
}

add_cost & party::operator[](int i) {
	std::cout << "overload[]";
	if (i < 0 || i >= cost->len) {
		std::cout << "out of range";
		exit(1);
	}
	else return cost->info[i];
}




/*party & party::operator[](int i) {
	if (i < 0 || i >= 5) {
		std::cout << "out of range";
		exit(1);
	}
	else return *this;
}*/

void party::retatd_func() {
	std::cout << &cost->info[cost->len].price;
}

///////////////////////////// ������������
/*
mainparty::mainparty() {
	std::cout << "\nmainparty def";
	c_name = nullptr;
}

mainparty::~mainparty() {
	std::cout << "\nmainparty des";
	delete c_name;
}*/







/*mainparty::~mainparty() {
	delete c_name;
}*/

/*mainparty::mainparty() {
	c_name = nullptr;
}*/
