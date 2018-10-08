#include <bits/stdc++.h>
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
long long power(long long x, unsigned long long y, long long p)
{
    long long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = mod_multi(res,x,p);

        y = y>>1;
        x = mod_multi(x,x,p);
    }
    return res;
}
bool miillerTest(long long d, long long n)
{
    long long a = 2 + rand() % (n - 4);
    long long x = power(a, d, n);

    if (x == 1  || x == n-1)
        return true;
    while (d != n-1)
    {
        x = mod_multi(x,x,n);
        d *= 2;

        if (x == 1)
            return false;
        if (x == n-1)
            return true;
    }
    return false;
}
bool isPrime(long long n, long long k)
{
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (int i = 0; i < k; i++)
        if (!miillerTest(d, n))
            return false;

    return true;
}
int main()
{
    long long k = 4;
    long long n,m;
    cout<<isPrime(17,k); // K is how many times you wanna check with a rand() value //
    return 0;
}
