#include <iostream>
using namespace std;
int main()
{
    unsigned int size_of_memory_card = 128 * 1024 * 1024; // 128EB
    unsigned int size_of_data = 0; cin >> size_of_data;   // TB
    cout << size_of_memory_card / size_of_data << endl;
    return 0;
}