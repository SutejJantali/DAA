#include<iostream>
using namespace std;

class topological
{
    int n,i,k,j,adj[10][10],count=0,flag[10],indeg[10];
    public:
            void read();
            void topo();

};

void topological::read()
{
    cout<<"enter the number of nodes: ";
    cin>>n;
    cout<<"enter the adjacency matrix"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
    }

}

void topological::topo()
{
    for(i=0;i<n;i++)
    {
        flag[i]=0;
        indeg[i]=0;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            indeg[i]+=adj[j][i];
        }
    }

    cout<<"topological ordering is :"<<endl;

    while(count<n)
    {
        for(k=0;k<n;k++)
        {
                if((indeg[k]==0) && (flag[k]==0))
                    {
                        cout<<k<<"\t";
                        flag[k]=1;
                    }
                for(i=0;i<n;i++)
                {
                    if(adj[i][k]==1)
                    {
                        adj[i][k]=0;
                        indeg[k]--;
                    }
                }
        }
        count++;

    }

}


int main()
{
topological t;
t.read();
t.topo();

return 0;
}
