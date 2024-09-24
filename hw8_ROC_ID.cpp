#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int two_digit=0;
    vector<int> id(9,0);
    while(cin>>two_digit)
    {
        int n1=two_digit/10;
        int n2=two_digit%10;
        for(int i=1;i<=8;++i)
        {
            cin>>id[i];
        }
        int S=n1*1+n2*9+id[1]*8+id[2]*7+id[3]*6+id[4]*5+id[5]*4+id[6]*3+id[7]*2+id[8]*1;
        int check=(((S%10)!=0)?10-(S%10):0);
        cout<<two_digit<<'-'<<flush;
        for(int i=1;i<=8;++i)
        {
            cout<<id[i];
        }
        cout<<check<<endl;
    }
    return 0;
}