// LightOJ 1188

#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef pair <ll, ll> pll;
 
const int Max = 1e6 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;
 
int mp[Max];
set<int>st;
int BLOCK_SIZE;
int ans[Max];
int ar[Max];
 
struct Node // template's Part
{
    ll l, r, id;
 
    Node() {};
 
    Node(int l_, int r_, int id_)
    {
        l = l_;
        r = r_;
        id = id_;
    }
 
    bool operator<(const Node &b) const
    {
        if(l / BLOCK_SIZE < b.l / BLOCK_SIZE)
        {
            return 1;
        }
        if(l / BLOCK_SIZE > b.l / BLOCK_SIZE)
        {
            return 0;
        }
        return ((l / BLOCK_SIZE) & 1) ? r < b.r : r > b.r;
    }
} qr[Max];
 
int cnt;
void add(int x) // change according to statement
{
    mp[x]++;
    if(mp[x]==1)
        cnt++;
}
 
void del(int x) // change according to statement
{
    mp[x]--;
    if(mp[x]==0)
        cnt--;
}
 
int main()
{
 
    int n, q, l, r, t;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        //st.clear();
        cnt=0;
        memset(mp,0,sizeof(mp));
        memset(ans,0,sizeof(ans));
        memset(ar,0,sizeof(ar));
        memset(qr,0,sizeof(qr));
 
        scanf("%d %d", &n, &q);
        BLOCK_SIZE = 1000;
 
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &ar[i]);
        }
 
        for(int i = 1; i <= q; i++)
        {
            scanf("%d %d", &l, &r);
            qr[i] = Node(l, r, i);
        }
 
        sort(qr + 1, qr + q + 1);
 
        ll L = 1, R = 0;
 
        for(int i = 1; i <= q; i++) // template's part
        {
            ll l = qr[i].l;
            ll r = qr[i].r;
 
            while(R < r)
            {
                R++;
                add(ar[R]);
            }
 
            while(R > r)
            {
                del(ar[R]);
                R--;
            }
 
            while(L < l)
            {
                del(ar[L]);
                L++;
            }
 
            while(L > l)
            {
                L--;
                add(ar[L]);
            }
 
            ans[ qr[i].id ] = cnt;
        }
        printf("Case %d:\n",cs);
        for(int i = 1; i <= q; i++)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
