/*
 * map_example.cpp
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char ** argv)
{
	// key = matricola (string)
	// value = nome+cognome (string)
	// map<tipo della chiave, tipo del valore>
	map<string, string> database;
	
	database["X81000100"] = "Mario Rossi";
	database["X81000101"] = "Giuseppe Verdi";
	database["X81000102"] = "Salvatore Bianchi";
	
	cout << database["X81000100"] << endl;
	cout << database["X81000101"] << endl;
	cout << database["X81000102"] << endl;
}

