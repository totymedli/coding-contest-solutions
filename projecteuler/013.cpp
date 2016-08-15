/*PROBLEM UNSOLVED*/

#include <iostream>
#define NUMSIZE 50

using namespace std;

int main()
{
    string text[NUMSIZE];
    for (int i = 0; i < NUMSIZE; i++)
        cin >> text[i] >> endl;

    for (int i = 1; i < NUMSIZE; i++)
    {
        for (int x = 0; x < NUMSIZE; x++)
        {
            int textsize = text[0].size() - 1;
            int a = text[0][textsize-i] - '0';
            int b = text[i][NUMSIZE-1-i] - '0';
            int sum = a + b;
            if (sum > 9)//Carry: sum is 10->18
            {
                sum -= 10;
                //Add carry to higher digit
                text[0][i-1] += 1;//Error what if another carry?
                //Also what if sum string need extra chars to beggining?
            }
            text[0][i] = '0' + sum;
        }
    }
    for (int i = 0; i < 10; i++)
        cout << text[0][i];
    return 0;
}
