#include <iostream>
using namespace std;

void find_the_way();

int h = 0, w = 0;
bool map[10][5000][2] = {0};

int main()
{
    cin >> h >> w;
    map[0][0][1] = true;
    char tmp = ' ';
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> tmp;
            if (tmp == '.')
            {
                map[i][j][0] = true;
            }
        }
    }
    find_the_way();
    if (map[h - 1][w - 1][1])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
void find_the_way()
{
    for (int j = 0; j < w; ++j)
    {
        for (int i = 0; i < h; ++i)
        {
            bool is_reachable = false;
            if (j != 0)
            {
                if (i != 0)
                {
                    is_reachable |= map[i - 1][j - 1][1];
                }
                is_reachable |= map[i][j - 1][1];
                if (i != h - 1)
                {
                    is_reachable |= map[i + 1][j - 1][1];
                }
                is_reachable &= map[i][j][0];
                map[i][j][1] = is_reachable;
            }
        }
    }
    return;
}