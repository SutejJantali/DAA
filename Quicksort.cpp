#include<iostream>
#include<time.h>
using namespace std;

class quick
{
    int n;
    public:
        void get();
        int partition(int [],int,int);
        void sort(int[],int,int);
};
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void quick::get()
{
    clock_t start,stop;

    cout<<"enter the number of elements: ";
    cin>>n;
    int *a=new int[n];
    cout<<"enter the elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%1000;
        // cin>>a[i];
    }
     cout<<"elements before sorting: "<<endl;
     for(int i=0;i<n;i++)
    cout<<a[i]<<endl;

    start=clock();
    cout<<"elements after sorting: "<<endl;
    sort(a,0,n);
    stop=clock();

    for(int i=0;i<n;i++)
    cout<<a[i]<<endl;

    cout<<"\ntime taken= "<<(stop-start)/CLOCKS_PER_SEC<<endl;

    cout<<"space consumed: "<<sizeof(a);

}

void quick::sort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(a,l,h);
        sort(a,l,j);
        sort(a,j+1,h);
    }
}

int quick::partition(int a[],int l,int h)
{
    int pivot=a[l];
    int i=l,j=h;
    do
    {
        do{i++;}while(a[i]<pivot);
        do{j--;}while(a[j]>pivot);

        if(i<j)
        swap(&a[i],&a[j]);
    }
    while(i<j);
    swap(&a[l],&a[j]);

    return j;

}



int main()
{
    quick q;
    q.get();

    return 0;
}
