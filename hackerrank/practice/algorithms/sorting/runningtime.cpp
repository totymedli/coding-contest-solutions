#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void insertionSort(vector <int> ar) {
    int shift = 0;
    for (int i=1;i<ar.size(); ++i)
    {
        int temp = ar[i];//---
        for(int x=i;ar[x-1]>temp&&x>0;--x)//-
        {
            int swap = ar[x];
            ar[x]=ar[x-1];
            ar[x-1]=swap;
            shift++;
        }
    }
    cout << shift;
}

int main() {
    
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}
insertionSort(_ar);
    return 0;
}
