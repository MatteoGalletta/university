/*
 * quicksort.cpp
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

template <typename T> int partition(T * data, int start, int end)
{
    int pivot_index;

    if (start == end)
        return start;

    if (data[start] > data[start + 1])
        pivot_index = start;
    else
        pivot_index = start + 1;

    T pivot = data[pivot_index];

    int left = start;
    int right = end;

    while (left <= right) {

        while ((data[left] <= pivot) && (left <= right))
            left++;

        while ((data[right] > pivot) && (left <= right))
            right--;

        if (left < right)
            _swap<T>(data[left], data[right]);
    }
    _swap<T>(data[pivot_index], data[left - 1]);

    return left - 1;
}

#define N 20


template <typename T> void quicksort(T * data, int start, int end)
{
    if (start < end) {
        int split = partition<T>(data, start, end);
        quicksort<T>(data, start, split - 1);
        quicksort<T>(data, split + 1, end);
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    float data[N];
    for (int i = 0; i < N; i++) {
        data[i] = ((float)rand() / RAND_MAX * 50);
    }

    quicksort<float>(data, 0, N - 1);

    for (int i = 0; i < N; i++) {
        cout << i << " " << data[i] << endl;
    }
    return 0;
}
