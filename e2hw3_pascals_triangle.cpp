#include <iostream>
using namespace std;
unsigned long long C(int r, int c);
unsigned long long table[65][65]={0};
int main()
{
    int r=0,c=0;
    while(cin>>r)
    {
        cin>>c;
        if(table[r][c]==0)
        {
            table[r][c]=C(r,c);
            table[r][r-c]=table[r][c];
        }
        cout<<table[r][c]<<endl;
    }
    return 0;
}
unsigned long long C(int r, int c) {
    if(c>r-c)
    {
        int tmp=r-c;
        c=tmp;
    }
    if (c == 0)
    {
        table[r][c]=1;
        return 1;
    }
    if (c == 1)
    {
        table[r][c]=r;
        return r;
    }
    if(table[r - 1][c - 1]==0)
    {
        table[r - 1][c - 1]=C(r - 1, c - 1);
        table[r-1][r-c]=table[r - 1][c - 1];
    }
    if(table[r - 1][c]==0)
    {
        table[r - 1][c]=C(r - 1, c);
        table[r-1][r-c-1]=table[r - 1][c];
    }
    return table[r - 1][c - 1] + table[r - 1][c];
}