#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>fib;
    int a,i,t,n;
    fib.push_back(0);
    fib.push_back(1);
    fib.push_back(1);
    for(i=3;i<=60;i++)
    {
        a=(fib[i-1]+fib[i-2])%10;
        fib.push_back(a);
    }
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        printf("Case %d: %d is the last digit.\n",i,fib[n%60]);
    }
    return 0;
}
