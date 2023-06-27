/*
 * map_example.cpp
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>

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
	
	/*
	cout << database["X81000100"] << endl;
	cout << database["X81000101"] << endl;
	cout << database["X81000102"] << endl;
	*/
	
	// creazione vettore delle chiavi del nostro database
	vector<string> keys;
	for (map<string, string>::iterator it = database.begin(); it != database.end(); it++) {
		keys.push_back(it->first);
	}
	
	for (vector<string>::iterator it = keys.begin(); it != keys.end(); it++) {
		cout << *it << "," << database[*it] << endl;
	}
}


