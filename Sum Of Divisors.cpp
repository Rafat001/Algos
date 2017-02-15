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

int sum_of_divisor(int N)
{
    int i,val,count,sum,p,s;
    val = sqrt(N)+1;
    sum = 1;
    for(i=0;prime[i]<val;i++)
    {
        if(N%prime[i]==0)
        {
            p=1;
            while(N%prime[i]==0)
            {
                N/=prime[i];
                p=p*prime[i];
            }
            p=p*prime[i];
            s=(p-1)/(prime[i]-1);
            sum=sum*s;
        }
    }
    if(N>1)
    {
        p=N*N;
        s=(p-1)/(N-1);
        sum=sum*s;
    }
    return sum;
}

int main()
{
    seive();
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("Sum of divisors of %d is %d\n",n,sum_of_divisor(n));
    }
    return 0;
}

