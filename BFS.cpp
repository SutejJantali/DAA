#include <iostream>
using namespace std;
class BFS
{
  int n,adj[10][10],s[10];
  public:
    void read();
    void bfs();
    void print();
};

void BFS::read()
{
    int i,j;
    cout<<"enter the number of nodes: ";
    cin>>n;
    cout<<"enter the matrix:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
    }
    
}
    
void BFS::bfs()
{
    int q[n],j,i,source,f,r;
    f=r=0;
    cout<<"enter the source: ";
    cin>>source;
    for(i=0;i<n;i++)
    s[i]=0;
    
    s[source]=1;
    q[r]=source;
    
    cout<<"traversal is:"<<endl;
    while(f<=r)
    {
         i=q[f++];
        cout<<"\t"<<i<<"\t";   
        for(j=1;j<=n;j++)
        {
            if(s[j]==0 && adj[i][j]==1)
            {
                s[j]=1;
                q[++r]=j;
            }
        }
    }
    
}

void BFS::print()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(s[i]==0)
        cout<<endl<<"node "<<i<<" not reachable"<<endl;
        
        else
         cout<<"node "<<i<<" reachable"<<endl;
    }
    
}


int main()
{
   BFS b;
   b.read();
   b.bfs();
   b.print();
   
   return 0;
}
