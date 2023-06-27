/*
 * lista_3.cpp
 * lista semplicemente collegata in C++
 */
#include <iostream>
#include <string>

using namespace std; 

class Nodo {
	string elem;
public:
	Nodo() : elem(""),next(nullptr) { };
	Nodo(string e) : elem(e),next(nullptr) { };
	string get() { return elem; };
	void insert(string data);
	void delete_first();
	void delete_element(string data);
	void show(ostream & output = cout);
	bool exist(string data);

	Nodo * next;
};

typedef Nodo List;

void Nodo::insert(string data)
{
	Nodo * nuovo_nodo = new Nodo(data);
	nuovo_nodo->next = this->next;
	this->next = nuovo_nodo;
}

void Nodo::delete_first()
{
	Nodo * first = this->next;
	
	Nodo * new_first = first->next;
	
	delete first;
	
	this->next = new_first;
}


void Nodo::show(ostream & output)
{
	Nodo * p = this->next;
	while (p != nullptr) {
		output << p->get() << endl;		
		p = p->next;
	}
}

bool Nodo::exist(string data)
{
	Nodo * p = this->next;	
	while (p != nullptr) {
		if (p->get() == data)
			return true;
		p = p->next;
	}
	return false;
}

void Nodo::delete_element(string data)
{
	Nodo * current = this->next;
	Nodo * prev = this;	
	while (current != nullptr) {
		if (current->get() == data) {
			// dato trovato
			prev->next = current->next;
			delete current;
			return;
		}
		current = current->next;
		prev = prev->next;
	}
}

ostream & operator<<(ostream & output, Nodo & n)
{
	n.show(output);
	return output;
}

int main(int argc, char ** argv)
{
	List mylist;

	mylist.insert("Corrado");	
	mylist.insert("Giuseppe");	
	mylist.insert("Maria");	
	
	cout << mylist << endl;
	
	if (mylist.exist("Giuseppe"))
		cout << "'Giuseppe' trovato" << endl;

	cout << endl;
	
	//mylist.delete_first();
	//mylist.delete_first();
	
	mylist.delete_element("Maria");
	
	mylist.show();

	//if (mylist.exist("Giuseppe"))
	//	cout << "'Giuseppe' trovato" << endl;
}

