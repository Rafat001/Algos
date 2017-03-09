#include<bits/stdc++.h>
using namespace std;
vector<int>v[10];
int n;
map<int,int>mp;
int ndigit(int d,int temp)
{
    int p;
    while(d)
    {
        p=temp%10;
        temp/=10;
        d--;
    }
    return p;
}
int radix(int arr[],int p)
{
    int i,j,cnt=0,temp,dig,k,qw,l,mn,loc;
    for(i=1; i<=p; i++)
    {
        qw=0;
        loc=0;
        for(j=0; j<n; j++)
        {
            dig=ndigit(i,arr[j]);
            v[dig].push_back(arr[j]);
        }
        for(j=0; j<=9; j++)
        {
            l=v[j].size();
            mn=0;
            //cout<<l<<" ";
            for(k=loc; k<n; k++)
            {
                if(l)
                {
                    arr[k]=v[j][mn++];
                    l--;
                    loc++;
                }
            }
        }
        for(j=0;j<10;j++)
            v[j].clear();
    }
}
int main()
{
    int arr[100],maxx,p=0;
    cin>>n;
    cin>>arr[0];
    maxx=arr[0];
    for(int i=1; i<n; i++)
    {
        cin>>arr[i];
        maxx=max(maxx,arr[i]);
    }
    while(maxx>0)
    {
        maxx/=10;
        p++;
    }
    radix(arr,p);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
