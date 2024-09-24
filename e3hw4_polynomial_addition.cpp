#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Polynomial
{
    vector<pair<int, int>> list;
    int len;
    void construct();
    void print();
};

Polynomial add(const Polynomial &arg_a, const Polynomial &arg_b);
int main()
{
    Polynomial p1;
    p1.construct();
    Polynomial p2;
    p2.construct();
    Polynomial ans = add(p1, p2);
    ans.print();
    return 0;
}
void Polynomial::construct()
{
    cin >> len;
    pair<int, int> tmp;
    int zero_cnt = 0;
    for (int i = 0; i < len; ++i)
    {
        cin >> tmp.second;
        cin >> tmp.first;
        if (tmp.second != 0)
        {
            list.push_back(tmp);
        }
        else
        {
            ++zero_cnt;
        }
    }
    len-=zero_cnt;
    sort(list.begin(), list.end());
    return;
}
void Polynomial::print()
{
    for (int i = len - 1; i >= 0; --i)
    {
        if (list[i].first != 0)
        {
            if (list[i].second != 1)
            {
                cout << list[i].second;
            }
            cout << 'x';
            if (list[i].first != 1)
            {
                cout << '^' << list[i].first;
            }
        }
        else
        {
            cout << list[i].second;
        }
        if (i != 0)
        {
            cout << '+' << flush;
        }
    }
    if (len == 0)
    {
        cout << 0 << flush;
    }
    cout << endl;
    return;
}
Polynomial add(const Polynomial &arg_a, const Polynomial &arg_b)
{
    Polynomial tmp;
    int i = 0;
    int j = 0;
    while (i < arg_a.len || j < arg_b.len)
    {
        if (i >= arg_a.len)
        {
            while (j < arg_b.len)
            {
                tmp.list.push_back(arg_b.list[j]);
                ++tmp.len;
                ++j;
            }
            break;
        }
        if (j >= arg_b.len)
        {
            while (i < arg_a.len)
            {
                tmp.list.push_back(arg_a.list[i]);
                ++tmp.len;
                ++i;
            }
            break;
        }
        if (arg_a.list[i].first == arg_b.list[j].first)
        {
            if (arg_a.list[i].second + arg_b.list[j].second != 0)
            {
                pair<int, int> p;
                p.second = arg_a.list[i].second + arg_b.list[j].second;
                p.first = arg_a.list[i].first;
                tmp.list.push_back(p);
                ++tmp.len;
            }
            ++i;
            ++j;
        }
        else
        {
            if (arg_a.list[i].first < arg_b.list[j].first)
            {
                tmp.list.push_back(arg_a.list[i]);
                ++tmp.len;
                ++i;
            }
            else
            {
                tmp.list.push_back(arg_b.list[j]);
                ++tmp.len;
                ++j;
            }
        }
    }
    sort(tmp.list.begin(), tmp.list.end());
    return tmp;
}