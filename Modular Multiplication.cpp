#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll modular_multiplication(ll a, ll b, ll c)
{
    if(a==0 || b==0)
        return 0;
    if(a==1)
        return b;
    if(b==1)
        return a;
    ll n=modular_multiplication(a,b/2,c);
    if(b%2==0)
        return(n+n)%c;
    else
        return((a%c)+(n+n))%c;
}
int main()
{
    ll a,b,m;
    cin>>a>>b>>m;
    cout<<modular_multiplication(a,b,m);
}
