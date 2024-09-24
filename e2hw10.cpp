#include <iostream>
using namespace std;

int n = 0;
bool board[45][45] = {0};
int fri_cnt[45] = {0};
bool visited[45] = {0};
int visited_cnt = 0;
bool ans[45] = {0};
int ans_cnt = 0;
int max_ans_cnt = 0;

void find_max_fri_index(int &arg_k);
int main()
{
    cin >> n;
    bool is_fri = 0;
    int max_fri_index = 0;
    int sec_max_fri_index = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> is_fri;
            if (is_fri)
            {
                board[i][j] = true;
                ++fri_cnt[i];
                if (fri_cnt[max_fri_index] < fri_cnt[i])
                {
                    max_fri_index = i;
                }
            }
        }
    }
    while(visited_cnt!=n)
    {
        int tmp=-1;
        find_max_fri_index(tmp);
        if (max_ans_cnt < ans_cnt)
        {
            max_ans_cnt = ans_cnt;
        }
        ans_cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            ans[i] = false;
        }
    }
    cout << max_ans_cnt << endl;
    return 0;
}
void find_max_fri_index(int &arg_k)
{
    int max_fri_index = -1;
    if (arg_k != -1)
    {
        for (int i = 0; i < n; ++i)
        {
            if (!ans[i] && board[arg_k][i] && fri_cnt[max_fri_index] < fri_cnt[i])
            {
                bool has_ans_fri = true;
                for (int j = 0; j < n; ++j)
                {
                    if (ans[j])
                    {
                        has_ans_fri &= board[i][j];
                    }
                }
                if (has_ans_fri)
                {
                    max_fri_index = i;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i] && fri_cnt[max_fri_index] < fri_cnt[i])
            {
                max_fri_index = i;
            }
        }
        visited[max_fri_index]=true;
        ++visited_cnt;
        if(fri_cnt[max_fri_index]<max_ans_cnt)
        {
            return;
        }
    }
    if (max_fri_index != -1)
    {
        ans[max_fri_index] = true;
        ++ans_cnt;
        find_max_fri_index(max_fri_index);
    }
    return;
}