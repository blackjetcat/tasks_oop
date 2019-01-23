#include "Header.h"

not_independent::not_independent() {
	name = "\0";
	c_name = "\0";
	std::cout << "not_independent DEF";
}

not_independent::~not_independent() {
	name.erase();
	c_name.erase();
	std::cout << "not independent DES ";
}

void not_independent::fill() {
	std::cout << "enter name ";
	std::cin >> name;
	std::cout << "enter country name ";
	std::cin >> c_name;
}

void not_independent::view() {
	std::cout << name;
	std::cout << c_name;
}

std::string not_independent::get_name() {
	return name;
}

std::string not_independent::get_c_name() {
	return c_name;
}

std::istream &operator >> (std::istream &stream, not_independent &obj) {
	std::cout << "enter name ";
	stream >> obj.name;
	std::cout << "enter country ";
	stream >> obj.c_name;
	return stream;
}