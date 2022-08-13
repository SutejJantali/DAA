#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define no_char 256

void badcharheuristic(string str,int size,int badchar[no_char])
{
    int i=0;

    for(int i=0;i<no_char;i++)
    badchar[i]=-1;

    for(int i=0;i<size;i++)
    {
        badchar[(int) str[i]]=i;
    }
}

void search(string txt,string pat)
{
int n=txt.length();
int m=pat.length();

int badchar[no_char];

badcharheuristic(pat,m,badchar);

int s=0;

    while(s<=(n-m))
    {
        int j=m-1;

        while(j>=0 && pat[j]==txt[s+j])
            j--;

        if(j<0)
        {
        cout<<"pattern occurs at position: "<<s<<endl;

        s+=(s+m<n)? m-badchar[txt[s+m]]:1;
        }
        else
        s+=max(1,j-badchar[txt[s+j]]);
    }
}


int main()
{
    string txt= "HAPPYBIRTHDAYHHA";
string pat = "BIRTH";
cout<<"Text= "<<txt<<endl;
cout<<"Pattern= "<<pat<<endl;
search(txt, pat);
return 0;
}
