#include <iostream>

using namespace std;

int main()
{
    int ok,v[100],i,j,maxim,s[100],ending[100],k=0,n;
    cout << "n=";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"v["<<i<<"]=";
        cin>>v[i];
    }
    cout<<endl;
    j=1;
    ok=1;
    maxim=1;
    for(i=0;i<n-1;i++)
        {
            if(v[i]<=v[i+1])
                j++;
            if((v[i]>v[i+1])||(i==n-2))
            {
                if(j>=maxim)
                {
                    cout<<"j="<<j<<endl;
                    if(j==maxim)
                        k++;
                    if (ok)
                        s[k]=0;
                    else
                    {
                        if (j==maxim)
                            s[k]=ending[k-1]+1;
                        else
                            s[k]=ending[k]+1;
                    }
                    if(i==n-2)
                        ending[k]=i+1;
                    else
                        ending[k]=i;
                    maxim=j;
                    j=1;
                    ok=0;
                }
            }
        }
    for(i=0;i<=k;i++)
    {
        for(j=s[i];j<=ending[i];j++)
            cout<<v[j]<<endl;
    }
    return 0;
}
