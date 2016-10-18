#include <iostream>

using namespace std;
//Alien invasion
//An alien lays X eggs each day (no genders) and the eggs hatch after Y days
//If X=3 and Y=5 how many aliens will there be 30 days after 1 alien invades.

int main()
{
    //we have 2 arrays, one for each alien there is in each day and one for how many eggs are laid every day
    int i,eggs=3,hatchDays=5,alien[30],eggsLaid[30];        //(1)
    //setting the aliens and eggs laid in the first day
    alien[0]=1;                                             //(1)
    eggsLaid[0]=3;                                          //(1)


    for(i=1;i<30;i++)                                       //(n)
    {
        // if the eggs are starting to hatch we calculate
        //the eggs laid and aliens,from that day on, differently.
        if(i>(hatchDays-1))                                 //(n)
        {
            alien[i]=alien[i-1]+eggsLaid[i-hatchDays];      //(n)
            eggsLaid[i]=(alien[i]*eggs);                    //(n)
        }
        //if the first set of eggs did not hatch we continue by having the same
        //amount of aliens as in the start of the invasion
        //and the same amount of eggs laid every day.
        else
        {
            eggsLaid[i]=(eggsLaid[i-1]);                    //(n)
            alien[i]=alien[i-1];                            //(n)
        }
    }
    /*
    //print how many aliens and eggs are there every day
    for(i=0;i<30;i++)
        cout << "Aliens in the "<<i+1<<" day= " <<alien[i]<< endl;
    for(i=0;i<30;i++)
        cout << "Eggs Laid in the "<<i+1<<" day= " <<eggsLaid[i]<< endl;
    */

    cout<<"Aliens 30 days after the invasion= "<<alien[29]; //(1)
    return 0;                                               //(1)
}
//The run time: O(6n+5)=O(n)
