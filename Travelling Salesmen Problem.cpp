#include<iostream>
using namespace std;

int n,a[10][10],completed[10],cost=0;


void get()
{
    int i,j;
    cout<<"enter the number of cities: "<<endl;
    cin>>n;
    cout<<"enter the cost matrix:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
        completed[i]=0;
    }

}

int least(int c)
{
    int i,min=9999,nc=9999,kmin;

    for(int i=0;i<n;i++)
    {
        if(a[c][i]!=0 && (completed[i]==0))
        {
            if(a[c][i]+a[i][c]<min)
            {
            min=a[i][0]+a[c][i];
            kmin=a[c][i];
            nc=i;
            }
        }
    }

    if(min!=9999)
        cost+=kmin;

    return nc;
}


void mincost(int city)
{
    int i,ncity;

    completed[city]=1;

    cout<<city+1<<"-->";

    ncity=least(city);

    if(ncity==9999)
    {
        ncity=0;
        cout<<ncity+1;
        cost+=a[city][ncity];

        return;
    }

    mincost(ncity);
}


int main()
{
    get();

    mincost(0);

    cout<<"\nminimum cost is: "<<cost<<endl;

    return 0;

}
