#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Cat
{
    string name;
    string identity;
    int id;
    int age;
    int order;
    Cat()
    {
        name = "";
        identity = "";
        id = 0;
        age = 0;
        order = 48763;
    }
    void set_id_order()
    {
        id = (int)identity[0];
        switch (id)
        {
        case 101:
            order = 0;
            break;
        case 110:
            order = 1;
            break;
        case 107:
            order = 2;
            break;
        case 119:
            order = 3;
            break;
        case 97:
            order = 4;
            break;
        case 109:
            order = 5;
            break;
        case 100:
            order = 6;
            break;
        case 108:
            order = 7;
            break;
        }
        return;
        /*101:elder, 110:nursy, 107:kit, 119:warrior, 97:apprentice, 109:medicent, 100:deputy, 108:leader*/
    }
};
bool cmp(Cat &arg_a, Cat &arg_b);
int main()
{
    int cat_cnt = 0, food_cnt = 0;
    cin >> cat_cnt >> food_cnt;
    vector<Cat> list;
    while (cat_cnt--)
    {
        Cat tmp;
        cin >> tmp.name >> tmp.identity >> tmp.age;
        tmp.set_id_order();
        list.push_back(tmp);
    }
    sort(list.begin(), list.end(), cmp);
    int m = (food_cnt < list.size()) ? food_cnt : list.size();
    for (int i = 0; i < m; ++i)
    {
        cout << list[i].name << endl;
    }
    return 0;
}
bool cmp(Cat &arg_a, Cat &arg_b)
{
    if (arg_a.order == arg_b.order)
    {
        if (arg_a.age == arg_b.age)
        {
            return arg_a.name < arg_b.name;
        }
        if (arg_a.order == 4)
        {
            return arg_a.age < arg_b.age;
        }
        return arg_a.age > arg_b.age;
    }
    return arg_a.order < arg_b.order;
}