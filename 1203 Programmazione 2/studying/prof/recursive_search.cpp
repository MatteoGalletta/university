/*
 * recursive_sum.cpp
 */
 
#include <iostream>
#include <cstdlib>

using namespace std;

bool search(int * data, int n, int val)
{
	if (n == 0)
		return false;
	if (val == data[0])
		return true;
	else
		return search(data + 1, n - 1, val);
}

bool search(int * data, int n, int val)
{
	for (int i = 0; i < n;i++) {
		if (data[i] == val)
			return true;
	}
	return false;
}

#define N 10

int main(int argc, char **argv)
{
    srand(time(NULL));
    int data[N];
    for (int i = 0; i < N; i++) {
        data[i] = (int)((float)rand() / RAND_MAX * 50);
    }
    
    for (int i = 0; i < N; i++) {
        cout << " " << data[i];
    }
    cout << endl;
    
    int val_to_search;
    cout << "Inserisci valore da cercare:";
    cin >> val_to_search;
    
    cout << search(data, N, val_to_search) << endl;
    
    return 0;    

}

