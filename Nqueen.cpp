#include<iostream>
using namespace std;
int x[10],count=0;

int place(int k,int i)
{
     for(int j=1;j<k;j++)
     {
        if(x[j]==i || (abs(x[j]-i)==abs(j-k)))
        return 0;
     }
     return 1;
}

void print(int n)
{
int i,j;
    cout<<"\n\nSolution "<<++count<<endl<<endl;

   for(i=1;i<=n;i++)
    {
        cout<<"\t"<<i;
   }
    for(i=1;i<=n;i++)
    {
        cout<<"\n\n"<<i;
        for(j=1;j<=n;j++)
        {
            if(x[i]==j)
            {
            cout<<"\tQ";
            }
        else
        cout<<"\t-";
        }
    }


}
int nqueens(int k,int n)
{
 for(int i=1;i<=n;i++)
 {
    if(place(k,i))
    {
        x[k]=i;
        if(k==n)
        {
            print(n);
        }
        else
        nqueens(k+1,n);
    }
 }

}

int main()
{
    int i,n;
    cout<<"Enter the number of Queens"<<endl;
    scanf("%d",&n);
    nqueens(1,n);
    cout<<"\n\nTotal solutions= "<<count<<endl;

    return 0;
}
