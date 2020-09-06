#include <iostream>
#include <math.h>
using namespace std;

template <class array_type>
array_type max(array_type *a, const int N)
{
    array_type m = a[0];
    for (int i = 1; i < N; i++)
        if (a[i] > m)
        {
            m = a[i];
        }
    return m;
}

int main(int argc, char *argv[])
{
    double a[] = {2.5, 8.3, 6};
    int b[] = {3, 5, -1, 2};
    char c[] = {'A', 'b', 'Z', 'r'};
    cout << max(a, sizeof(a) / sizeof(a[0])) << endl;
    cout << max(b, sizeof(b) / sizeof(b[0])) << endl;
    cout << max(c, sizeof(c) / sizeof(c[0])) << endl;

    return 0;
}