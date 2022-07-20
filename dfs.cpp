#include <iostream>
using namespace std;

class DFS
{
    int n,adj[20][20];
    public:
    void read();
    void reach();
    void dfs(int,int []);
    
    
};

void DFS::read()
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

void DFS::reach()
{
    int i,s[n],source;
    for(i=0;i<n;i++)
    s[i]=0;
    
    cout<<"enter the source node: ";
    cin>>source;
    cout<<"traversal is :"<<endl;
    dfs(source,s);
    
    for(i=0;i<n;i++)
    {
        if(s[i]==0)
        cout<<endl<<i<<" not reachable";
        else
        cout<<endl<<i<<" reachable";
    }
    
}
void DFS::dfs(int i,int s[])
{
    int j;
    s[i]=1;
    cout<<i<<"\t";
    for(j=0;j<n;j++)
    if(s[j]==0 && adj[i][j]==1)
    dfs(j,s);
}
int main() {
    // Write C++ code here
    DFS d;
    d.read();
    d.reach();

    return 0;
}
