#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double deg = 0.0;
    cin >> deg;
    double PI = std::acos(-1.0); // get PI = 3.14159265358979323846...
    double ans = (deg * PI) / 180;
    cout <<fixed<< setprecision(8) << ans << endl;
    return 0;
}