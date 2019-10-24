#include<iostream>
#include<algorithm>
using namespace std;
struct student{
    string name;
    int m1,m2,m3;
    int total,pos;
};
bool compare(student a,student b)
{  
        return(a.total>b.total);
}
int main()
{
    int t;
    cin>>t;
    int ot=t;
    struct student s[t];
    int i=0;
    while(t--)
    {    s[i].pos=i;
        cin>>s[i].name>>s[i].m1>>s[i].m2>>s[i].m3;
        s[i].total=(s[i].m1+s[i].m2+s[i].m3);
    }
    sort(s,s+ot,compare);
    for(int i=0;i<ot;i++)
    {
        cout<<s[i].name<<endl;
    }
    for(int i=0;i<ot;i++)
    {
        cout<<i+1<<" "<<s[i].name<<endl;
    }
    return 0;
}


