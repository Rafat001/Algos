#include<bits/stdc++.h>
using namespace std;
int main()
{
    int column_number;
    cin>>column;
    string columnName;
    int modulo;
    while (column_number> 0)
    {
        modulo = (column_number- 1) % 26;
        columnName+=(65+modulo)
        column_number = (column_number - modulo) / 26;
    }
    columnName.reverse();
    cout<<columnName<<endl
}
