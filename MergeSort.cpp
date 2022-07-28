#include<iostream>
#include<time.h>
using namespace std;

class Rmerge
{
    public:
            void Rmergesort(int[],int,int);
            void merge(int [],int,int,int);
};


void Rmerge::Rmergesort(int a[],int l,int h)
{
    if(l<h)
    {
       int mid=(l+h)/2;
        Rmergesort(a,l,mid);
        Rmergesort(a,mid+1,h);

        merge(a,l,mid,h);
    }

}

void Rmerge::merge(int a[],int l,int mid,int h)
{
    int i=l;
    int j=mid+1;
    int k=l;
    int b[h+1];
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
        b[k++]=a[i++];


        else
        b[k++]=a[j++];
    }
    for(;i<=mid;i++)
    b[k++]=a[i];
    for(;j<=h;j++)
    b[k++]=a[j];

    for(i=l;i<=h;i++)
    a[i]=b[i];
}

int main()
{
clock_t start,stop;
    Rmerge r;
    int n,*a;
    cout<<"enter the number of elements: ";
    cin>>n;
    a=new int[n];
    cout<<"enter the elements:"<<endl;
    for(int i=0;i<n;i++)
    {
     a[i]=rand()%1000;
     //cin>>a[i];
    }
    cout<<"elements before sorting:"<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<"\t";

        cout<<endl;
    start=clock();

    cout<<"elements after sorting:"<<endl;
    r.Rmergesort(a,0,n-1);
    stop=clock();


    for(int i=0;i<n;i++)
    cout<<a[i]<<"\t";


    cout<<"\ntime taken= "<<(stop-start)/CLOCKS_PER_SEC<<endl;

    cout<<"space consumed: "<<sizeof(a);
    return 0;
}
