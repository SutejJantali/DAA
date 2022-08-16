#include<iostream>
#include<cstdlib>
using namespace std;

void dijkstra(int,int,int [][10],int []);
int main()
{
int i,j,n,s,cost[10],a[10][10];

cout<<"enter the number of vertices:"<<endl;
cin>>n;

cout<<"enter the adjacency matrix:"<<endl;
for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
        cin>>a[i][j];

        if(a[i][j]==0)
        a[i][j]=9999;
    }

}

cout<<"enter the source vertice: ";
cin>>s;

dijkstra(n,s,a,cost);


cout<<"\nDistances are: "<<endl;
for(int i=1;i<=n;i++)
{
    if(s!=i)
    {
        cout<<" "<<s<<" -> "<<i<<" is "<<cost[i]<<endl;
    }
}

return 0;
}


void dijkstra(int n,int s,int a[][10],int cost[])
{
    int count=0,v,min,visited[10];

    for(int i=1;i<=n;i++)
    {
        visited[i]=0;

        cost[i]=a[s][i];
    }

    visited[s]=1;

    cost[s]=0;


    while(count<=n)
    {
        min=9999;

        for(int i=1;i<=n;i++)
        {
            if(cost[i]<min && visited[i]==0)
            {
                min=cost[i];
                v=i;
            }

        }
        visited[v]=1;
        count++;


        for(int i=1;i<=n;i++)
        {
            if(cost[i]>cost[v]+a[v][i])
            {
                cost[i]=cost[v]+a[v][i];
            }
        }
    }



}
