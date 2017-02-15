struct data{
    int v,w;
    bool operator<(const data &p)const
    {
        return p.w<w; ///in ascending order
    }
};

vecotr<data>con[];dis[];
//whoTo[];color[]

bool relax(int u,int v,int w)
{
    if(dis[v]>dis[u]+w)
    {
        dis[v]=dis[u]+w;
        //whoTo[v]=u;
        return true;
    }
    return false;
}


void dij(int start,int end)
{
    priority_queue<data>pq;
    clear dis[] with inf;
    dis[start]=0;
    //whoTo[start]=start;
    pq.push(data(start,0));
    data tmp;
    while(!pq.empty())
    {
        tmp=pq.top();
        pq.pop();
        //if(color[tmp.v]==0)
        //{
        //color[tmp.v]=1;
        int u=tmp.v;
        if(u==end)return;

        for(int i=0;i<SZ(con[u]);i++)
        {
            tmp=con[u][i];
            if(relax(u,tmp.v,tmp.w))
            {
                pq.push(data(tmp.v,dis[tmp.v]));
            }
        }
        //} END OF COLOR BLOCK
     }
     return;
}
