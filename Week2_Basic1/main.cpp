#include <iostream>
#include <math.h>
using namespace std;
int closestPerfectSquare(int n)
{
    float x;
    //take the square root of the number
    x=pow(n,0.5);
    //if the square root is an integer it means that the number is a perfect square
    if(x==(int(x)))
        return n;
    //otherwise round it down and find out the closest square root by multiplying //the rounded value with itself.
    else
        {
        x=floor(x);
        return x*x;
        }
}
int main()
{
    int n;
    cout << "n=";
    cin>>n;
    cout<<"Closest Perfect Square Less or Equal than "<<n<<"="<<closestPerfectSquare(n);
    return 0;
}
