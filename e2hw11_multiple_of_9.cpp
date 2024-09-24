#include<iostream>
#include<vector>
using namespace std;
void dfs(unsigned long long arg_m);
int main()
{
    unsigned long long m=0;
    cin>>m;
    dfs(m);
    return 0;
}
void dfs(unsigned long long arg_m)
{
    cout<<arg_m<<endl;
    if(arg_m==0||arg_m==9)
    {
        cout<<"yes"<<endl;
        return;
    }
    if(arg_m<9)
    {
        cout<<"no"<<endl;
        return;
    }
    unsigned long long tmp=0;
    while(arg_m)
    {
        tmp+=arg_m%10;
        arg_m/=10;
    }
    dfs(tmp);
    return;
}