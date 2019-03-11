/*
Bellman Ford Algorithm By Rafat
Used to find single source shortest path with negative edge
Time Complexity: O(|V|*|E|)
Drawback: Won't work if there is a negative cycle
*/

#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f
int dist[100005];
struct graph{
    int from,to,cost;
    graph(int a,int b,int c){
        from=a;
        to=b;
        cost=c;
    }
};
vector<graph>ListOfEdges;
int nodes,edges;
void Bellman_Ford()
{
    for(int i=1;i<=nodes-1;i++) // The main idea of bellman ford is to relax edges n-1 times. that's what this loop for! //
    {
        int changed=0;
        for(int j=0;j<ListOfEdges.size();j++)
        {
            // Relaxation Starts

            int src=ListOfEdges[j].from;
            int destination=ListOfEdges[j].to;
            int weight=ListOfEdges[j].cost;

            if(dist[src]+weight<dist[destination]) // Relaxation condition
                {
                    dist[destination]=dist[src]+weight;
                    changed++; // it indicates we found a new shortest path in this iteration
                }

            // Relaxation Ends
        }
        if(changed==0) // indicates that our graph is now stable
            break;
    }
}
int main()
{
    int u,v,c;
    memset(dist,inf,sizeof(dist)); // Assigning distance array with a large value (inf)
    scanf("%d%d",&nodes,&edges);
    dist[1]=0; // let 1 be the source that's why distance of 1 is 0.
    for(int i=1;i<=edges;i++)
    {
        scanf("%d%d%d",&u,&v,&c);
        ListOfEdges.push_back(graph(u,v,c));
    }
    Bellman_Ford();
    for(int i=1;i<=nodes;i++)
        printf("Destination of Node %d from 1 is %d\n",i,dist[i]);
}

