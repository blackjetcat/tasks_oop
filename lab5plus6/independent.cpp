#include "Header.h"

independent::independent()
{
	std::cout << "independent DEF ";
}

void independent::fill() {
	std::cout << "\nenter name ";
	std::cin >> name;
	std::cout << "enter country name ";
	std::cin >> c_name;
}

void independent::view() {
	std::cout << "name " << name;
}

independent::~independent() {
	std::cout << "independent DES ";
	name.erase();
}

std::string independent::get_name() {
	return name;
}

std::string independent::get_c_name() {
	return c_name;
}

void independent::get_sale() {  // снижает стоимость(проверка на статус) и делает статус
	if (!price.empty()) {
		std::list<double>::iterator price_ = price.begin();
		std::list<std::string>::iterator prod_name_ = prod_name.begin();
		std::list<std::string>::iterator state_ = state.begin();
		for (; price_ != price.end(); price_++, prod_name_++, state_++) {
			if (*state_ != "sale")
			{
				*price_ *= 0.8;
				*state_ = "sale";
			}
		}
	}
}

std::istream &operator >> (std::istream &stream, independent &obj) {
	std::cout << "enter name ";
	stream >> obj.name;
	std::cout << "enter country ";
	stream >> obj.c_name;
	return stream;
}
