#include<bits/stdc++.h>
using namespace std;
bool visit[100][100];
int dp[100][100];
string s,s1,anss;
int ans,l,l1;
int lcs(int i,int j)
{
    if(i==0 || j==0)
        return 0;
    if(visit[i][j])
        return dp[i][j];
    if(s[i-1]==s1[j-1])
    {
        ans=1+lcs(i-1,j-1);
    }
    else
    {
        ans=max(lcs(i-1,j),lcs(i,j-1));
    }
    visit[i][j]=1;
    dp[i][j]=ans;
    return ans;
}
void printl(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(s[i-1]==s1[j-1])
    {
        anss+=s[i-1];
        printl(i-1,j-1);
    }
    else
    {
        if(dp[i-1][j]>dp[i][j-1])
        printl(i-1,j);
        else
        printl(i,j-1);
    }
}
int main()
{
    int i,j;
    cin>>s>>s1;
    l=s.size();
    l1=s1.size();
    cout<<lcs(l,l1)<<endl;
    printl(l,l1);
    reverse(anss.begin(),anss.end());
    cout<<anss<<endl;
}
