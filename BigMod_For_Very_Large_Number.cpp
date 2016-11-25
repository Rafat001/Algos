#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod_multi(ll a, ll b, ll c)
{
    if(a==0 || b==0)
        return 0;
    if(a==1)
        return b;
    if(b==1)
        return a;
    ll n=mod_multi(a,b/2,c);
    if((b&1)==0)
        return(n+n)%c;
    else
        return((a%c)+(n+n))%c;
}
ll mod(ll a, ll b, ll c)
{
    ll part1,part2,half;
    if(b==0)
        return 1;
    if(b%2==1)
    {
        part1=a%c;
        part2=mod(a,b-1,c);
        return mod_multi(part1,part2,c);
    }
    else
    {
        half=mod(a,b/2,c);
        return mod_multi(half,half,c);
    }
}
int main()
{
    //freopen("output.txt","w",stdout);
    ll a,b,c,t,i;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>a>>b>>c;
        cout<<"Case "<<i<<": ";
        cout<<mod(a,b,c)<<endl;
    }
    return 0;
}
