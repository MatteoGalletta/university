/*
 * lista_1.cpp
 */
#include <iostream>
#include <string>

using namespace std; 

class Nodo {
	string elem;
public:
	Nodo(string e) : elem(e) { };
	string get() { return elem; };

	Nodo * next;
};

typedef Nodo * List;

void insert(List & l, string data)
{
	Nodo * nuovo_nodo = new Nodo(data);
	nuovo_nodo->next = l;
	l = nuovo_nodo;
}

void delete_first(List & l)
{
	Nodo * first = l;
	Nodo * new_first = l->next;
	
	delete first;
	
	l = new_first;
}


void show(List the_list)
{
	while (the_list != nullptr) {
	
		cout << the_list->get() << endl;
		
		the_list = the_list->next;
	}
}

int main(int argc, char ** argv)
{
	List mylist = nullptr;

	insert(mylist, "Corrado");	
	insert(mylist, "Giuseppe");	
	insert(mylist, "Maria");	
	
	show(mylist);
	
	cout << endl;
	
	delete_first(mylist);
	delete_first(mylist);
	
	show(mylist);
}

