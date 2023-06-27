/*
 * lista_2.cpp
 * lista semplicemente collegata, con elemento fittizio
 */
#include <iostream>
#include <string>

using namespace std; 

class Nodo {
	string elem;
public:
	Nodo(string e) : elem(e),next(nullptr) { };
	string get() { return elem; };

	Nodo * next;
};

typedef Nodo * List;

void insert(List l, string data)
{
	Nodo * nuovo_nodo = new Nodo(data);
	nuovo_nodo->next = l->next;
	l->next = nuovo_nodo;
}

void delete_first(List l)
{
	Nodo * first = l->next;
	
	Nodo * new_first = first->next;
	
	delete first;
	
	l->next = new_first;
}


void show(List the_list)
{
	Nodo * p = the_list->next;
	
	while (p != nullptr) {
	
		cout << p->get() << endl;
		
		p = p->next;
	}
}

int main(int argc, char ** argv)
{
	List mylist = new Nodo("");

	insert(mylist, "Corrado");	
	insert(mylist, "Giuseppe");	
	insert(mylist, "Maria");	
	
	show(mylist);

	cout << endl;
	
	delete_first(mylist);
	delete_first(mylist);
	
	show(mylist);

}

