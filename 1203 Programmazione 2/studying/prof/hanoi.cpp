/*
 * hanoi.cpp
 */

#include <iostream>

using namespace std;

void hanoi(int n, char _from, char _to, char _aux)
{
    if (n == 0) return;
    hanoi(n - 1, _from, _aux, _to);
    cout << "Move disc from " << _from << " to " << _to << endl;
    hanoi(n - 1, _aux, _to, _from);
}

int main(int argc, char * argv[])
{

    int size;

    cout << "Enter tower size:" ;
    cin >> size ;

    hanoi(size, 'A', 'B', 'C');

    return 0;

}

