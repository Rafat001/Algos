// Tested on LightOJ 1026

#include<bits/stdc++.h>
using namespace std;
#define MX 10005
vector<int>vec[MX];
bool vist[MX];
int low[MX],dist[MX],ans,par[MX],cur;
vector<pair<int,int> >str;
void ArticulationBridge(int u)
{
    low[u] = dist[u] = ++cur;
    vist[u] = 1;
    for(int i = 0; i < vec[u].size(); i++)
    {
        int v = vec[u][i];
        if(vist[v])
        {
            if(v != par[u])
            {
                low[u] = min(low[u], dist[v]);
            }
        }
        else // not visited
        {
            par[v] = u;
            ArticulationBridge(v);
            low[u] = min(low[u], low[v]);
            if(low[v] > dist[u])
            {
                ans += 1;
                str.push_back(make_pair(min(u,v),max(u,v)));
            }
        }
    }
}
void init()
{
    ans=cur=0;
    str.clear();
    for(int i=0;i<MX;i++)
    {
        vec[i].clear();
        low[i]=dist[i]=vist[i]=0;
        par[i]=i;
    }
}
int main()
{
    int t,n,x,y,v;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d (%d)",&x,&y);
            for(int j=1; j<=y; j++)
            {
                scanf("%d",&v);
                vec[x].push_back(v);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(vist[i]==0)
                ArticulationBridge(i);
        }
        printf("Case %d:\n",cs);
        if(ans==0)
            printf("0 critical links\n");
        else
        {
            sort(str.begin(),str.end());
            printf("%d critical links\n",ans);
            for(int i=0;i<ans;i++)
                printf("%d - %d\n",str[i].first,str[i].second);
        }
        init();
    }
}
