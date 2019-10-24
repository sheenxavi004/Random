
#include <iostream>
using namespace std;
void Rotate(int arr[], int d, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
    int temp;
    while(d--)
    {
        temp=arr[0];
        for(int i=0;i<size-1;i++)
        {
            
            arr[i]=arr[i+1];
        }
        arr[size-1]=temp;
    }
}	

int main() {

	int size;
	int d;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin >> d;
    
    Rotate(input,d,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;

}

