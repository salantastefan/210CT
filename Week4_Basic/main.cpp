#include <iostream>

using namespace std;

bool binary_in_interval(int v[],int n,int leftInterval,int rightInterval)
{
    //this function takes a vector and its length and the margins of the interval.
    //uses the binary_search method to find if there are an values in the mentioned interval
    //in the vector. It returns true or false based on that
    int leftMargin,rightMargin,m;
    leftMargin=0;
    rightMargin=n-1;
    //set the margins where to look at the beginning and end of the vector
    while(leftMargin<=rightMargin)
        //continue until there is less than an element to check
    {
        m=(leftMargin+rightMargin)/2;
        //set the middle
        if ((v[m]>=leftInterval)&&(v[m]<=rightInterval))
            //if the mid value is in the interval, return true
            return true;
        else if (v[m]>rightInterval)
            //if the mid value is greater than the most right point of the interval
            //look in the right side of the middle point
            rightMargin=m-1;
        else if (v[m]<leftInterval)
            //if the mid value is less than the most left point of the interval
            //look in the left side of the middle point
            leftMargin=m+1;
    }
    //if there is no values from the interval in the vector, return false
    return false;
}
int main()
{
    int n,v[100],i;
    cout << "n=";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>v[i];
    cout<<binary_in_interval(v,n,15,17);
    return 0;
}
