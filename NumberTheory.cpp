#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll num[50],rem[50];
vector<ll>parts
char s[100005];
void divide(int len) // divides the actual string into several integer parts of 9 digits. 
{
    // len= actual numerical string size
    parts.clear();
    ll total=0;
    int po=0;
    for(int i=len-1; i>=0; i--){
 
        ll add=s[i]-'0'; // s is the actual string
        add*=power[po];
        total+=add;
        if(po==9 || i==0){
 
            parts.push_back(total);
            po=0;
            total=0;
        }
        else po++;
    }
    reverse(parts.begin(), parts.end());
}
 
ll modulo(ll x) // calculates string modulo x efficiently
{
    ll mod=0;
    for(int i=0; i<parts.size(); i++){
 
        mod=mod*power[10];
        mod%=x;
        mod+=parts[i];
        mod%=x;
 
    }
    return mod;
}
ll stringModx(ll x) // returns S % X where S is a numerical string.
{
    divide(strlen(s));
    return modulo(x);
}
ll inv(ll a, ll m) // returns inverse(a)%m
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
       return 0;

    while (a > 1)
    {
        q = a / m; // q is quotient
        t = m; // m is remainder now, process same as euclid's algo
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;  // Make x1 positive

    return x1;
}
int SNOD( int n ) //Sum of NOD
{
    int res = 0;
    int u = sqrt(n);
    for ( int i = 1; i <= u; i++ ) {
        res += ( n / i ) - i;
    }
    res *= 2;
    res += u;
    return res;
}
int SOD( int n )
{
    int res = 1;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            int tempSum = 1; // Contains value of (p^0+p^1+...p^a)
            int p = 1;
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                p *= prime[i];
                tempSum += p;
            }
            sqrtn = sqrt ( n );
            res *= tempSum;
        }
    }
    if ( n != 1 ) {
        res *= ( n + 1 ); // Need to multiply (p^0+p^1)
    }
    return res;
}
ll ChineseRemainder(int k) // given some numbers num[] and reminders rem[] find smallest x such that x%num[i]=rem[i] for all i from 0 to k
{
    ll prod = 1;
    for (int i = 0; i < k; i++)
        prod =prod*1LL*num[i];

    ll result = 0;

    for (int i = 0; i < k; i++)
    {
        ll pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }
    return result % prod;
}

ll largestPower(ll n, ll p) //Legendre’s formula.. returns largest power of P that divides n!
{
    ll x = 0;
    while (n) // Calculate x = n/p + n/(p^2) + n/(p^3) + ....
    {
        n /= p;
        x += n;
    }
    return x;
}

ll trailing_Zeroes_of_N_Factorial_in_base_b(ll n, ll b)
{
    ll ans=(ll)1e18;
    for(int i=2;i<=sqrt(b);i++)
    {
        ll cnt=0;
        while(b%i==0)
        {
            b/=i;
            cnt++;
        }
       // cout<<i<<" "<<cnt<<" "<<b<<endl;
        if(cnt) ans=min(ans,largestPower(n,i)/cnt);
    }
    if(b!=1) ans=min(ans,largestPower(n,b));
    return ans;
}
ll catalan_number(ll n) //returns nTh catalan number
{
    ll c=nCr(2*n,n);
    return c/(n+1);
    /* Application of catalan numbers
    1. Number of possible Binary Search Trees with n keys.
    2. Number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
    3. Number of ways a convex polygon of n+2 sides can split into triangles by connecting vertices.
    4. Number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
    5. Number of different Unlabeled Binary Trees can be there with n nodes.
    6. The number of paths with 2n steps on a rectangular grid from bottom left, i.e., (n-1, 0) to top right (0, n-1) that do not cross above the main diagonal.
    7. Number of ways to insert n pairs of parentheses in a word of n+1 letters, e.g., for n=2 there are 2 ways: ((ab)c) or (a(bc)). For n=3 there are 5 ways, ((ab)(cd)), (((ab)c)d), ((a(bc))d), (a((bc)d)), (a(b(cd))).
    8. Number of Dyck words of length 2n. A Dyck word is a string consisting of n X’s and n Y’s such that no initial segment of the string has more Y’s than X’s.  For example, the following are the Dyck words of length 6: XXXYYY     XYXXYY     XYXYXY     XXYYXY     XXYXYY.
    9. Number of ways to form a “mountain ranges” with n upstrokes and n down-strokes that all stay above the original line.The mountain range interpretation is that the mountains will never go below the horizon.
    10. Number of stack-sortable permutations of {1, …, n}. A permutation w is called stack-sortable if S(w) = (1, …, n), where S(w) is defined recursively as follows: write w = unv where n is the largest element in w and u and v are shorter sequences, and set S(w) = S(u)S(v)n, with S being the identity for one-element sequences.
    11. Number of permutations of {1, …, n} that avoid the pattern 123 (or any of the other patterns of length 3); that is, the number of permutations with no three-term increasing subsequence. For n = 3, these permutations are 132, 213, 231, 312 and 321. For n = 4, they are 1432, 2143, 2413, 2431, 3142, 3214, 3241, 3412, 3421, 4132, 4213, 4231, 4312 and 4321
    */
}
ull mul(ull a, ull b)
{
    ull res = 0;

    while (b){
        if (b & 1LL) res = (res + a);
        if (res >= n) return 0;
        a = (a << 1LL);
        b >>= 1LL;
    }

    return res;
}
int p, primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 51, 53, 59, 61, 67, 71};
void backtrack(int i, int lim, ull val, ull r)
{
    if (r > res) res = r;
    if (i == p) return;

    int d;
    ull x = val;

    for (d = 1; d <= lim; d++){
        x = mul(x, primes[i]);
        if (x == 0) return;
        backtrack(i + 1, d, x, r * (d + 1));
    }
}
ull maximum_NOD_of_any_number_less_than_N(ull n)
{
    p = sizeof(primes) / sizeof(int);
    res=0;
    backtrack(0, 100, 1, 1);
    return res;
}
