#include "Header.h"
#include <cstring>

aditional_cost ::aditional_cost() {
	std::cout << "additional cost DEF ";
}

aditional_cost::~aditional_cost() {
	price.clear();
	prod_name.clear();
	std::cout << "aditional_cost DES";
}

void aditional_cost::fill() {
	std::cout << "aditional cost fill";
	std::string name_;
	double cost;
	std::cout << "now you are filling list with clients orders.\n You can leave by pressing [Enter] instead of name";
	do {
		std::cout << "\nenter name [Enter] price\n ";
		std::cin >> name_ >> cost;
		if (name_.compare("0") == 0)
			break;
		price.push_back(cost);
		prod_name.push_back(name_);
		state.push_back("\0");
		std::cout << " new order " << name_ << " --//-- " << cost << "$";
	} while (true);
}

void aditional_cost::view() {
		std::list<double>::iterator price_ = price.begin();
		std::list<std::string>::iterator name_ = prod_name.begin();
		std::list<std::string>::iterator sale = state.begin();
		for (; price_ != price.end(); name_++, price_++, sale++) {
			std::cout << "\n" << *name_ << " -- " << *price_ << " $";
			if (*sale == "sale") std::cout << " 20% off";
		}
}