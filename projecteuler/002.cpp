//Solution: 4613732

#include <iostream>

using namespace std;

int main()
{
   int ossz = 2;
   int pre = 1;
   int pre2 = 2;
   for (int i = 3; i <= 4000000; i = pre + pre2)
   {
      pre = pre2;
      pre2 = i;
      if (i % 2 == 0)
         ossz += i;
   }
   cout << ossz;
   return 0;
}
