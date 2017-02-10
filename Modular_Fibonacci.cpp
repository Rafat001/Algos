#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll, ll> mp;
int p;
ll mod_fib(ll n)
{
    if(mp[n]!=0)
        return mp[n];
    ll k=n/2;
    if (n%2==0)
    {
        return mp[n] = (mod_fib(k)*mod_fib(k) + mod_fib(k-1)*mod_fib(k-1)) % p;
    }
    else
    {
        return mp[n] = (mod_fib(k)*mod_fib(k+1) + mod_fib(k-1)*mod_fib(k)) % p;
    }
}
int main()
{
    ll n,m;
    while (cin >> n >>m)
    {
        mp[0]=mp[1]=1;
        p=pow(2,m);
        if(n==0)
            cout<<0<<endl;
        else
            cout<<mod_fib(n-1)<<endl;
        mp.clear();
    }
}
