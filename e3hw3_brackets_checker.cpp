#include <iostream>
using namespace std;
int main()
{
    char c[10000] = {0};
    char tmp = ' ';
    int index = 0;
    bool is_valid = true;
    while (cin >> tmp)
    {
        if (!is_valid)
        {
            continue;
        }
        if (tmp == ')')
        {
            if (index == 0)
            {
                is_valid = false;
                continue;
            }
            if (c[index - 1] == '(')
            {
                --index;
            }
            else
            {
                is_valid = false;
            }
            continue;
        }
        if (tmp == ']')
        {
            if (index == 0)
            {
                is_valid = false;
                continue;
            }
            if (c[index - 1] == '[')
            {
                --index;
            }
            else
            {
                is_valid = false;
            }
            continue;
        }
        c[index] = tmp;
        ++index;
    }
    if(is_valid)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    return 0;
}