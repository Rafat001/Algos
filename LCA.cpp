// Tested on HDU 2874
// Author: Rafat001

#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair <ll, ll> pll;
const int Max = 10005;
int L[Max];
int P[Max][22];
int T[Max];
int dist[Max][22];
int inf=2147483647,ans;
vector<pair<int,int> >vec[Max];
bool vist[Max];
void chk(int src){
      vist[src]=true;
      for(int i=0;i<vec[src].size();i++)
          {
                int v=vec[src][i].second;
                if(vist[v]==0) chk(v);
          }
}
void dfs(int u, int par, int dep)
{
    T[u] = par;
    L[u] = dep;
 
    for(int i=0;i<vec[u].size();i++)
    {
        int v=vec[u][i].second;
        if(v == par) continue;
        dist[v][0]=vec[u][i].first;
        dfs(v, u, dep + 1);
    }
}
int lca_query(int p, int q)
{
    if(L[p] < L[q]) swap(p, q);
    int lg = 1;
    while(1)
    {
        int nxt = lg + 1;
        if((1 << nxt) > L[p])
        {
            break;
        }
        lg++;
    }
    ans=0; // to hold the distance between P and Q
    for(int i = lg; i >= 0; i--)
    {
        if(L[p] - (1 << i) >= L[q])
        {
            ans+=dist[p][i];
            p = P[p][i];
        }
    }
    if(p == q)
    {
        return p;
    }
    for(int i = lg; i >= 0; i--)
    {
        if(P[p][i] != -1 && P[p][i] != P[q][i])
        {
            ans+=dist[p][i]+dist[q][i];
            p = P[p][i], q = P[q][i];
        }
    }
    ans+=dist[p][0]+dist[q][0];
    return T[p];
}
 
void lca_init(int n)
{
    memset(P, -1, sizeof(P));
    for(int i = 0; i < n; i++)
    {
        P[i][0] = T[i];
    }
    for(int j = 1; 1 << j < n; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(P[i][j - 1] != -1)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];
                dist[i][j]=dist[P[i][j-1]][j-1];
                dist[i][j]+=dist[i][j-1];
            }
        }
    }
}
void init()
{
    memset(L,0,sizeof(L));
    memset(P,0,sizeof(P));
    memset(T,0,sizeof(T));
    memset(dist,0,sizeof(dist));
    memset(vist,0,sizeof(vist));
    for(int i=0; i<Max; i++)
        vec[i].clear();
}
int main()
{
    int n, u, v, q, c, t, m;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        init();
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &u, &v,&c);
            dist[v][0]++;
            vec[u].emplace_back(c,v);
            vec[v].emplace_back(c,u);
        }
        for(int i=1; i<=n; i++)
        {
            if(vist[i]==0)
            {
                chk(i);
                u=0;
                v=i;
                c=0;
                vec[u].emplace_back(c,v);
                vec[v].emplace_back(c,u);
            }
        }
        n++;
        memset(dist,0,sizeof(dist));
        dfs(0, 0, 0);
        lca_init(n);
 
        while(q--)
        {
            scanf("%d%d", &u, &v);
            int common=lca_query(u,v);
            //int ans=dist[u]+dist[v]-2LL*dist[common];
            if(common==0)
                printf("Not connected\n");
            else
                printf("%d\n",ans);
        }
    }
    return 0;
}
