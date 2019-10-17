#include<bits/stdc++.h>
using namespace std;
const int MX=500005;
int num[MX],arr[MX];
vector<int>prime;
int n,m,k,x,vis[MX],start[MX],_left[MX],_right[MX],ee,a,b; // n means node
struct edge{
    int v,_next;
    edge(){}
    edge(int _v,int __next){v=_v,_next=__next;}
}edgeList[500000];

void init(){
    ee=0;
    memset(start,-1,sizeof(start));
    return;
}
int cnt=1;

void addEdge(int u,int v){
    u++;
    v++;
    edgeList[ee]=edge(v,start[u]);start[u]=ee;ee++;
    return;
}

bool dfs(int src){
    if(vis[src]==x)return false;
    vis[src]=x;
    for(int i=start[src];i!=-1;i=edgeList[i]._next){
        if(_right[edgeList[i].v]==-1){
            _right[edgeList[i].v]=src;
            _left[src]=edgeList[i].v;
            return true;
        }
    }
    for(int i=start[src];i!=-1;i=edgeList[i]._next){
        if(dfs(_right[edgeList[i].v])){
            _right[edgeList[i].v]=src;
            _left[src]=edgeList[i].v;
            return true;
        }
    }
    return false;
}
int HopCroft(){
    
    init();
    memset(_left,-1,sizeof(_left));
    memset(_right,-1,sizeof(_right));
    bool done=false;
    while(!done){
        x++;
        done=true;
        for(int i=1;i<=n;i++){
            if(_left[i]==-1 && dfs(i)){
                done=false;
            }
        }
    }
    int ret=0;
    for(int i=1;i<=n;i++)ret+=(_left[i]!=-1);
    return ret>>1;
}
