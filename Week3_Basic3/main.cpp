#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

string no_vowels(string inputString, unsigned int n)
{
    //this function takes 1 string1 and 1 integer as input
    //the string is the input by the user and the N is the index
    //N=1 at the beginning
    // the result is the same as the input one but without the vowels.

    if(n<inputString.length())
        //the base case is when we reach the last char of the input string
        {
        if((inputString[n]=='a')||(inputString[n]=='e')||(inputString[n]=='i')
           ||(inputString[n]=='o')||(inputString[n]=='u')||(inputString[n]=='A')
           ||(inputString[n]=='E')||(inputString[n]=='I')||(inputString[n]=='O')||(inputString[n]=='U'))
            {
            //if the current char is a vowel we skip it
            return no_vowels(inputString,n+1);
            }
        else
            {
            //if is not we concatenate it to the result
            return inputString[n]+no_vowels(inputString,n+1);
            }
        }
    else
        {
            //when we reach the base case we return
            //an empty character to finish the resulting string.
            return "";
        }
}
int main()
{
    string inputString,finalString;

    getline(cin,inputString);

    finalString=no_vowels(inputString,0);
    cout<<finalString;

    return 0;
}
