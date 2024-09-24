#include <iostream>
using namespace std;
class Fraction
{
    private: 
        int _numerator = 0;
        int _denominator = 1;
    public:
        //constructor
        Fraction(const int& arg_numerator = 0,const int& arg_denominator = 1):_numerator(arg_numerator),_denominator(arg_denominator){};
        int get_numerator(){return _numerator;};
        int get_denominator(){return _denominator;};
        void set_numerator(int& arg_numerator){_numerator=arg_numerator;};
        void set_denominator(int& arg_denominator){_denominator=arg_denominator;};
        void reduction();
        ~Fraction(){};
};
int get_gcd(int a,int b);
Fraction sum_of_two_fractions(Fraction& arg_p,Fraction& arg_q);
int main()
{
    int numerator = 0, denominator = 1;
    Fraction ans(0,1);
    int num_of_fractions=2;
    while(num_of_fractions--)
    {
        cin>>numerator>>denominator;
        Fraction p(numerator,denominator);
        p.reduction();
        ans=sum_of_two_fractions(p,ans);
    }
    cout<<ans.get_numerator()<<'/'<<ans.get_denominator()<<endl;
    return 0;
}
// Use Euclidean algorithm to get the gcd
int get_gcd(int a,int b)
{
    while( a%b!=0 && b%a!=0)
    {
        (a<b)?b%=a:a%=b;
    }
    return (a<b)?a:b;
}
void Fraction::reduction()
{
    int gcd=get_gcd(_numerator,_denominator);
    _numerator/=gcd;
    _denominator/=gcd;
}
Fraction sum_of_two_fractions(Fraction& arg_p,Fraction& arg_q)
{
    Fraction r((arg_p.get_numerator()*arg_q.get_denominator())+(arg_q.get_numerator()*arg_p.get_denominator()),arg_p.get_denominator()*arg_q.get_denominator());
    r.reduction();
    return r;
}