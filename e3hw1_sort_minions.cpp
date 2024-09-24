#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Minion
{
    string name = "";
    int height = 0;
    int hair_cnt = 0;
    int age = 0;
    int eyes_cnt = 0;
};
bool cmp(Minion &arg_a, Minion &arg_b);
int main()
{
    int minion_cnt = 0;
    cin >> minion_cnt;
    vector<Minion> list;
    int n=minion_cnt;
    while (n--)
    {
        Minion tmp;
        cin >> tmp.name >> tmp.height >> tmp.hair_cnt >> tmp.age >> tmp.eyes_cnt;
        list.push_back(tmp);
    }
    sort(list.begin(),list.end(),cmp);
    for(int i=0;i<minion_cnt;++i)
    {
        cout<<list[i].name<<endl;
    }
    return 0;
}
bool cmp(Minion &arg_a, Minion &arg_b)
{
    if (arg_a.height == arg_b.height)
    {
        if (arg_a.hair_cnt == arg_b.hair_cnt)
        {
            if (arg_a.age == arg_b.age)
            {
                if (arg_a.eyes_cnt == arg_b.eyes_cnt)
                {
                    return arg_a.name < arg_b.name;
                }
                return arg_a.eyes_cnt > arg_b.eyes_cnt;
            }
            return arg_a.age < arg_b.age;
        }
        return arg_a.hair_cnt > arg_b.hair_cnt;
    }
    return arg_a.height < arg_b.height;
}