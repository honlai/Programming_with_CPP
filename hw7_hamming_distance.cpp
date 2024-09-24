#include <iostream>
using namespace std;
unsigned int hamming_distance(unsigned long long int arg_a, unsigned long long int arg_b);
int main()
{
    unsigned long long int a = 0, b = 0;
    cin >> a >> b;
    cout << hamming_distance(a, b) << endl;
    return 0;
}
unsigned int hamming_distance(unsigned long long int arg_a, unsigned long long int arg_b)
{
    unsigned long long int XOR=arg_a^arg_b;
    unsigned int dist = 0;
    while (XOR)
    {
        dist+=(XOR & 1);

        XOR >>= 1;
        //dist+=((XOR>>1)&1);
    }
    return dist;

}