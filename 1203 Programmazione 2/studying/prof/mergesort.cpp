/*
 * mergesort.cpp
 */

#include <iostream>

using namespace std;

template <typename T> void merge(T *arr, int size, int low, int mid, int high)
{
    int i, j, k;
    T c[size];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}

template <typename T> void merge_sort(T *arr, int size, int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid = (low + high) / 2;
        merge_sort(arr, size, low, mid);
        merge_sort(arr, size, mid+1, high);
        //merge sorted arrays
        merge(arr, size, low, mid, high);
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

    merge_sort<float>(data, N, 0, N - 1);

    for (int i = 0; i < N; i++) {
        cout << i << " " << data[i] << endl;
    }
    return 0;
}
