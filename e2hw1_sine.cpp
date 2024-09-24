#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;
int main() 
{ 
  cout << fixed << setprecision(8); 
  double PI = acos(-1.0); // get PI
  double x=0;
  cin>>x;
  cout<<sin(x*(PI/180))<<endl;
  return 0;
}