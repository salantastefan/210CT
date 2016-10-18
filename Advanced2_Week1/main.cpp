#include <iostream>
//Sparse matrix
//Find a better way to store a spare matrix
//Functions for Adding, Substracting and Multiplying these matrixes that are stored in this type of storage.
using namespace std;


class spareMatrix{
    /*
    This class uses 3 vectors to keep the values of a spare matrix
    1 for the row values, 1 for the column values and 1 for the values within those indexes
    You can add substract or multiply 2 spare matrixes stored using this class
    */
    private:
    //nrnz=number of non-zero elements in the matrix
    //nrR,nrC number of rows and columns for a matrix
        int r[10],c[10],v[10],nrNZ,nrR,nrC;                     //(1)

    public:
        spareMatrix()
        {
            int i;                                              //(1)
            //getting the inputs from the user
            cout<<"Non0ElemOfMatrix=";                          //(1)
            cin>>nrNZ;                                          //(1)

            cout<<"nrRowsOfMatrix=";                            //(1)
            cin>>nrR;                                           //(1)

            cout<<"nrColumnsOfMatrix=";                         //(1)
            cin>>nrC;                                           //(1)
            cout<<"Enter non-0 elements:"<<endl;                //(1)

            for(i=0;i<nrNZ;i++)                                 //(n)
            {

                cout<<"row position=";                          //(n)
                cin>>r[i];                                      //(n)
                cout<<"column position=";                       //(n)
                cin>>c[i];                                      //(n)
                cout<<"value=";                                 //(n)
                cin>>v[i];                                      //(n)
            }
        }
        //RunTime spareMatrix: O(7n+8)=O(n)
        void getMatrix()
        {
            //this function outputs to the user the matrix.
            int i,j,x=0;                                        //(1)
            //it goes from 0 to the number of rows
            //and columns that the user mentioned
            //if there is a non-zero elements it outputs that otherwise it outputs 0
            for (i=0;i<nrR;i++)                                 //(n)
            {
                for (j=0;j<nrC;j++)                             //(n*n)
                    if((r[x]==i)&&(c[x]==j))                    //(n*n)
                    {
                        cout<<v[x]<<" ";                        //(n*n)
                        x++;                                    //(n*n)
                    }
                    else
                    {
                        cout<<0<<" ";                           //(n*n)
                    }
                cout<<endl;                                     //(n)

            }
                cout<<endl;                                     //(1)
        }
        //RunTime getMatrix: O(4n^2+2n+2)=O(n^2)
        void addMatrixes(spareMatrix m1,spareMatrix m2)
        {
            //this function adds 2 matrixes
            cout<<"Add Matrixes"<<endl;                         //(1)
            int i,j,x=0,y=0,k,p;                                //(1)
            //checks if the nr of rows and columuns of the matrixes are equal
            if((m1.nrR==m2.nrR)&&(m1.nrC==m2.nrC))              //(1)
            {   //it checks which matrixes has more non-0 elements
                //so it know how far to go within the vectors.
                if(m1.nrNZ>m2.nrNZ)                             //(1)
                    {
                        k=m1.nrR;                               //(1)
                        p=m1.nrC;                               //(1)
                    }
                else
                    {
                        k=m2.nrR;                               //(1)
                        p=m2.nrC;                               //(1)
                    }

                    for (i=0;i<k;i++)                           //(n)
                    {
                        for (j=0;j<p;j++)                       //(n*n)
                            //if both matrixes have non-0 values on that position
                            //the output will be the addition of those values
                            if(((m1.r[x]==i)&&(m1.c[x]==j))&&((m2.r[y]==i)&&(m2.c[y]==j)))//(n*n)
                            {
                                cout<<m1.v[x]+m2.v[y]<<" ";     //(n*n)
                                x++;                            //(n*n)
                                y++;                            //(n*n)
                            }
                            //if only the first matrix has a non-0 element it outputs that
                            else if (((m1.r[x]==i)&&(m1.c[x]==j))&&((m2.r[y]!=i)||(m2.c[y]!=j)))//(n*n)
                            {
                                cout<<m1.v[x]<<" ";             //(n*n)
                                x++;                            //(n*n)

                            }
                            //if only the second matrix has a non-0 element it outputs that
                            else if (((m1.r[x]!=i)||(m1.c[x]!=j))&&((m2.r[y]==i)&&(m2.c[y]==j)))//(n*n)
                            {
                                cout<<m2.v[y]<<" ";             //(n*n)
                                y++;                            //(n*n)
                            }
                            //if none of them have a non-0 element on that position it outputs 0
                            else
                            {
                                cout<<0<<" ";                   //(n*n)
                            }
                    cout<<endl;                                 //(n)
                    }
            }
            else
                cout<<"Cannot add these matrixes"<<endl;        //(1)

        }
        //RunTime addMatrixes and subMatrixes: O(12n^2+2n+9)=O(n^2)
        void subMatrixes(spareMatrix m1,spareMatrix m2)
        {   //the same thing as in the add function with a single difference
            //see below
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
                            //if only the second matrix has a non-0 value it is output
                            //with the signed changed because it is considered as 0-(the value)
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
            cout<<"Multiply Matrixes"<<endl;                    //(1)
            //the result of the multiplication will be stored as well in 3 vectors
            int i,j,x=0,r[10],c[10],v[10];                      //(1)
            for(i=0;i<10;i++)                                   //(n)
                v[i]=0;                                         //(n)
            // check if the number of columns of the first matrix
            // is equal to the number of rows of the second matrix
            if(m1.nrC==m2.nrR)                                  //(1)
            {
                //takes every element of the first matrix
                //and checks if the position on the row
                // in the first matrix = with the position
                // on the column in the second matrix for
                // a value.
                for(i=0;i<m1.nrNZ;i++)                          //(n)
                {
                    for(j=0;j<m2.nrNZ;j++)                      //(n*n)
                        {
                            if(m1.c[i]==m2.r[j])                //(n*n)
                                {

                                    if(v[x]!=0)                 //(n*n)
                                        //if the position in the values vector is not 0
                                        //then you add the result of the multiplication
                                        //with the values that are already there
                                        if((r[x]==m1.r[i])&&(c[x]==m2.c[j]))//(n*n)
                                            v[x]=v[x]+(m1.v[i]*m2.v[j]);//(n*n)
                                        else
                                            {
                                                //if the values in the rows and columns vectors
                                                //are not the same with the values in the current position
                                                //you add another element to the values vector.
                                                //Also you store the position in the matrix
                                                x++;//(n*n)
                                                r[x]=m1.r[i];   //(n*n)
                                                c[x]=m2.c[j];   //(n*n)
                                                v[x]=(m1.v[i]*m2.v[j]);//(n*n)
                                            }
                                    else
                                        {
                                            //if the vector value is 0 in that position
                                            // you just put there the value of the multiplication
                                            r[x]=m1.r[i];       //(n*n)
                                            c[x]=m2.c[j];       //(n*n)
                                            v[x]=(m1.v[i]*m2.v[j]);//(n*n)
                                        }

                                }
                        }

                }
            }
            else
                cout<<"Cannot multiply the Matrixes";           //(1)
        x=0;                                                    //(1)
        //Outputs the multiplied matrixes
        for (i=0;i<m1.nrR;i++)                                  //(n)
            {
            for (j=0;j<m2.nrC;j++)                              //(n*n)
                if((r[x]==i)&&(c[x]==j))                        //(n*n)
                    {
                        cout<<v[x]<<" ";                        //(n*n)
                        x++;                                    //(n*n)
                    }
                else
                    {
                        cout<<0<<" ";                           //(n*n)
                    }
            cout<<endl;                                         //(n)

            }
        }
} ;
//RunTime inmultMatrixes: O(16n^2+5n+5)=O(n^2)
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
    //RunTime: O(4n^2+n)=O(n^2)
}
