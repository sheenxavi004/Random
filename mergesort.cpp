#include<iostream>
#include<sys/time.h>
#include<iomanip>
using namespace std;
long getTimeinMicroseconds()
{
    struct timeval start;
    gettimeofday(&start,NULL);
    return start.tv_sec*1000000+start.tv_usec;
}
int * createArray(int n)
{
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        arr[i]=n-i;
    return arr;
}
void merge(int arr[],int start,int mid,int end)
{
    int temp[end-start];
    int i=start;
    int j=mid+1;
    int k=0;
    while((i<=mid)&&(j<=end))
    {
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else 
            temp[k++]=arr[j++];
    }
    if(i<=mid)
        while(i<=mid)
            temp[k++]=arr[i++];
    else if(j<=end)
            while(j<=end)
                temp[k++]=arr[j++];
    k=0;
    for(int l=start;l<=end;l++)
    {
        arr[l]=temp[k++];
    }
}
void mergesort(int arr[],int start,int end)
{
    if(start>=end)
        return;
    int mid=(start+end)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,mid,end);
}
void selectionSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=arr[i];
        int pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                pos=j;
            }
            int temp=arr[i];
            arr[i]=min;
            arr[pos]=temp;
        }
    }
}
int main()
{
    cout<<"TIME IN MICROSECONDS\n";
    cout<<left<<setw(10)<<"n"<<left<<setw(15)<<"mergesort"<<left<<setw(20)<<"selectionsort"<<"\n";
    for(int n=10;n<=1000000;n=n*10)
    {   
        int *arr=createArray(n);
        long start_time_merge=getTimeinMicroseconds();
        mergesort(arr,0,n-1);
        long end_time_merge=getTimeinMicroseconds();
        arr=createArray(n);
        long start_time_sel=getTimeinMicroseconds();
        selectionSort(arr,n);
        long end_time_sel=getTimeinMicroseconds();
        cout<<left<<setw(10)<<n<<left<<setw(15)<<(end_time_merge-start_time_merge)<<left<<setw(20)<<(end_time_sel-start_time_sel)<<"\n";
    }

}