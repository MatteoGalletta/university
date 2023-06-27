/*
 * read_file.cpp
 */
#include <iostream>
#include <fstream>

using namespace std;

void bubblesort(int * a, int n)
{
	bool done = true;
	do {
		done = true;
		for (int i = 0; i < n-1; i++) {
			if (a[i] > a[i+1]) {
				int tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
				done = false;
			}
		}
	} while (!done);
}

int main(int argc, char *argv[])
{
	ifstream myfile; // FILE * myfile
	myfile.open("numeri.txt");	// myfile = fopen("numeri.txt", "r");
	int n;
	myfile >> n;
	int * dati = new int[n];
	for (int i = 0; i < n; i++) {
		myfile >> dati[i];
		cout << dati[i] << endl;
	}
	myfile.close();	// fclose(myfile);
	
	bubblesort(dati, n);
	
	ofstream outfile;
	outfile.open("numeri_ordinati.txt");
	outfile << n << endl;
	for (int i = 0; i < n; i++) {
		outfile << dati[i] << endl;
	}
	outfile.close();
	return 0;
}

