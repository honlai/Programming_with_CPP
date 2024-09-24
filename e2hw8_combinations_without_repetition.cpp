#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int> tmp_list, int arg_k);
void print();

vector<int> list;
int list_len = 0;
vector<vector<int>> ans;

int main()
{
    int n = 0;
    cin >> n;
    list_len = n;
    while (n--)
    {
        int tmp = 0;
        cin >> tmp;
        list.push_back(tmp);
    }
    sort(list.begin(), list.end());
    dfs(list, 0);
    print();
    return 0;
}
void dfs(vector<int> tmp_list, int arg_k)
{
    if (arg_k == list_len - 1)
    {
        ans.push_back(tmp_list);
        return;
    }
    for (int i = arg_k; i < list_len; ++i)
    {
        if (arg_k == i || tmp_list[arg_k] != tmp_list[i])
        {
            swap(tmp_list[arg_k], tmp_list[i]);
            dfs(tmp_list, arg_k + 1);
        }
    }
    return;
}
void print()
{
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < list_len - 1; ++j)
        {
            cout << ans[i][j] << ' ';
        }
        cout << ans[i][list_len - 1] << endl;
    }
    return;
}