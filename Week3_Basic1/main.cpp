#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
using namespace std;


void reverse_sentence(string s)
{
    //this funtion takes a strring as a parameter and it
    //outputs the strings reversing the words in it
    int x,startingW,endingW,i,j;
    endingW=s.length()-1;
    x=endingW;
    //we keep the first ending because we will alter it in the for loop
    for (i=x;i>=0;i--)
    {
        //we go throw the string from the end to the start
        if((s[i]==' ')||(i==0))
        {
            //if we encounter a space or the string has ended
            //we get the position from where to display the word
            startingW=i+1;
            //the position is the first character after the space
            if(i==0)
                startingW=0;
            //if we are at the start we get that exact position
            //because a sentence does not start/end with a space
            for(j=startingW;j<=endingW;j++)
                {
                    //outputs char by char from the start to the end of the word
                    cout<<s[j];
                }
            //outputs a space after the word and
            //the next ending position will be the
            //first char in front of the space
            if(i!=0)
                cout<<' ';
            endingW=i-1;
        }
    }
}
int main ()
{

  string line;
  //in build class for managing strings.
  getline(cin,line);
  reverse_sentence(line);
  return 0;
}
