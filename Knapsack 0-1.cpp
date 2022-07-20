#include<iostream>
using namespace std;

int max(int a,int b)
{
    return (a>b)?a:b;
}
int main()
{
    int n,m;
    cout<<"enter the number of objects: ";
    cin>>n;
    cout<<"\nenter the capacity of knapsack: "<<endl;
    cin>>m;

    int p[n+1],wt[n+1];
    cout<<"enter the 1.profit and 2.weight of objects\n"<<endl;
    p[0]=wt[0]=0;

    for(int i=1;i<=n;i++)
    cin>>p[i]>>wt[i];

   // int p[5]={0,1,2,5,6};
    //int wt[5]={0,2,3,4,5};
    //int m=8,n=4;
    int k[n+1][m+1];
    int i,j,w;
    for(i=0;i<=n;i++)
    {
        for(w=0;w<=m;w++)
        {
            if(i==0 || w==0)
            k[i][w]=0;

            else if(wt[i]<=w)
            k[i][w]=max(p[i]+k[i-1][w-wt[i]],k[i-1][w]);

            else
            k[i][w]=k[i-1][w];
        }
    }
    cout<<"optimal profit: "<<k[n][m]<<endl;

    i=n;
    j=m;
    while(i>0 && j>=0)
    {
        if(k[i][j]==k[i-1][j])
        {
            cout<<"object "<<i<<"=0,i.e: not included"<<endl;
            i--;
        }
        else{
            cout<<"object "<<i<<"=1,i.e: included"<<endl;

            j=j-wt[i];
                 i--;
        }
    }
}
