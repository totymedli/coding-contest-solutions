// Soultion: 25164150

#include <iostream>

using namespace std;

int main()
{
    int sumOfSquares = 0, squareOfSums = 0;
    for (int i = 1; i <= 100; ++i)
    {
        sumOfSquares += i * i;
        squareOfSums += i;
    }

   cout << squareOfSums * squareOfSums - sumOfSquares << endl; 
   
   return 0;
}
