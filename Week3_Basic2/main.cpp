#include <iostream>

using namespace std;

bool prime_recursive(int n,int m)
{
    //this recursion function takes two numbers as input,
    //one is just a counter to count down to 1 from the first number
    //at the first call of the function m=n-1

    if (m<=1)
        //if counter reaches 1 or less(the input is 1)
        //then the number is prime
        return true;
    else if (n%m==0)
        //compare the number at every step with the counter
        //if the reminder is 0 it means is not a prime number
        return false;
    else
        //call the recursive function with the same input
        // but take 1 at every step from the counter.
        return prime_recursive(n,m-1);

}
int main()
{
    int n;
    cout << "n=" << endl;
    cin>>n;
    if(prime_recursive(n,n-1))
        cout<<n<<" is a prime number";
    else
        cout<<n<<" is NOT a prime number";
    return 0;
}
