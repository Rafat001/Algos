#include<bits/stdc++.h>
using namespace std;
#define Max 100000
int main()
{
    int n,limit,factors[Max],k,m=1,flag=0,i,j;
    factors[0]=1;
    cin>>n;
    limit=sqrt(n);
    for(i=1; i<=n; i++)
    {
        k=i;
        limit=sqrt(i);
        for(j=2; j<=limit; j++)
        {
            while(k%j==0)
            {
                factors[m]=j;
                m++;
                k=k/j;
            }
        }
        if(k!=1)
        {
            factors[m]=k;
            m++;
        }
    }
    sort(factors,factors+m);
    cout<<n<<"!=";
    for(i=0; i<m; i++)
    {
        cout<<factors[i];
        if(i!=m-1)
            cout<<"*";
    }
    cout<<endl;
}
