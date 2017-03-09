#include<bits/stdc++.h>
using namespace std;
int n;
int quick(int arr[],int low,int high)
{
    int temp,i,j,pivot;
    if(low<high)
    {
        pivot=low;
        i=low;
        j=high;
        temp=pivot;
        while(i<j)
        {
            while(arr[i]<arr[pivot] && i<high)
                i++;
            swap(arr[i],arr[pivot]);
            pivot=i;
            while(arr[j]>arr[pivot])
                j--;
            swap(arr[j],arr[pivot]);
            pivot=j;
        }
        quick(arr,low,j-1);
        quick(arr,j+1,high);
    }
}
int main()
{
    int arr[100];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    quick(arr,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
