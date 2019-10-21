#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll kadane(int arr[],int n)
{
    ll curr_sum=0;
    ll max_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        curr_sum+=arr[i];
        if(curr_sum>max_sum)
            max_sum=curr_sum;
        if(curr_sum<0)
            curr_sum=0;
    }
    return max_sum;
}
ll LongestSum(int arr[],int n,int k)
{
    ll kadanes_sum=kadane(arr,n);
    if(k==1)
        return kadanes_sum;
    ll curr_prefix_sum=0;
    ll max_prefix_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        curr_prefix_sum+=arr[i];
        max_prefix_sum=max(curr_prefix_sum,max_prefix_sum);
    }
    ll totalSum=curr_prefix_sum;
    ll curr_suffix_sum=0;
    ll max_suffix_sum=INT_MIN;
    for(int i=n-1;i>=0;i-- )
    {
        curr_suffix_sum+=arr[i];
        max_suffix_sum=max(curr_suffix_sum,max_prefix_sum);
    }
    if(totalSum<0)
    {
        return max(max_prefix_sum+max_suffix_sum,kadanes_sum);
    }
    else
        return max(max_prefix_sum+(k-2)*totalSum+max_suffix_sum,kadanes_sum);

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<LongestSum(arr,n,k)<<endl;
    }
    return 0;
}