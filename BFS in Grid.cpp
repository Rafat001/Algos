#include<stdio.h>
#include<queue>

using namespace std;
#define MAX 500

int row,col;
char box[MAX][MAX];
int visit[MAX][MAX],dis[MAX][MAX];

int rrr[]={1,0,-1,0};
int ccc[]={0,1,0,-1}; //4 Direction

void bfs(int start_x,int start_y)
{
    queue<int>Qx;
    queue<int>Qy;

    visit[start_x][start_y] = 1;
    dis[start_x][start_y]   = 0;

    Qx.push(start_x);
    Qy.push(start_y);

    while(!Qx.empty())
    {
        int x = Qx.front();
        int y = Qy.front();

        Qx.pop();
        Qy.pop();

        for(int i=0;i<4;i++) // for four direction move
        {
            int u = x+rrr[i];
            int v = y+ccc[i];

            if(0<=u && u<row && 0<=v && v<col)
            {
                if(visit[u][v]==0)
                {
                    if(box[u][v]=='.')
                    {
                        visit[u][v]=1;
                        dis[u][v] = dis[x][y]+1;

                        Qx.push(u);
                        Qy.push(v);
                    }
                }
            }
        }
    }

    return ;
}

int main()
{
    int i;
    scanf("%d%d",&row,&col);

    for(int i=0;i<row;i++) scanf(" %s",box[i]);

    int start_x = 0;
    int start_y = 0;

    bfs(start_x,start_y);


    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++) printf("%d ",dis[i][j]);
        printf("\n");
    }
}


/*
As it is a two dimensional grid we need to keep x and y for one position. So we use 2 Queues.
Here only . is visitable and x is not visitable.


Suppose we are in 1,0 position; If we want to make 4 moves up,down,right,left then our coordinate will be
0,0 if we go up
2,0 if we go down
1,-1 if we go left
1,1 if we go right

With rrr and ccc we are finding that thing and checking whether it is in the grid.


Input::

3 3
..x
x.x
...

*/
