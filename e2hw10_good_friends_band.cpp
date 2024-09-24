#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0;
bool board[45][45] = {0};
vector<pair<int, int>> fri_cnt; /*{cnt,idx}*/
vector<int> max_complete_graph;
int max_size = 0;
bool visited[45] = {0};

void set_board();
void find_max_complete_graph(vector<pair<int, int>> &arg_fri_cnt);

int main()
{
    set_board();
    for (int i = fri_cnt.size() - 1; i >= 0; --i)
    {
        visited[fri_cnt[i].second] = true;
        find_max_complete_graph(fri_cnt);
        fri_cnt.pop_back();
    cout << endl;
    }
    cout << max_size << endl;
    return 0;
}
void set_board()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        fri_cnt.push_back({0, i});
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
            if (board[i][j])
            {
                ++fri_cnt[i].first;
            }
        }
        cout<<i<<" has "<<fri_cnt[i].first<<" fri_cnt"<<endl;
    }
    sort(fri_cnt.begin(), fri_cnt.end());
    return;
}
void find_max_complete_graph(vector<pair<int, int>> &arg_fri_cnt)
{
    int max_fri_cnt_idx = arg_fri_cnt[arg_fri_cnt.size() - 1].second;
                cout << "idx: "<<max_fri_cnt_idx << ' ' << flush;
    max_complete_graph.push_back(max_fri_cnt_idx);
    if (max_size < max_complete_graph.size())
    {
        max_size = max_complete_graph.size();
    }
    vector<pair<int, int>> tmp_fri_cnt; /*{cnt,idx}*/
    for (int i = 0; i < n; ++i)
    {
        if (board[max_fri_cnt_idx][i] && !visited[i] && i != max_fri_cnt_idx)
        {
            bool is_fri = true;
            for (auto j : max_complete_graph)
            {
                is_fri &= board[i][j];
            }
            if (is_fri&&arg_fri_cnt[i].first - 1>0)
            {
                tmp_fri_cnt.push_back({arg_fri_cnt[i].first - 1, i});
                cout << "tmp_fri_cnt: "<<arg_fri_cnt[i].first - 1<<'-'<< i << ' ' << flush;
            }
        }
    }
    if (!tmp_fri_cnt.empty())
    {
        sort(tmp_fri_cnt.begin(), tmp_fri_cnt.end());
        for (int i = tmp_fri_cnt.size() - 1; i >= 0; --i)
        {
            visited[tmp_fri_cnt[i].second] = true;
            find_max_complete_graph(tmp_fri_cnt);
            tmp_fri_cnt.pop_back();
            visited[tmp_fri_cnt[i].second] = false;
        }
    }
    if (!max_complete_graph.empty())
    {
        max_complete_graph.pop_back();
    }
    return;
}
