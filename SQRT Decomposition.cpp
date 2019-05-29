// LightOJ 1135
// Rafat's Code

#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair <ll, ll> pll;

const int Max = 2e6 + 10;
const int Mod = 1e9 + 7;

ll BLOCK[1001];
ll ONE[1001];
ll TWO[1001];

ll prop[1001];

ll BLOCK_SIZE,n;
ll ar[100001];
ll getID(ll idx) // get the block number for idx position
{
    ll id = idx / BLOCK_SIZE;
    return id;
}

ll calc()
{
    for(int i = 1; i < 1000; i++) // initializing the blocks as per statement
    {
        BLOCK[i] = BLOCK_SIZE;
        if(i*BLOCK_SIZE>n)
        {
            BLOCK[i]=n-((i-1)*BLOCK_SIZE);
        }
    }
}

ll query(int l, int r)
{
    int lf = getID(l);
    int rt = getID(r);

    ll ret = 0;

    if(lf == rt)
    {
        for(int i = l; i <= r; i++)
        {
            if((ar[i]+prop[lf])%3==0)
                ret++;
        }
        return ret;
    }

    for(int i = l; i < (lf + 1) * BLOCK_SIZE; i++)
    {
        if((ar[i]+prop[lf])%3==0)
                ret++;
        //cout<<"dus "<<ret<<endl;
    }

    for(int i = lf + 1; i < rt; i++)
    {
        if(prop[i]%3==0)
            ret += BLOCK[i];
        else if(prop[i]%3==2)
            ret += ONE[i];
        else
            ret += TWO[i];
    }

    for(int i = rt * BLOCK_SIZE; i <= r; i++)
    {
        if((ar[i]+prop[rt])%3==0)
                ret++;
    }
    return ret;
}
void update(int l, int r)
{
    int lf = getID(l);
    int rt = getID(r);

    //ll ret = 0;

    if(lf == rt) // same block e L, R porle linear calculation
    {
        for(int i = l; i <= r; i++)
        {
            if(ar[i]%3==0)
            {
                BLOCK[lf]--;
                ONE[lf]++;
            }
            else if(ar[i]%3==1)
            {
                ONE[lf]--;
                TWO[lf]++;
            }
            else if(ar[i]%3==2)
            {
                BLOCK[lf]++;
                TWO[lf]--;
            }
            ar[i]+=1;
        }
        return;
    }

    for(int i = l; i < (lf + 1) * BLOCK_SIZE; i++) // first block er fraction calculation
    {
        if(ar[i]%3==0)
        {
            BLOCK[lf]--;
            ONE[lf]++;
        }
        else if(ar[i]%3==1)
        {
            ONE[lf]--;
            TWO[lf]++;
        }
        else if(ar[i]%3==2)
        {
            BLOCK[lf]++;
            TWO[lf]--;
        }
        ar[i]+=1;
    }

    for(int i = lf + 1; i < rt; i++) // majer all blocks er calculation
    {
        prop[i]+=1;
    }

    for(int i = rt * BLOCK_SIZE; i <= r; i++) // last block er fraction calculation
    {
        if(ar[i]%3==0)
        {
            BLOCK[rt]--;
            ONE[rt]++;
        }
        else if(ar[i]%3==1)
        {
            ONE[rt]--;
            TWO[rt]++;
        }
        else if(ar[i]%3==2)
        {
            BLOCK[rt]++;
            TWO[rt]--;
        }
        ar[i]+=1;
    }
}
int main()
{
    int  q, l, r, t, type;

    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        printf("Case %d:\n",cs);

        memset(BLOCK,0,sizeof(BLOCK));
        memset(ONE,0,sizeof(ONE));
        memset(TWO,0,sizeof(TWO));
        memset(prop,0,sizeof(prop));
        memset(ar,0,sizeof(ar));

        scanf("%d %d", &n, &q);

        BLOCK_SIZE=sqrt(n)+1;
        calc();
        
        for(int i = 1; i <= q; i++)
        {
            scanf("%d %d %d", &type, &l, &r);
            l++,r++;
            if(type==0)
                update(l,r);
            else
                printf("%d\n",query(l,r));
        }
    }
    return 0;
}
