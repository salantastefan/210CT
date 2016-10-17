#include <iostream>
//sparse matrix
using namespace std;


class spareMatrix{
    private:
        int r[10],c[10],v[10],nrNZ,nrR,nrC;;

    public:
        spareMatrix()
        {
            int i;
            cout<<"Non0ElemOfMatrix=";
            cin>>nrNZ;

            cout<<"nrRowsOfMatrix=";
            cin>>nrR;

            cout<<"nrColumnsOfMatrix=";
            cin>>nrC;
            cout<<"Enter non-0 elements:"<<endl;
            for(i=0;i<nrNZ;i++)
            {

                cout<<"row position=";
                cin>>r[i];
                cout<<"column position=";
                cin>>c[i];
                cout<<"value=";
                cin>>v[i];
            }
        }
        void getMatrix()
        {
            int i,j,x=0;
            for (i=0;i<nrR;i++)
            {
                for (j=0;j<nrC;j++)
                    if((r[x]==i)&&(c[x]==j))
                    {
                        cout<<v[x]<<" ";
                        x++;
                    }
                    else
                    {
                        cout<<0<<" ";
                    }
                cout<<endl;

            }
            cout<<endl;
        }
        void addMatrixes(spareMatrix m1,spareMatrix m2)
        {
            cout<<"Add Matrixes"<<endl;
            int i,j,x=0,y=0,k,p;
            if((m1.nrR==m2.nrR)&&(m1.nrC==m2.nrC))
            {
                if(m1.nrNZ>m2.nrNZ)
                    {
                        k=m1.nrR;
                        p=m1.nrC;
                    }
                else
                    {
                        k=m2.nrR;
                        p=m2.nrC;
                    }

                    for (i=0;i<k;i++)
                    {
                        for (j=0;j<p;j++)
                            if(((m1.r[x]==i)&&(m1.c[x]==j))&&((m2.r[y]==i)&&(m2.c[y]==j)))
                            {
                                cout<<m1.v[x]+m2.v[y]<<" ";
                                x++;
                                y++;
                            }
                            else if (((m1.r[x]==i)&&(m1.c[x]==j))&&((m2.r[y]!=i)||(m2.c[y]!=j)))
                            {
                                cout<<m1.v[x]<<" ";
                                x++;

                            }
                            else if (((m1.r[x]!=i)||(m1.c[x]!=j))&&((m2.r[y]==i)&&(m2.c[y]==j)))
                            {
                                cout<<m2.v[y]<<" ";
                                y++;
                            }
                            else
                            {
                                cout<<0<<" ";
                            }
                    cout<<endl;
                    }
            }
            else
                cout<<"Cannot add these matrixes"<<endl;

        }
        void subMatrixes(spareMatrix m1,spareMatrix m2)
        {
            cout<<"Substract Matrixes"<<endl;
            int i,j,x=0,y=0,k,p;
            if((m1.nrR==m2.nrR)&&(m1.nrC==m2.nrC))
            {
                if(m1.nrNZ>m2.nrNZ)
                    {
                        k=m1.nrR;
                        p=m1.nrC;
                    }
                else
                    {
                        k=m2.nrR;
                        p=m2.nrC;
                    }

                    for (i=0;i<k;i++)
                    {
                        for (j=0;j<p;j++)
                            if(((m1.r[x]==i)&&(m1.c[x]==j))&&((m2.r[y]==i)&&(m2.c[y]==j)))
                            {
                                cout<<(m1.v[x]-m2.v[y])<<" ";
                                x++;
                                y++;
                            }
                            else if (((m1.r[x]==i)&&(m1.c[x]==j))&&((m2.r[y]!=i)||(m2.c[y]!=j)))
                            {
                                cout<<m1.v[x]<<" ";
                                x++;

                            }
                            else if (((m1.r[x]!=i)||(m1.c[x]!=j))&&((m2.r[y]==i)&&(m2.c[y]==j)))
                            {
                                cout<<-m2.v[y]<<" ";
                                y++;
                            }
                            else
                            {
                                cout<<0<<" ";
                            }
                    cout<<endl;
                    }
            }
            else
                cout<<"Cannot add these matrixes"<<endl;

        }
        void inmultMatrixes(spareMatrix m1, spareMatrix m2)
        {
            cout<<"Multiply Matrixes"<<endl;
            int i,j,x=0,r[10],c[10],v[10];
            for(i=0;i<10;i++)
                v[i]=0;
            if(m1.nrC==m2.nrR)
            {
                for(i=0;i<m1.nrNZ;i++)
                {
                    for(j=0;j<m2.nrNZ;j++)
                        {
                            if(m1.c[i]==m2.r[j])
                                {
                                    if(v[x]!=0)
                                        if((r[x]==m1.r[i])&&(c[x]==m2.c[j]))
                                            v[x]=v[x]+(m1.v[i]*m2.v[j]);
                                        else
                                            {
                                                x++;
                                                r[x]=m1.r[i];
                                                c[x]=m2.c[j];
                                                v[x]=(m1.v[i]*m2.v[j]);
                                            }
                                    else
                                        {
                                            r[x]=m1.r[i];
                                            c[x]=m2.c[j];
                                            v[x]=(m1.v[i]*m2.v[j]);
                                        }

                                }
                        }

                }
            }
            else
                cout<<"Cannot multiply the Matrixes";
        x=0;
        for (i=0;i<m1.nrR;i++)
            {
            for (j=0;j<m2.nrC;j++)
                if((r[x]==i)&&(c[x]==j))
                    {
                        cout<<v[x]<<" ";
                        x++;
                    }
                else
                    {
                        cout<<0<<" ";
                    }
            cout<<endl;

            }
        }
} ;
int main()
{
    //int r[4]={0,1,1,2},c[4]={0,1,3,2},v[4]={1,2,4,3};
    spareMatrix m1;
    spareMatrix m2;
    m1.getMatrix();
    m2.getMatrix();
    m1.addMatrixes(m1,m2);
    m1.subMatrixes(m1,m2);
    m1.inmultMatrixes(m1,m2);
    return 0;
}
