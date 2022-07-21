#include<iostream>
using namespace std;

class heap
{
    int n,*a;
    public:
            void heapify(int [],int,int);
            void heapsort(int [],int);
            void get();
};

void heap::heapify(int a[],int n,int i)
{
    int temp,largest,l,r;
    largest=i;
    l=2*i+1;
    r=2*i+2;

    if(l<n && a[l]>a[largest])
    largest=l;

    if(r<n && a[r]>a[largest])
    largest=r;


    if(largest!=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;

        heapify(a,n,largest);
    }

}

void heap::heapsort(int a[],int n)
{
    int i,temp;
    for(i=n/2-1;i>=0;i--)
    heapify(a,n,i);

    for(i=n-1;i>=0;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}

void heap::get()
{
    cout<<"enter the number of elements: ";
    cin>>n;
    a=new int[n];
    int i;
    cout<<"enter the elements:"<<endl;
    for(i=0;i<n;i++)
    cin>>a[i];

    cout<<"elements before heap sort:"<<endl;
        for(i=0;i<n;i++)
        cout<<a[i]<<" ";

    heapsort(a,n);

    cout<<"\nelements after sort:"<<endl;
        for(i=0;i<n;i++)
        cout<<a[i]<<" ";


}
int main()
{
    heap h;
    h.get();

    return 0;
}
