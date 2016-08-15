#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */
void insertionSort(vector <int> ar) {
    if (ar.size()>1){
    int var = ar[ar.size()-1];
    int i;
    for (i=ar.size()-2; (ar[i]>var&&i>=0); i--)
    {
        ar[i+1]=ar[i];
        for (int x=0; x<ar.size(); x++)
            cout << ar[x] << " ";
        cout << endl;
    }
    ar[i+1]=var;
    for (int x=0; x<ar.size(); x++)
        cout << ar[x] << " ";
}
else
    cout << ar[0];
}
/* Tail starts here */
int main(void) {
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