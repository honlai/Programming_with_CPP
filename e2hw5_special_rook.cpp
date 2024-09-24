#include <iostream>
using namespace std;
void add_rook(int &x, int &y);
void remove_rook(int &x, int &y);
bool is_valid_special_rook_position(int &x, int &y);
void dfs(int arg_k,int &arg_n);
int cnt = 1;
int max_n = 0;
int board_x[6] = {0};
int board_y[6] = {0};
bool visited[6][6] = {0};
int main()
{
    cin >> max_n;
    int k = 0;
    cin >> k;
    while (k--)
    {
        int x = 0;
        cin >> x;
        ++board_x[x];
        int y = 0;
        cin >> y;
        ++board_y[y];
        visited[x][y]=true;
    }
    dfs(0,max_n);
    cout << cnt << endl;
    return 0;
}
void add_rook(int &x, int &y)
{
    ++cnt;
    ++board_x[x];
    ++board_y[y];
    visited[x][y]=true;
    return;
}
void remove_rook(int &x, int &y)
{
    --board_x[x];
    --board_y[y];
    visited[x][y]=false;
    return;
}
bool is_valid_special_rook_position(int &x, int &y)
{
    if (board_x[x] < 2 && board_y[y] < 2 && (!visited[x][y]))
    {
        return true;
    }
    return false;
}
void dfs(int arg_k,int &arg_n)
{
    for (int k = arg_k; k < arg_n*arg_n; ++k)
    {
        int x=k/arg_n;
        int y=k%arg_n;
        if (is_valid_special_rook_position(x,y))
        {
            add_rook(x, y);
            dfs(k,arg_n);
            remove_rook(x, y);
        }
    }
    return;
}