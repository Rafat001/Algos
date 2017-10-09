#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >vv[105];
int dist[105];
void bfs(int src)
{
    int node,temp,cost,weight;
    dist[src]=0;
    priority_queue<pair<int,int> >pq;
    pq.push({src,0});
    while(!pq.empty())
    {
        temp=pq.top().first;
        cost=pq.top().second*-1;
        pq.pop();
        for(int i=0; i<vv[temp].size(); i++)
        {
            node=vv[temp][i].second;
            weight=vv[temp][i].first;
            if(dist[node]==-1)
            {
                dist[node]=weight+dist[temp];
                pq.push({node,-1*dist[node]});
            }
            else if(dist[node]>dist[temp]+weight)
            {
                dist[node]=dist[temp]+weight;
                pq.push({node,-1*dist[node]});
            }
        }
    }
}
int main()
{
    int n,m,t,from,u,v,w;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        memset(dist,-1,sizeof(dist));
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            vv[u].push_back({w,v});
            vv[v].push_back({w,u});
        }
        bfs(1);
        printf("Case %d: ",cs);
        if(dist[n]==-1)
            printf("Impossible\n");
        else
            printf("%d\n",dist[n]);
        for(int i=0; i<105; i++)
            vv[i].clear();
    }
}

