/*PROBLEM UNSOLVED - ALGORITHM TOO SLOW*/
//Problem Set Volumes-Volume VI-624
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int mezoosszeg_max = 0;
    cin >> n;
    vector<vector<int> > szamok(n, vector<int>(n));
    for (int i=0; i<n; i++)
    {
        for (int k=0; k<n; k++)
            cin >> szamok[i][k];
    }
    for (int i=0; i<n; i++)
    {
        for (int k=0; k<n; k++)
        {
            for (int x=i; x<n; x++)
            {
                for (int y=k; y<n; y++)
                {
                    int mezoosszeg = 0;
                    for (int p=i; p<=x; p++)
                    {
                        for (int z=k; z<=y; z++)
                            mezoosszeg += szamok[p][z];
                    }
                    if (mezoosszeg>mezoosszeg_max)
                        mezoosszeg_max = mezoosszeg;
                }
            }
        }
    }
    cout << mezoosszeg_max;
    return 0;
}
