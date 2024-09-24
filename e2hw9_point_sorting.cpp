#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    int x=0;
    int y=0;
};
bool cmp(point &p1,point &p2);
int main()
{
    vector<point> list;
    int n=0;cin>>n;
    int tmp=n;
    while (tmp--)
    {
        point p;
        cin>>p.x;
        cin>>p.y;
        list.push_back(p);
    }
    sort(list.begin(),list.end(),cmp);
    for (int i=0;i<n;++i)
    {
        cout<<list[i].x<<' '<<list[i].y<<endl;
    }
    return 0;
}
bool cmp(point &p1,point &p2)
{
    long long dist_A=p1.x*p1.x+p1.y*p1.y;
    long long dist_B=p2.x*p2.x+p2.y*p2.y;
    if(dist_A-dist_B)
    {
        return dist_A<dist_B;
    }
    else
    {
        if(p1.x-p2.x)
        {
            return p1.x<p2.x;
        }
        else
        {
            return p1.y<p2.y;
        }
    }
}