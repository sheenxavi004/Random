#include<iostream>
#include<utility>
using namespace std;

int main()
{
    pair <int,char> p(1,'a');
    pair <int,char> p1;
    p1=make_pair(2,'b');
    cout<<p.first<<" "<<p.second<<endl;
    cout<<p1.first<<" "<<p1.second<<endl;
    return 0;
}