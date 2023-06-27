/*
 * test_list_3.cpp
 */
 
#include <iostream>
#include <string>
#include "list.h"

using namespace std;

class Studente {
	string matricola;
	string nome;
	string cognome;
public:
	Studente() : matricola(""), nome(""), cognome("") {};
	
	Studente(string _matricola, string _nome = "", string _cognome = "") :
		matricola(_matricola), nome(_nome), cognome(_cognome) {};
		
	Studente(Studente & p) :
		matricola(p.matricola), nome(p.nome), cognome(p.cognome) {};
		
	bool operator==(Studente & rhs) {
		return (matricola == rhs.matricola);
	};
	
	bool operator<(Studente & rhs) {
		// true se this < rhs
		// false negli altri casi
		// (ordinamento solo su nome e cognome)
		if (cognome < rhs.cognome) return true;
		if (cognome == rhs.cognome) {
			if (nome < rhs.nome) return true;
		}
		return false;
	};
	
	friend ostream& operator<<(ostream& out, const Studente & p);
};

ostream& operator<<(ostream& out, const Studente & p)
{
	out << "(" << p.matricola << "," << p.nome << "," << p.cognome << ")";
	return out;
}

int main(int argc, char **argv)
{
	OrderedList<Studente> mylist;
	
	mylist.insert(Studente("10001", "Mario", "Rossi"));
	mylist.insert(Studente("10002", "Giuseppe", "Verdi"));
	mylist.insert(Studente("10003", "Salvatore", "Bianchi"));
	//mylist.insert(Studente("10004", "Giuseppe", "Rossi"));
	
	mylist.show();
	cout << endl;
	
	mylist.delete_element(Studente("10003"));

	mylist.show();
	cout << endl;
	
	Studente * s = mylist.find(Studente("10004"));
	if (s == nullptr) 
		cout << "matricola 10004 NON presente" << endl;
	else
		cout << (*s) << endl;
		
	return 0;
}

