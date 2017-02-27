#include<bits/stdc++.h>
using namespace std;
vector<string>s;
bool compare(string s1, string s2)
{
    long long l1,l2;
    l1=s1.size(),l2=s2.size();
    if(l1!=l2)
        return l1<l2;
    else
        return s1<s2;
}
int main()
{
    long long n,i;
    string c;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>c;
        s.push_back(c);
    }
    sort(s.begin(),s.end(),compare);
    for(i=0; i<n; i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}
