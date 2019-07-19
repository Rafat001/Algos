// Explanation learned from CSDN Blog //
// This code calculates M^1+M^2+M^3+M^4+....+M^k efficiently

#include<stdio.h>
#include<vector>
using namespace std;
#define ll int
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define matrix vector<vector<ll> >
int MP;
#define new_matrix vector<vector<ll> >(MP,vector<ll>(MP,0))

int MOD=10007;

matrix multiply(const matrix &a,const matrix &b)
{
    matrix answer = new_matrix;
    for(int i = 0 ; i < MP ; ++i)
    {
        for(int j = 0; j < MP; ++j)
        {
            answer[i][j] = 0;
            for(int k = 0; k < MP; ++k)
            {
                answer[i][j] = (answer[i][j]+a[i][k]*b[k][j])%MOD;
            }
        }
    }
    return answer;
}
matrix mod_pow(matrix m, ll n)
{
    matrix answer = new_matrix;
    for(int i = 0; i< MP; ++i)
        for(int j = 0; j < MP; ++j)
            if(i==j)
                answer[i][j] = 1;

    for(ll i = n; i > 0; i>>=1)
    {
        if(i&1)
            answer = multiply(answer,m);

        m = multiply(m,m);
    }

    return answer;
}

matrix Add(const matrix &a,const matrix &b)
{
    matrix answer = new_matrix;
    for(int i=0; i<MP; ++i)
    {
        for(int j=0; j<MP; ++j)
            answer[i][j] = (a[i][j] + b[i][j]) % MOD;
    }
    return answer;
}

matrix solveBinary(const matrix &a, int n)
{
    if(n==1)
        return a;

    matrix answer = new_matrix;
    matrix tmp = new_matrix;
    answer = solveBinary(a,n/2);
    if(n&1)
    {
        tmp = mod_pow(a, n/2+1);
        answer = Add(answer, multiply(tmp, answer));
        answer = Add(tmp, answer);
    }
    else
    {
        tmp = mod_pow(a, n/2);
        answer = Add(answer, multiply(tmp, answer));
    }
    return answer;
}

int main()
{
    ll n,m,k;
    scanf("%d%d%d",&n,&k,&MOD);
    MP=n;
    matrix mat=new_matrix;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            scanf("%d",&mat[i][j]);
    }
    mat=solveBinary(mat,k);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<MP; j++)
        {
            printf("%d",mat[i][j]);
            if(j==MP-1)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}
/*
We know that the matrix A^x can be solved quickly by the matrix fast power. We must consider how to reduce the computation is S = A + A ^ 2 + A ^ 3 + ... A ^ k + during the addition of this time-consuming operation. Below we consider matrix A as a normal number A. 

For S(10) we have: 

S(10) = A + A^2 + A^3 +A^4 + A^5 + A^5 * (A +  A^2 +A^3 +A^4 + A^5 )



For S(5) we have:

S(5) =  A + A^2 + A^3 + A^3 * ( A + A^2 )


For S(2) we have:

S(2) = A + A * (A)



The value of A has been given in the question, then we can get the value of S(2) by recursive backtracking, and find the value of A^3, then we can get the value of S(5) by the above formula, and then get S The value of (10). Then for each S(k) we can do this two-way recursive solution. Note that S(n) here requires an additional value of A^(n/2+1) when n is odd (for example, S(5) above). Finally, add the matrix's fast power and addition operations.
*/
