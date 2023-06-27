/*
 * test_set.cpp
 */
 
#include <iostream>
#include <cstring>
#include "set.h"

using namespace std;

class Persona {
	char nome[40];
	char cognome[40];
public:
	Persona() {
		nome[0] = 0;
		cognome[0] = 0;
	};
	Persona(const char * _nome, const char * _cognome) {
		strcpy(nome, _nome);
		strcpy(cognome, _cognome);
	};
	Persona(Persona & p) {
		strcpy(nome, p.nome);
		strcpy(cognome, p.cognome);
	};
	bool operator==(Persona & rhs) {
		if (strcmp(nome, rhs.nome) == 0 && strcmp(cognome, rhs.cognome) == 0)
			return true;
		else
			return false;
	};
	friend ostream& operator<<(ostream& out, Persona & p);
};

ostream& operator<<(ostream& out, Persona & p)
{
	out << p.nome << " " << p.cognome ;
	return out;
}

int main(int argc, char **argv)
{
	SetDuplicates<int> s;
	s += 20; // s = s + 20;
	s += 2;
	s += 50;
	s += 30;
	s += 50;
	s += 10.5;
	cout << "S: ";
	s.show();
	
	SetDuplicates<float> s2;
	s2 += 10.3;
	s2 += 4.5;
	cout << "S2: ";
	s2.show();
	
	SetDuplicates<Persona> s3;
	s3 += Persona("Mario", "Rossi");
	s3 += Persona("Giuseppe", "Verdi");
	cout << "S3: ";
	s3.show();
	
	s3 -= Persona("Mario", "Rossi");
	cout << "S3: ";
	s3.show();
	
	return 0;
}

