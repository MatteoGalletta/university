/*
 * selectsort.cpp
 */

#include <iostream>
#include <cstdlib>

using namespace std;


template <typename T> void _swap(T& a, T& b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T> void selectsort(T * data, int n)
{
    for (int i = 1; i < n; i++) {
        int least_index = i;
        for (int j = i; j < n; j++) {
            if (data[j] < data[least_index])
                least_index = j;
        }
        _swap<T>(data[i-1], data[least_index]);
    }
}

#define N 20

int main(int argc, char **argv)
{
    srand(time(NULL));
    float data[N];
    for (int i = 0; i < N; i++) {
        data[i] = ((float)rand() / RAND_MAX * 50);
    }

    selectsort<float>(data, N);

    for (int i = 0; i < N; i++) {
        cout << i << " " << data[i] << endl;
    }
    return 0;
}
