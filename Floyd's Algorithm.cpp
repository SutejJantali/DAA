#include<iostream>
using namespace std;

class Floyd
{
    int n,c[10][10];
    public:
            void read();
            void floyd();
            void print();

};
int min(int a,int b)
{
    return (a<b)?a:b;
}
void Floyd::read()
{
    cout<<"enter the number of vertices:";
    cin>>n;
    cout<<"enter the cost matrix:\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>c[i][j];
        }
    }

}


void Floyd::floyd()
{
int k,i,j;
for(k=1;k<=n;k++)
{
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
        c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
        }
    }

}

}


void Floyd::print()
{
    cout<<"cost matrix is:"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cout<<c[i][j]<<"\t";

        cout<<endl;
    }

}


int main()
{
    Floyd f;
    f.read();
    f.floyd();
    f.print();

    return 0;

}
