#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll num[50],rem[50];
ll inv(ll a, ll m) // returns inverse(a)%m
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
       return 0;

    while (a > 1)
    {
        q = a / m; // q is quotient
        t = m; // m is remainder now, process same as euclid's algo
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;  // Make x1 positive

    return x1;
}
ll ChineseRemainder(int k) // given some numbers num[] and reminders rem[] find smallest x such that x%num[i]=rem[i] for all i from 0 to k
{
    ll prod = 1;
    for (int i = 0; i < k; i++)
        prod =prod*1LL*num[i];

    ll result = 0;

    for (int i = 0; i < k; i++)
    {
        ll pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }
    return result % prod;
}
