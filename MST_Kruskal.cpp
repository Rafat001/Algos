struct data{
    int u,v,w;
};
vector<data>vecEdge;

int findparent(int r)
{
    if(inTree[r]==r)return r;
    return inTree[r]=findparent(inTree[r]);
}

double kruskal()
{
    sort(vecEdge);
    for(int i=0;i<MAX;i++)inTree[i]=i;
    double totaldis=0;
    for(int i=0;i<SZ(vecEdge);i++)
    {
        int a=findparent(vecEdge[i].u);
        int b=findparent(vecEdge[i].v);

        if(a!=b)
        {
            totaldis+=vecEdge[i].w;
            inTree[a]=b;
        }
    }
    return totaldis;
}


