#include<iostream>
using namespace std;
int kadane(int *arr,int n)
{
    int curr_sum=0;
    int best_sum=0;
    for(int i=0;i<n;i++)
    {
        curr_sum+=arr[i];
        if(curr_sum>best_sum)
            best_sum=curr_sum;
        if(curr_sum<0)
            curr_sum=0;
    }
    return best_sum;
}
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n = sizeof(a)/sizeof(a[0]); 
    cout<<kadane(a,n);
    return 0;
}