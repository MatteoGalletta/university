/*
 * test_list_2.cpp
 */
 
#include <iostream>
#include <string>
#include "list.h"

using namespace std;

class Persona {
	string nome;
	string cognome;
	int  eta;
public:
	Persona() : nome(""), cognome(""), eta(0) {};
	
	Persona(string _nome, string _cognome, int _eta) :
		nome(_nome), cognome(_cognome), eta(_eta) {};
		
	Persona(Persona & p) :
		nome(p.nome), cognome(p.cognome), eta(p.eta) {};
		
	bool operator==(Persona & rhs) {
		if (nome == rhs.nome && cognome == rhs.cognome && eta == rhs.eta)
			return true;
		else
			return false;
	};
	
	bool operator<(Persona & rhs) {
		// true se this < rhs
		// false negli altri casi
		if (cognome < rhs.cognome) return true;
		if (cognome == rhs.cognome) {
			if (nome < rhs.nome) return true;
			if (nome == rhs.nome) {
				if (eta < rhs.eta) return true;
			}
		}
		return false;
	};
	
	friend ostream& operator<<(ostream& out, const Persona & p);
};

ostream& operator<<(ostream& out, const Persona & p)
{
	out << "(" << p.nome << "," << p.cognome << "," << p.eta << ")";
	return out;
}

int main(int argc, char **argv)
{
	OrderedList<Persona> mylist;
	
	mylist.insert(Persona("Mario", "Rossi", 30));
	mylist.insert(Persona("Giuseppe", "Verdi", 25));
	mylist.insert(Persona("Salvatore", "Bianchi", 20));
	mylist.insert(Persona("Giuseppe", "Rossi", 40));
	
	mylist.show();
	cout << endl;
	
	mylist.delete_element(Persona("Salvatore", "Bianchi", 20));

	mylist.show();
		
	return 0;
}

