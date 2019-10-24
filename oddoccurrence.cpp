#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n],res=0;
    cout<<"enter duplictates of all numbers except 1\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        res=res^arr[i];
    }
    cout<<"single element is "<<res<<"\n";
    return 0;
}