/*
 * recursive_sum.cpp
 */
 
#include <iostream>
#include <cstdlib>

using namespace std;

int sum(int * data, int n)
{
	if (n == 0)
		return 0;
	else
		return data[0] + sum(data + 1, n - 1);
}

#define N 10

int main(int argc, char **argv)
{
    srand(time(NULL));
    int data[N];
    for (int i = 0; i < N; i++) {
        data[i] = (int)((float)rand() / RAND_MAX * 50);
    }

    int somma = sum(data, N);
    
    for (int i = 0; i < N; i++) {
        cout << " " << data[i];
    }
    cout << endl << "SOMMA = " << somma << endl;
    
    return 0;    

}

