// Complexity O(Qlogn+Nlogn)

#include <bits/stdc++.h>
using namespace std;
#define MX  200005

struct info
{
    int lazy,sum;
    info() : lazy(-1), sum(0) {}
} tree[4*MX];

void update_lazy(int node, int st, int en, int val)
{
    tree[node].lazy = val;
    tree[node].sum = (en-st+1)*val;
}

void update_node(int node, int st, int en)
{
    int left=node*2;
    int right=node*2+1;
    int mid = (st+en)/2;

    tree[left].lazy=tree[right].lazy=tree[node].lazy;

    tree[left].sum= (mid-st+1)*tree[left].lazy;
    tree[right].sum= (en-mid)*tree[right].lazy;

    tree[node].lazy=-1;
}

void merger(int node)
{
    int left=node*2;
    tree[node].sum= tree[left].sum + tree[left+1].sum;
}

void update(int node, int s, int e, int i, int j, int val)
{

    if(s==i && e==j)
    {
        update_lazy(node,s,e,val);
        return;
    }
    if(tree[node].lazy!=-1)
    {
        update_node(node,s,e);
    }

    int left=node*2;
    int mid=(s+e)/2;

    if(j<=mid)
    {
        update(left,s,mid,i,j,val);
    }
    else if(mid<i)
    {
        update(left+1,mid+1,e,i,j,val);
    }
    else
    {
        update(left, s, mid, i, mid, val);
        update(left+1, mid+1, e, mid+1, j, val);
    }

    merger(node);
}

int query(int node, int s, int e, int i, int j)
{
    if(s==i && e==j)
    {
        return tree[node].sum;
    }
    if(tree[node].lazy!=-1)
    {
        update_node(node,s,e);
    }

    int left=node*2;
    int mid=(s+e)/2;

    int res=0;
    if(j<=mid)
    {
        res+=query(left, s, mid, i, j);
    }
    else if(i>mid)
    {
        res+=query(left+1, mid+1, e, i, j);
    }
    else
    {
        res+=(query(left, s, mid, i, mid)+ query(left+1, mid+1, e, mid+1, j));
    }
    merger(node);
    return res;
}
int main()
{
    int t,no=0;

    int n,m,l,r,x;
    scanf("%d%d",&n,&m);
    info p;
    p.lazy = -1;
    p.sum = 0;
    fill_n(tree, sizeof(tree)/sizeof(*tree), p);
    while(m--)
    {
        scanf("%d%d%d",&l,&r,&x);
        update(1,1,n,l,r,x);
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d",query(1,1,n,i,i));
        if(i==n)
            printf("\n");
        else
            printf(" ");
    }
    return 0;
}
