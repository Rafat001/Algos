// Problem LightOJ 1197 //

/* 
   given A and B, output the number of primes between them where A,B <2^31 and B-A<=10^6.
   The main idea is to optimize the classic sieve for space complexity. flag all numbers from A to B which
   is divisible by another prime less than sqrt(b). the marking process is choosing A as 0, A+1 as 1.... B as B-A
   so we'll need atmost 10^6 space.
*/

#include<bits/stdc++.h>
using namespace std;
#define MX 100005
#define ll long long
bool num[MX],mark[MX*10];
void sieve()
{
    num[0]=num[1]=1;
    for(int i=4; i<MX; i+=2)
        num[i]=1;
    for(int i=3; i<sqrt(MX); i+=2)
    {
        if(num[i]==0)
        {
            for(int j=i*i; j<MX; j+=i)
            {
                num[j]=1;
            }
        }
    }
}
int segSieve(ll a,ll b)
{
    ll aa=a;
    if(aa%2!=0)
        aa++;
    for(ll i=aa; i<=b; i+=2)
    {
        mark[i-a]=1;
    }
    ll sq=sqrt(b)+1;
    for(int i=3; i<=sq; i+=2)
    {
        if(num[i]==0)
        {
            ll lim=a;
            if(a%i!=0)
            {
                ll p=a%i;
                lim+=i-p;
            }
            if(lim==i)
                lim*=2;
            for(ll j=lim; j<=b; j+=i)
            {
                mark[j-a]=1;
            }
        }
    }
    ll cnt=0;
    if(a==2)
        cnt++;
    for(ll i=a; i<=b; i++)
    {
        if(mark[i-a]==0)
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    sieve();
    int t,cnt;
    ll n,m;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        memset(mark,0,sizeof(mark));
        scanf("%lld%lld",&n,&m);
        cnt=segSieve(n,m);
        if(n==1 && m==1)
            cnt=0;
        printf("Case %d: %d\n",cs,cnt);
    }
}
