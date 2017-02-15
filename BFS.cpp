#include<stdio.h>
#include<queue>

using namespace std;
#define MAX 500

int node,edge;
int con[MAX][MAX];
int visit[MAX],dis[MAX];

void bfs(int start)
{
    queue<int>Q;

    visit[start] = 1;
    dis[start]   = 0;
    Q.push(start);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int v=0;v<=node;v++)
        {
            if(con[u][v]==1)
            {
                if(visit[v]==0)
                {
                    visit[v] = 1;
                    dis[v] = dis[u]+1;
                    Q.push(v);
                }
            }
        }
    }

    return ;
}

int main()
{
    int i;
    scanf("%d%d",&node,&edge);
    for(i=0;i<edge;i++)
    {
        int u,v; // there is connection between u and v
        scanf("%d%d",&u,&v);
        con[u][v] = 1;
        con[v][u] = 1;
    }

    int start = 1;
    bfs(start);


    for(int i=1;i<=node;i++) printf("Distance from %d to %d: %d\n",start,i,dis[i]);
}


/*
Input::

5 6
1 2
2 3
2 4
3 5
4 5
1 4

*/
