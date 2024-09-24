#include <iostream>
using namespace std;
int main()
{
    int hour = 0; cin >> hour;
    int minute = 0; cin >> minute;
    int add_minutes = 0; cin >> add_minutes;
    minute += add_minutes; 
    hour += (minute / 60);
    minute %= 60; 
    hour %= 24; 
    cout << hour << ' ' << minute << endl;
    return 0;
}