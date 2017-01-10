#include<bits/stdc++.h>
using namespace std;
int main()
{
    string columnName;
    cin>>columnName;
    int l=columnName.length(),sum=0;
    for(int i=0;i<l;i++)
    {
        sum*=26;
        sum+=(columnName[i] - 'A' + 1);
    }
    cout<<sum<<endl                     //here sum is The Column Number//
}
