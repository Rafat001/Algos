#include<bits/stdc++.h>
using namespace std;
stack<char>st;
set<int>ste;
int arr[256][256],n,visit[256];
void dfs(int src)
{
    visit[src]=1;
    int i;
    for(i=64;i<=125;i++)
    {
        if(arr[src][i]==1 && visit[i]==0)
        {
            // 9
            //cout<<src<<" "<<i<<endl;
            dfs(i);
        }
    }
    st.push(src);
    ste.erase(src);
}
int main()
{
    char u,v,src;
    int e,i;
    memset(arr,0,sizeof(arr));
    cin>>n>>e;
    for(i=0;i<e;i++)
    {
        cin>>u>>v;
        ste.insert(u);
        ste.insert(v);
        arr[u][v]=1;
        //cout<<(int)u<<" "<<(int)v<<endl;
    }
    cout<<"Enter The Source: ";
    cin>>src;
    dfs(src);
    set<int>::iterator it;
    for(it=ste.begin(); it!=ste.end(); ++it)
    {
        if(!st.empty())
        dfs(*it);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
