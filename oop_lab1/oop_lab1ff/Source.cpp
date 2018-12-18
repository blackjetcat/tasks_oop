#include <iostream>



using namespace std;

struct ddata
{	char *name;
	int id;
	int date;
	float *finances;
	int pnumber;

};

struct Stack
{
	ddata d;
	Stack *next;
	Stack *head;
};

void add(Stack * s)
{
	ddata d;
	d.finances = new float[2];
	Stack * tmp = new Stack;
	char buffer[100] = { '\0' };
	cout << "Name of a company: ";
	cin >> buffer;
	int size;
	size = strlen(buffer);
	d.name = (char*)malloc(size + 1);

	strcpy(d.name, buffer);

	cout << "Income: ";
	cin >> d.finances[0];
	cout << "Outcome: ";
	cin >> d.finances[1];
	cout << "ID in system: ";
	cin >> d.id;
	cout << "Year of registration: ";
	cin >> d.date;
	cout << "Phone number: ";
	cin >> d.pnumber;

	tmp->next = s->head;

	tmp->d.name = d.name;
	tmp->d.finances = d.finances;
	tmp->d.date = d.date;
	tmp->d.id = d.id;
	tmp->d.pnumber = d.pnumber;
	s->head = tmp;
}

void show(Stack * s)
{
	Stack *tmp = s->head;
	while (tmp != NULL)
	{
		cout << "Name of a company: ";
		for (int i = 0; i < strlen(tmp->d.name); i++)
		{
			cout << tmp->d.name[i];

		}
		cout << endl;
		cout << "Income: " << tmp->d.finances[0] << endl;
		cout << "Outcome: " << tmp->d.finances[1] << endl;
		cout << "Year of registration: " << tmp->d.date << endl;
		cout << "ID in system: " << tmp->d.id << endl;
		cout << "Phone number: " << tmp->d.pnumber << endl;
		tmp = tmp->next;
	}
}

void wfile(Stack * s, FILE * file)
{
	Stack *tmp = s->head;
	while (tmp != NULL)
	{
		fprintf(file, "%s\n", "Company");
		cout << tmp->d.finances[0];
		cout << tmp->d.finances[1];
		cout << tmp->d.id;
		cout << tmp->d.pnumber;

		fprintf(file, "%s;%d;%4.2f;%4.2f;%i;%i\n", tmp->d.name, tmp->d.date, tmp->d.finances[0], tmp->d.finances[1], tmp->d.id, tmp->d.pnumber);
		tmp = tmp->next;
	}
}

void ClearStack(Stack * s)
{
	while (s->head != NULL)
	{

		Stack * tmp = s->head->next;
		delete s->head;
		s->head = tmp;
	}
}
int main()
{
	FILE * file = NULL;
	fopen_s(&file, "text.txt", "w+");
	if (file == NULL)
	{
		cerr << "file not found" << endl;
		system("pause");
		exit(1);
	}

	Stack * stack = new Stack;
	stack->head = NULL;


	while (true)
	{
		setlocale(LC_ALL, "");
		char choice;

		cout << "1)Add to stack" << endl;
		cout << "2)Output" << endl;
		cout << "3)Clear stack" << endl;
		cout << "4)Output to file" << endl;
		cout << "5)Exit" << endl;
		cin >> choice;
		while (!cin.good())
		{
			cin.ignore();
			cin.clear();
			system("clear");
			cin >> choice;
		}
		switch (choice)
		{
		case '1':
			add(stack);
			break;
		case '2':
			show(stack);
			break;
		case '3':
			ClearStack(stack);
			break;
		case '4':
			wfile(stack, file);
			break;
		case '5':
			return 0;
			break;
		}

	}

}