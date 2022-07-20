#include<iostream>
using namespace std;

class subset
{
    int include[50],weights[50],sum;
    public:
            void get();
            int promising(int,int,int);
            void sumset(int,int,int);
};


int subset::promising(int i,int wt,int total)
{
    return ((wt+total)>=sum && ((wt==sum)||(wt+weights[i+1]<=sum)));
}

void subset::sumset(int i,int wt,int total)
{
    int j;
    if(promising(i,wt,total)!=NULL)
    {
        if(wt==sum)
            {
                cout<<"\n{";
                for(j=0;j<=i;j++)
                {
                    if(include[j]!=NULL)
                    {
                        cout<<weights[j]<<" ";
                    }
                }
                cout<<"}\n";
            }
        else
            {
            include[i+1]=1;
            sumset(i+1,wt+weights[i+1],total-weights[i+1]);
            include[i+1]=0;
            sumset(i+1,wt,total-weights[i+1]);
            }
    }
}

void subset::get()
{
    int i,j,n,temp,total=0;
    cout<<"enter the number of objects: ";
    cin>>n;
    cout<<"enter the object's weights"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>weights[i];
        total+=weights[i];
    }

    cout<<"\n input subset sum: ";
    cin>>sum;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(weights[j]>weights[j+1])
            {
                temp=weights[j];
                weights[j]=weights[j+1];
                weights[j+1]=temp;
            }
        }
    }

    if((total<sum)!=NULL)
    {
        cout<<"subset construction not possible"<<endl;
    }
    else
    {
        for(i=0;i<n;i++)
        include[i]=0;

        cout<<"solution using backtracking is: "<<endl;
        sumset(-1,0,total);
    }
}

int main()
{
    subset s;
    s.get();

    return 0;
}
