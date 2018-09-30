// LightOJ 1065

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define matrix vector<vector<int> >
#define MP 2
#define new_matrix vector<vector<int> >(MP,vector<int>(MP,0))

void _print(matrix m){
    for(int i = 0 ; i< MP ; ++i){
        for(int j = 0; j< MP; ++j){
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}

int MOD=1000;

matrix multiply(const matrix &a,const matrix &b){
    matrix answer = new_matrix;
    for(int i = 0 ; i < MP ; ++i){
        for(int j = 0; j < MP; ++j){
            answer[i][j] = 0;
            for(int k = 0; k < MP; ++k){
                answer[i][j] += (a[i][k]*b[k][j])%MOD;
                answer[i][j] %= MOD;
            }
        }
    }
    return answer;
}

matrix mod_pow(matrix m, int n){
    matrix answer = new_matrix;
    for(int i = 0; i< MP; ++i)
        for(int j = 0; j < MP; ++j)
            if(i==j) answer[i][j] = 1;

    for(int i = n; i > 0; i>>=1){
        if(i&1)
            answer = multiply(answer,m);

        m = multiply(m,m);
    }

    return answer;
}


int main(){
    int tc;cin>>tc;
    for(int tid = 1; tid <= tc ; ++tid){
        long long n,a,b,c,m;
        cin>>a>>b>>n>>m;
        MOD=10;
        for(int i=2;i<=m;i++)
        {
            MOD*=10;
        }
        long long ans = 0,ans1=0;
        if(n >= 2){
            matrix mat =  new_matrix;
            mat[0][0] = 1;
            mat[0][1] = 1;
            mat[1][0] = 1;
            mat[1][1] = 0;

            matrix answer = mod_pow(mat,n-1);

            ans = (long long)answer[0][0]*b;
            long long x=(long long)answer[0][1]*a;
            ans+=x;
            ans %= MOD;

        }
        if(n==0)
            ans=a;
        if(n==1)
            ans=b;
        printf("Case %d: %d\n",tid,ans%MOD);
    }

    return 0;
}
