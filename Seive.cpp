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

int main()
{
    seive();
    printf("Total number of prime less than %d : %d\n\n",MAX,prime_no);
    for(int i=0;i<30;i++) printf("%d ",prime[i]); // printing some prime number below 30
}
