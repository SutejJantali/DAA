#include<iostream>
#include<cstdlib>
using namespace std;

int i,j,n,a,b,u,v,cost[10][10],no_vertices=1,mini,min_cost=0,parent[10];


int fin(int i)
{
    while(parent[i])
    i=parent[i];

    return i;
}

int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}


int main()
{
    cout<<"enter the number of vertices: ";
    cin>>n;

    cout<<"enter the adjacency matrix:"<<endl;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>cost[i][j];

            if(cost[i][j]==0)
            cost[i][j]=9999;
        }
    }

    while(no_vertices<n)
    {
        for(i=1,mini=9999;i<=n;i++)
        {
        	
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<mini)
                {
                    mini=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }

        }

        u=fin(u);
        v=fin(v);

        if(uni(u,v))
        {
            cout<<"cost of edge from "<<a<<" to "<<b<<" is : "<<mini<<endl;
            min_cost+=mini;
            no_vertices++;
        }

        cost[a][b]=cost[b][a]=9999;
    }

    cout<<endl<<"minimum cost is: "<<min_cost<<endl;
    return 0;
}
