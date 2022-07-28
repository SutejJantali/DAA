#include<iostream>
using namespace std;

class Warshall
{
    int n,c[10][10];
    public:
            void read();
            void warshall();
            void print();
};


void Warshall::read()
{
    cout<<"enter the number of vertices:";
    cin>>n;
    cout<<"enter the matrix:\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>c[i][j];
        }
    }

}

void Warshall::warshall()
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                c[i][j]=(c[i][j]==1 || (c[i][k]==1 && c[k][j]==1));
            }
        }
    }

}
void Warshall::print()
{
cout<<"transitive closure is:"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    Warshall w;
    w.read();
    w.warshall();
    w.print();


    return 0;
}
