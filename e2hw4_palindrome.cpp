#include<iostream>
using namespace std;
int main()
{
    string s="";
    while(cin>>s)
    {
        bool is_palindrome=true;
        int len=s.length();
        char *forward=&s[0];
        char *back=&s[len-1];
        int i=len/2;
        while(i--)
        {
            if((int)*forward!=(int)*back)
            {
                is_palindrome=false;
                break;
            }
            else
            {
                ++forward;
                --back;
            }
        }
        if(is_palindrome)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }

    }
    
    return 0;
}
