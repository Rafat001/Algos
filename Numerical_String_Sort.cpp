//    Credit Goes To Mr. Emrul Chowdhury    //

#include <bits/stdc++.h>
#define LL long long int
using namespace std;

map <LL, LL> mp;
vector <string> v[2000005];
vector <LL> v1;

int main()
{
    string s;
    LL n,i ;

    cin >> n;

    for( i=0; i<n; i++ )
    {
        cin >> s;
        if( mp[s.size()] == 0 )
        {
            v1.push_back(s.size());
        }
        mp[ s.size() ]++;
        v[ s.size() ].push_back(s);
    }

    sort( v1.begin(), v1.end() );

    for( i=0; i<v1.size(); i++ )
    {
        sort( v[v1[i]].begin(), v[v1[i]].end() );
        for( LL j=0; j<v[v1[i]].size(); j++ )
        {
            cout << v[v1[i]][j] << endl;
        }
    }
    return 0;
}
