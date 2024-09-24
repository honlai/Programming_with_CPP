#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int tree_h = 0;
    cin >> tree_h;
    for (int i = 0; i < tree_h; ++i)
    {
        cout << setfill('.') << setw(i) << ""
             << setfill('@') << setw((tree_h - i)) << "" 
             << setfill('@') << setw((tree_h - i-1)) << "" 
             << setfill('.') << setw(i) << ""
             << endl;
    }
    return 0;
}
