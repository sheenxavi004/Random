#include<iostream>
using namespace std;
int maxprosub(int a[],int n)
{
    int max_pro_sofar=1;
    int min_pro_sofar=1;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            max_pro_sofar=max_pro_sofar*a[i];
            min_pro_sofar=min(1,min_pro_sofar*a[i]);
        }
        else if(a[i]==0)
        {
            max_pro_sofar=1;
            min_pro_sofar=1;
        }
        else
        {
            int temp=min_pro_sofar;
            min_pro_sofar=max_pro_sofar*a[i];
            max_pro_sofar=max(temp*a[i],1);
        }
        maxi=max(maxi,max_pro_sofar);
    }
    return maxi;
}
int main()
{
    int arr[]={2,3,-2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<maxprosub(arr,n)<<endl;
    return 0;
}