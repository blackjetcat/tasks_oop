#include "Header.h"

template <typename T> void _input(const std::string & massage, T & in) {
	std::cout << massage;
	std::cin >> in;
	while (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "input error\n input again: " << massage;
		std::cin >> in;
	}
}

int main() {
	setlocale(LC_ALL, "");
	/*int pointer = 0, action, number_of_cients = 0, range, type1, type2, desition = 1;
	long int adress;
	char * adress_c = new char[30];
	//char adress[30];
	party * client = nullptr;//new party;
	party * adr = nullptr;
	party * p_boy = new party();
	do {
		//std::cout << "\n1) add dude(new) 2) add multiply dudes(new[]) 3) select 4) view client 5)fill 6)delete\n 7)calculate money per people 8)get adress 9)dumb function 10)set id\n";
		std::cout << "\n1) add dude(new) 2) add multiply dudes(new[]) 3) select 4) view client 5)fill 6)delete\n 7)calculate money per people 8)get adress 9)dumb function 10)set id\n";
		std::cin >> action;
		switch (action)
		{
		case 1:
			if (client) break;
			desition = 1;
			/*client = (party*)realloc(client, (number_of_cients+1 ) * sizeof(party));
			client[number_of_cients] = party();
			//client = new (client) party[number_of_cients + 1];
			std::cin >> client[number_of_cients];
			number_of_cients++;
			try
			{
				client = new party;
			}
			catch (std::bad_alloc ba)
			{
				std::cout << "error";
				break;
			}
			std::cin >> *client;
			number_of_cients = 1;
			break;
		case 2:
			if (client) break;
			desition = 0;
			std::cout << "enter number of clients ";
			std::cin >> range;
			/*client = (party*)realloc(client, (number_of_cients + range) * sizeof(party));
			for (int i = number_of_cients; i < number_of_cients + range; i++) {
				client[i] = party();
				std::cout <<"\n" << i << ")";
				std::cin >> client[i];
			}
			//if (range > 0) number_of_cients += range;
			try {
				client = new party[range];
			}
			catch (std::bad_alloc ba) {
				std::cout << "error";
				break;
			}
			if (!range) break;
			for (int i = 0; i < range; i++) {
				std::cin >> client[i];
			}
			number_of_cients = range;
			break;
		case 3:
			if (!client)break;
			for (int i = 0; i < number_of_cients; i++) {
				std::cout << i << ")" << client[i].get_name() << "\n";
			}
			std::cin >> pointer;
			if (pointer >= number_of_cients || pointer < 0) pointer = 0;
			std::cout << client[pointer].get_name() << "--------------";
			break;
		case 4:
			std::cout << client[pointer];
			break;
		case 5:
			client[pointer].fill_list();
			break;
		case 6:
			std::cout << "\nthis func is not working";
			break;
		case 7:
			std::cout << "\n" << money_per_people(client[pointer]) << "$";
			break;
		case 8:
			//adress = reinterpret_cast<long int> (&client[pointer]);
			adress_c = reinterpret_cast<char *>(&client[pointer]);
			//strcpy(adress_c, reinterpret_cast<char *>(&client[pointer]));
			std::cout << "\nadress " << &adress_c;
			//std::cout << "\n" << adress;
			//adr = reinterpret_cast<party *> (adress);
			adr = reinterpret_cast<party *>(adress_c);
			std::cout << "\n" << adr->get_name();
			break;
		case 9:
			client[pointer].retatd_func();
			//client[-1].get_name();
			break;
		case 10:
			int id;
			std::cout << "enter new id";
			std::cin >> id;
			client[pointer](id);
			//std::cout << "coming soon";
			break;
		default:break;
		}
	} while (action > 0 && action < 11);
	if (desition)delete client;
	else delete[] client;*/
	/*std::allocator<std::string> test;
	std::string * test_str = test.allocate(5);
	test.construct(test_str + 1, "01234");
	std::cout << test_str->end();*/

	//independent * p;
	mainparty * point = nullptr;
	int /*ind_num = 1, not_ind_num = 1,*/ pointer = 0, indquestion = 0, obj_num = 0;
	//bool indquestion;
	/*std::cout << "введите количество самостоятельных пользователей";
	std::cin >> ind_num;
	std::cout << "enter number of";
	std::cin >> not_ind_num;*/
	std::vector<independent> ind;
	std::vector<not_independent> not_ind;
	std::string name;
	//auto ind = new independent[ind_num];
	//auto not_ind = new not_independent[not_ind_num];
	std::cin >> pointer;
	do {
		std::cout << "\n 1)add 2)select 3)change 4)view all 5)search 6)get sale 7)fill add cost 8)fill default cost 9)view one\n";
		//std::cin >> pointer;
		_input("enter action ", pointer);
		switch (pointer)
		{
		case 1:
			std::cout << "0) add independent 1)add not independent 2)skip ";
			//std::cin >> indquestion;
			_input("chose type ", indquestion);
			if (!indquestion) {
				auto obji = new independent;
				obji->fill();
				ind.push_back(*obji);
				obj_num = ind.size() - 1;
			}
			else {
				auto obji2 = new not_independent();
				obji2->fill();
				not_ind.push_back(*obji2);
				obj_num = ind.size() - 1;
			}
			break;
		case 2: std::cout << "0)independent 1)not independent";
			//std::cin >> indquestion; // 0 - independent 1 - not independent
			_input("chose type", indquestion);
			switch (indquestion)
			{
			case 0:
				for (int i = 0; i < (int)ind.size(); i++) {
					std::cout << i << ")" << ind[i].get_name() << "\n";
				}
				//std::cin >> obj_num;
				_input("input number", obj_num);
				if (obj_num >= 0 && obj_num < (int)ind.size()) {
					point = &ind[obj_num];
					std::cout << ind[obj_num].get_name() << "------------";
				}
				break;
			case 1:
				for (int i = 0; i < (int)not_ind.size(); i++) {
					std::cout << i << ")" << not_ind[i].get_name() << "\n";
				}
				//std::cin >> obj_num;
				_input("input number", obj_num);
				if (obj_num >= 0 && obj_num < (int)not_ind.size()) {
					point = &not_ind[obj_num];
					std::cout << not_ind[obj_num].get_name() << "------------";
				}
				break;
			default: std::cout << "you entered an invalid value";
				break;
			}
			break;
		case 3:
			if (point)point->fill();
			break;
		case 4:
			if (!ind.empty()) {
				std::cout << "\nindependent \n";
				for (int i = 0; i < (int)ind.size(); i++) {
					std::cout << "\n" << i << ")" << ind[i].get_name() << " " << ind[i].get_c_name();
				}
			}
			if (!not_ind.empty()) {
				std::cout << "\nnot independent \n";
				for (int i = 0; i < (int)ind.size(); i++) {
					std::cout << "\n" << i << ")" << not_ind[i].get_name() << " " << ind[i].get_c_name();
				}
			}
			break;
		case 5:
			std::cout << "search";
			break;
		case 6:
			if (indquestion) std::cout << "sale is not supported";
			else {
				if (!ind.empty())
					ind[obj_num].get_sale();
			}
			break;
		case 7:
			if (indquestion) std::cout << "add cost is not supported";
			else {
				if (!ind.empty())
					ind[obj_num].aditional_cost::fill();
				std::cout << "sale activated";
			}
			break;
		case 8:
			//point->default_cost::fill();
			if (indquestion && !not_ind.empty()) not_ind[obj_num].default_cost::fill();
			else if (!ind.empty())ind[obj_num].default_cost::fill();
			break;
		case 9:
			if (indquestion && !not_ind.empty()) {
				not_ind[obj_num].view();
				not_ind[obj_num].default_cost::view();
				//not_ind[obj_num].aditional_cost::view();
			}
			else {
				if (ind.empty()) break;
				ind[obj_num].view();
				ind[obj_num].default_cost::view();
				ind[obj_num].aditional_cost::view();
			}
		default:
			break;
		}
	} while (pointer > 0 && pointer < 10);
	/*auto obj = new independent;
	obj->fill();
	obj->aditional_cost::fill();
	obj->default_cost::fill();
	delete obj;*/
	std::cout << "\n";
	//delete[] ind;
	ind.clear();
	not_ind.clear();
	std::cout << "\n";
	//delete[] not_ind;
	system("pause");
	return 0;
}

