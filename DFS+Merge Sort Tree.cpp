/*
        You will be given an edge weighted graph with N nodes numbered from 1 to N. 
        If we want to drop all edges with weight lower than C, how many nodes will still be reachable from node 1?
*/

#include<bits/stdc++.h>
using namespace std;
#define MX 50000
vector<pair<int,int> >vec[MX];
vector<int>tree[4*MX];
int n,arr[MX],dist[MX];
void build(int node,int l, int r)
{
    if(l==r)
    {
        tree[node].push_back(arr[r]);
        return;
    }
    int mid=(l+r)/2;
    int L=node*2;
    int R=node*2+1;
    build(L,l,mid);
    build(R,mid+1,r);
    merge(tree[L].begin(),tree[L].end(),tree[R].begin(),tree[R].end(),back_inserter(tree[node]));

}
int query(int node, int l, int r, int L, int R, int val)
{
    if(L>r || R<l)
        return 0;
    if(L<=l && r<=R)
        return lower_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin();
    int mid=(l+r)/2;
    int LS=mid*2;
    int RS=mid*2+1;
    int u=query(LS,l,mid,L,R,val);
    int v=query(RS,mid+1,r,L,R,val);
    return u+v;
}
void dfs(int src)
{
    for(int i=0; i<vec[src].size(); i++)
    {
        int node=vec[src][i].first;
        int cost=vec[src][i].second;
        if(arr[node]==-1)
        {
            arr[node]=min(cost,arr[src]);
            dfs(node);
        }
        else if(min(cost,arr[src])>arr[node])
        {
            arr[node]=min(cost,arr[src]);
            dfs(node);
        }
    }
}
int main()
{
    int t,e,q,u,v,w,x;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        memset(arr,0,sizeof(arr));
        memset(arr,-1,sizeof(arr));
        scanf("%d%d",&n,&e);
        for(int i=1; i<=e; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            vec[u].push_back({v,w});
            vec[v].push_back({u,w});
        }
        arr[1]=(int)1e9;
        dfs(1);
        build(1,1,n);
        scanf("%d",&q);
        printf("Case %d:\n",cs);
        for(int i=1;i<=q;i++)
        {
            scanf("%d",&x);
            printf("%d\n",n-query(1,1,n,2,n,x)-1);
        }
        for(int i=0;i<4*MX;i++)
            tree[i].clear();
        for(int i=0;i<MX;i++)
            vec[i].clear();
    }
}
