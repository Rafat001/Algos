//Tested in Lightoj 1149 //

#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define mem(n) memset(n,0,sizeof(n))
#define LCM(a,b) (a / __gcd(a,b) ) * b
#define gcd(a,b) __gcd(a,b)
#define for0(l,n) for(int l=0;l<n;l++)
#define for1(l,n) for(int l=1;l<=n;l++)
#define bug(n) cout<<">> "<<n<<" <<";
#define pb push_back
#define squerit(n) (ll)n*n
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0)
#define MAX 205
 
vector<int>v[MAX];
ll n,m,q,a,b,c,sum=0,cnt=0;
//ll arr[1000055];
map<ll,bool>mp;
string s;
int match[MAX];
bool  col[MAX];
bool  dfs(int nd)
{
    int sz = v[nd].size();
    for0(i,sz)
    {
        int u = v[nd][i];
        if(!col[u])
        {
            col[u]=1;
            if(match[u]==-1 || dfs(match[u]))
            {
                match[u]=nd;
                return true;
            }
        }
    }
    return false;
}
int BPM()
{
    memset(match,-1,sizeof(match));
    int cnt = 0;
 
    for0(i,n)
    {
        mem(col);
        //  col[i]=1;
        if(dfs(i))
            cnt++;
    }
    return cnt;
}
int arr[MAX],brr[MAX];
int main()
{
    //freopen("output.txt","w",stdout);
    FastRead;
    int t,cs=1,m,p;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>m;
        for(int i=0;i<m;i++)
            cin>>brr[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(brr[j]%arr[i]==0)
                    v[i].pb(j);
            }
        }
        n=n+m;
        cout<<"Case "<<cs<<": "<<BPM()<<endl;
        for0(i,n)
        {
            v[i].clear();
        }
    }
 
 
}
