/* Algo
1 . For each node find the minimum incoming edge except root
2 . Look for cycle if there is no cycle its MST
3 . If cycle then consider one cycle as a one single vertex , give every vertex a new indx  and again recalculate the every edge
4 . goto step 2
*/
// Directed MST (Edmond's Algo) Template Credit https://github.com/shakilaust
// Tested On LightOJ 1380

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
const int Maxn = 1005 ; // Highest Vertex

struct edge
{
    int u , v , w ;
    edge() {}
    edge(int _u, int _v , int _w ) { u = _u , v = _v , w = _w ; }
};

int nodes , edges , root ; // nV = number of vertex , nE = number of edge , root is root
int vis[Maxn] , parnt[Maxn] ; // vis[] will store from which cycle it belogs , pre[] store its parnt
int Idx[Maxn] ; // will store new indxing Id
int dis[Maxn] ; // store the lowest incoming edge of a root
vector < edge > vec ;

int DMST()
{
    int ans  = 0 , i , u ,  v , w  ;
    while(true)
    {
        int i  ;
        for(i=0;i<nodes;i++)
        {
            dis[i] = INF ;
            vis[i] = -1 ;
            Idx[i] = -1 ;
        }
        for(i=0;i<vec.size();i++)
        {
            u = vec[i].u ;
            v = vec[i].v ;
            w = vec[i].w ;
            if ( u != v && dis[v] > w) // lowest Incoming Edge
            {
                parnt[v] = u ;
                dis [v] = w ;
            }
        }
        parnt[root] = root ;
        dis[root] = 0 ;
        for(i=0;i<nodes;i++)
        {
            if( dis[i] == INF )
            {
               return -1; // its not possible to reach
            }
            ans += dis[i];
        }
        int idx = 0 ;
        // cycle detection
        for(i=0;i<nodes;i++)
        {

            if(vis[i]==-1) // not yet visited
            {
                int cur = i ;
                while ( vis[cur]==-1)
                {
                    vis[cur] = i ;
                    cur = parnt[cur] ;
                }
                if ( cur == root || vis[cur] != i )  continue ; // not cycle
                Idx[cur] = idx ; // new indexing
                for (  u = parnt[cur] ; cur != u ; u = parnt[u] )
                Idx[u] = idx ;
                idx++;
            }
        }
        if(idx==0) break ; // no cycle
        for(i=0;i<nodes;i++)
        {
            if(Idx[i]==-1) // yet not find any grp
            {
                Idx[i] = idx++;
            }
        }
        for(i=0;i<vec.size();i++)
        {
            vec[i].w -= dis[vec[i].v];
            vec[i].u = Idx[vec[i].u] ;
            vec[i].v = Idx[vec[i].v];
        }
        nodes = idx++;
        root = Idx[root];
    }
    return ans;
}
int main()
{
    int t,m,a,b,c,n;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d%d%d",&nodes,&edges,&root);
        for(int i=1; i<=edges; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            edge ede=edge(a,b,c);
            vec.push_back(ede);
        }
        int ans=DMST();
        if(ans==-1)
            printf("Case %d: impossible\n",cs);
        else
            printf("Case %d: %d\n",cs,ans);
        vec.clear();
    }
}
