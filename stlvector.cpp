#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int>v(5);

    for(int i=0;i<v.size();i++)
        v[i]=i+1;

    vector <int>::iterator it;
    for(it=v.begin();it!=v.end();it++)
        cout<<*it<<endl;

    vector <int>v1;

    for(int i=0;i<5;i++)
        v1.push_back(i*2);
    
    for(it=v1.begin();it!=v1.end();it++)
        cout<<*it<<endl;
    
    return 0;
}