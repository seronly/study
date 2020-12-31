#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 10;
    try
    {
        cout << b / a << endl;
    }
    catch (...)
    {
        cout << "error";
    }
    cin.get();
    return 0;
}