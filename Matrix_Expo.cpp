// Credit = Araf-Al-Jami
// Complexity = O(log(n))
// Code for  UVA-10229 - Modular Fibonacci

#include<bits/stdc++.h>
using namespace std;
int mod=(int)1e9+7;
const int mat_sz = 2;
struct Matrix {
    int a[mat_sz][mat_sz];
    void clear() {
        memset(a, 0, sizeof(a));
    }
    void one() {
        for( int i=0; i<mat_sz; i++ ) {
            for( int j=0; j<mat_sz; j++ ) {
                a[i][j] = 1;
            }
        }
        a[1][1]=0;
    }
    void print()
    {
        for( int i=0; i<mat_sz; i++ ) {
            for( int j=0; j<mat_sz; j++ ) {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    Matrix operator + (const Matrix &b) const {
        Matrix tmp;
        tmp.clear();
        for (int i = 0; i <  mat_sz; i++) {
            for (int j = 0; j < mat_sz; j++) {
                tmp.a[i][j] = a[i][j] + b.a[i][j];
                if (tmp.a[i][j] >= mod) {
                    tmp.a[i][j] -= mod;
                }
            }
        }
        return tmp;
    }
    Matrix operator * (const Matrix &b) const {
        Matrix tmp;
        tmp.clear();
        for (int i = 0; i < mat_sz; i++) {
            for (int j = 0; j < mat_sz; j++) {
                for (int k = 0; k < mat_sz; k++) {
                    tmp.a[i][k] += (long long)a[i][j] * b.a[j][k] % mod;
                    if (tmp.a[i][k] >= mod) {
                        tmp.a[i][k] -= mod;
                    }
                }
            }
        }
        return tmp;
    }
    Matrix pw(int x) {
        Matrix ans, num = *this;
        ans.one();
        while (x > 0) {
            if (x & 1) {
                ans = ans * num;
            }
            num = num * num;
            x >>= 1;
        }
        return ans;
    }
};
int main()
{
    int n,m,cnt=1;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        mod=(1<<m);
        if(m==0)
            mod=1;
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        Matrix mat;
        mat.one();
        Matrix ans=mat.pw(n-1);
        long long c=ans.a[1][0];
        printf("%lld\n",c%mod);
    }
}
