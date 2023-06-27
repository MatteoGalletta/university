/*
 * bubblesort.cpp
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

template <typename T> void bubblesort(T * data, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (data[j] > data[j+1])
                _swap<T>(data[j], data[j+1]);
        }
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

    bubblesort<float>(data, N);

    for (int i = 0; i < N; i++) {
        cout << i << " " << data[i] << endl;
    }
    return 0;
}
