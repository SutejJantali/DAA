#include<iostream>
using namespace std;

int main()
{
int n,v,a,b,min,mincost=0,no_vertices=1,cost[10][10],visited[10]={0};
cout<<"enter the number of vertices:\n";
cin>>n;
    cout<<"enter the cost adjacency matrix:"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>cost[i][j];

            if(cost[i][j]==0)
            cost[i][j]=9999;
        }
    }

   cout<<"enter the start vertex:";
    cin>>v;
    visited[v]=1;
   //visited[1]=1;

    while(no_vertices<n)
    {
        min=9999;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }


        if(visited[b]==0)
        {
            cout<<"cost from "<<a<<" to "<<b<<"is :"<<min<<endl;
            mincost+=min;
            no_vertices++;
        }
        visited[b]=1;

        cost[a][b]=cost[b][a]=9999;

    }
    cout<<endl<<"minimum cost is: "<<mincost<<endl;

    return 0;

}
