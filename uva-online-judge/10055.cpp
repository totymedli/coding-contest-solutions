#include <iostream>

using namespace std;

int main()
{
    long a,b;
    while (cin >> a >> b)
    {
        b -= a;
        if (b<0)
            b *= -1;
        cout << b << endl;
    }
    return 0;
}
