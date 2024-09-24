#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string str = "";
    while (cin >> str)
    {
        vector<int> list;
        string::iterator iter = str.begin();
        while (iter != str.end())
        {
            if (*iter == '+')
            {
                int tmp = list[list.size() - 2] + list[list.size() - 1];
                list[list.size() - 2] = tmp;
                list.pop_back();
            }
            if (*iter == '-')
            {
                int tmp = list[list.size() - 2] - list[list.size() - 1];
                list[list.size() - 2] = tmp;
                list.pop_back();
            }
            if (*iter == '*')
            {
                int tmp = list[list.size() - 2] * list[list.size() - 1];
                list[list.size() - 2] = tmp;
                list.pop_back();
            }
            if (*iter == '/')
            {
                int tmp = list[list.size() - 2] / list[list.size() - 1];
                list[list.size() - 2] = tmp;
                list.pop_back();
            }
            if (0 <= *iter - '0' && *iter - '0' <= 9)
            {
                list.push_back(*iter - '0');
            }
            ++iter;
        }
        cout << list[0] << endl;
    }
    return 0;
}