/*
 * recursive_min.cpp
 */
 
#include <iostream>
#include <cstdlib>

using namespace std;
 
float rec_min(float temp_min, float * data, int n)
{
	if (n == 0)
		return temp_min;
	
	if (data[0] >= temp_min)
		return rec_min(temp_min, data + 1, n - 1);
	else
		return rec_min(data[0], data + 1, n - 1);
}

float rec_min(float * data, int n)
{
	return rec_min(data[0], data + 1, n - 1);
}

#define N 10

int main(int argc, char **argv)
{
    srand(time(NULL));
    float data[N];
    for (int i = 0; i < N; i++) {
        data[i] = ((float)rand() / RAND_MAX * 50);
    }
    
    for (int i = 0; i < N; i++) {
        cout << " " << data[i];
    }
    cout << endl;
    
    cout << rec_min(data, N) << endl;
    
    return 0;    

}


