#include<bits/stdc++.h>
using namespace std;
struct activity
{
    string id;
    int start;
    int finish;
};
int main()
{
    int total,i,j;
    cout<<"Total Number of Activities: ";
    cin>>total;
    activity act[total];
    cout<<"Enter activity name, start time and finish time: ";
    for(i=0; i<total; i++)
    {
        cin>>act[i].id>>act[i].start>>act[i].finish;
    }
    for(i=1; i<total; i++)
    {
        for(j=0; j<total-i; j++)
        {
            if(act[j].finish>act[j+1].finish)
                swap(act[j],act[j+1]);
        }
    }
    cout<<act[0].id<<endl;
    j=0;
    for(i=1;i<total;i++)
    {
        if(act[i].start>=act[j].finish)
        {
            cout<<act[i].id<<endl;
            j=i;
        }
    }
}
