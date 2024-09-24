#include <iostream>
#include <vector>
using namespace std;

void get_uni_inter();
void print_uni_inter();

vector<int> list1;
vector<int> list2;
vector<int> uni;
vector<int> intersection;

int main()
{
    int list1_len = 0, list2_len = 0;

    /*input L1*/
    cin >> list1_len;
    while (list1_len--)
    {
        int tmp = 0;
        cin >> tmp;
        list1.push_back(tmp);
    }

    /*input L2*/
    cin >> list2_len;
    while (list2_len--)
    {
        int tmp = 0;
        cin >> tmp;
        list2.push_back(tmp);
    }

    get_uni_inter();
    print_uni_inter();
    return 0;
}
void get_uni_inter()
{
    int i = 0;
    int j = 0;
    while (i < list1.size() || j < list2.size())
    {
        if (i == list1.size())
        {
            while (j < list2.size())
            {
                uni.push_back(list2[j]);
                ++j;
            }
            continue;
        }
        if (j == list2.size())
        {
            while (i < list1.size())
            {
                uni.push_back(list1[i]);
                ++i;
            }
            continue;
        }
        if (list1[i] == list2[j])
        {
            uni.push_back(list1[i]);
            intersection.push_back(list1[i]);
            ++i;
            ++j;
            continue;
        }
        if (list1[i] < list2[j])
        {
            uni.push_back(list1[i]);
            ++i;
            continue;
        }
        if (list1[i] > list2[j])
        {
            uni.push_back(list2[j]);
            ++j;
            continue;
        }
    }
    return;
}
void print_uni_inter()
{
    cout << "union: " << flush;
    if (!uni.empty())
    {
        for (size_t i = 0; i < uni.size() - 1; ++i)
        {
            cout << uni[i] << ' ' << flush;
        }
        cout << uni[uni.size() - 1] << endl;
    }
    cout << "intersection: " << flush;
    if (!intersection.empty())
    {
        for (size_t i = 0; i < intersection.size() - 1; ++i)
        {
            cout << intersection[i] << ' ' << flush;
        }
        cout << intersection[intersection.size() - 1] << endl;
    }
    else
    {
        cout << endl;
    }

    return;
}