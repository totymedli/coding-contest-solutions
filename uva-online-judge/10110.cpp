/*PROBLEM SEMI-SOLVED - Forever loop at big numbers*/
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    bool out = false;
    unsigned long long a = 0;
    cin >> a;
    while (a)
    {
        out = false;
        unsigned long b = (unsigned long)sqrt(a);
        for (unsigned int i=1; i<=b; i++)
        {
            if (a%i==0)
                out = !out;
        }
        out = !out;
        if (out)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        cin >> a;
    }
    return 0;
}
