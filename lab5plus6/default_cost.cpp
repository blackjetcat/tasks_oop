#include "Header.h"

default_cost::~default_cost() {
	std::cout << "default_cost DES ";
}

default_cost::default_cost() {
	stars = food = date = days = num_of_people = 0;
	std::cout << "default_cost DEF ";
}

void default_cost::view() {
	std::cout << "\nspa " << spa << "\ndate " << date << "\ndays " << days << "\nnumber of people " << num_of_people << "\nhotel stars " << stars << "\nfood set " << food << "\ncomment " << comment;
}

void default_cost::fill() {
	std::cout << "spa ";
	std::cin >> spa;
	std::cout << "stars ";
	std::cin >> stars;
	std::cout << "food set ";
	std::cin >> food;
	std::cout << "date ";
	std::cin >> date;
	std::cout << "days ";
	std::cin >> days;
	std::cout << "number_of_people ";
	std::cin >> num_of_people;
	std::cout << "comment ";
	std::cin >> comment;
}