#include <bits/stdc++.h>
using namespace std;
void lcs(string str1, string str2, int len1, int len2)
{
    int i, j;
    int matrix[len1+1][len2+1];
    for(i=0; i<=len1; i++)
    {
        for(j=0; j<=len2; j++)
        {
            if(i==0 || j==0)
            {
                matrix[i][j] = 0;
            }
            else if(str1[i-1] == str2[j-1])
            {
                matrix[i][j] = 1+ matrix[i-1][j-1];
            }
            else
            {
                matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
            }
        }
    }
    int max_length = matrix[len1][len2];
    cout << "Maximum Score: " << max_length << endl;
    string ans;
    i=len1,j=len2;
    while (i > 0 && j > 0)
    {
        if (str1[i-1] == str2[j-1])
        {
            ans+=str1[i-1];
            i--;
            j--;
        }
        else if (matrix[i-1][j] > matrix[i][j-1])
            i--;
        else
            j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
int main()
{
    string str1, str2;
    int len1, len2;
    cout << "Enter string 1: ";
    cin >> str1;
    cout << "Enter string 2: ";
    cin >> str2;
    len1 = str1.length();
    len2 = str2.length();
    lcs(str1, str2, len1, len2);
}
