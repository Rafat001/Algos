#include<stdio.h>
#include<math.h>

using namespace std;

#define MAX 100000

int flag[MAX];
int prime[MAX];
int prime_no;

void seive()
{
    int i,j;
    for(i=0;i<MAX;i++) flag[i] = 1;
    int lim = sqrt(MAX)+1;
    for(i=2;i<=lim;i++)
    {
        if(flag[i]==1)
        {
            for(j=i+i;j<MAX;j+=i)
            {
                flag[j] = 0;
            }
        }
    }

    prime_no = 0;
    for(i=2;i<MAX;i++)
    {
        if(flag[i]==1)
        {
            prime[prime_no] = i;
            prime_no++;
        }
    }
}

int divisor(int N)
{
    int i,val,count,sum;
    val = sqrt(N)+1;
    sum = 1;
    for(i=0;prime[i]<val;i++)
    {
        if(N%prime[i]==0)
        {
            count = 0;
            while(N%prime[i]==0)
            {
                N/=prime[i];
                count++;
            }
            sum*=(count+1);
        }
    }
    if(N>1) sum = sum*2;
    return sum;
}

int main()
{
    seive();
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("Number of divisors in %d is %d\n",n,divisor(n));
    }
    return 0;
}
