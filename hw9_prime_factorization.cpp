#include <iostream>
using namespace std;
int main()
{
    unsigned int N=0;
    cin>>N;
    cout<<N<<'='<<flush;
    unsigned int temp=N;
    unsigned int d = 2;
    unsigned int count = 0;
    while(temp!=1 && ((long long)d*d)<N)
    {
        if((temp%d)==0)
        {
            temp/=d;
            ++count;
            if((temp%d)!=0||temp==1)
            {
                cout<<d<<flush;
                if(count!=1)
                {
                    cout<<'^'<<count<<flush;
                }
                if(temp!=1)
                {
                    cout<<'x'<<flush;
                }
            }
        }
        else
        {
            ++d;
            count=0;
        }
    }
    if(temp!=1)
    {
        cout<<N<<flush;
    }
    return 0;
}