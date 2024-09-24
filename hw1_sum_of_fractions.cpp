#include <iostream>
using namespace std;
class Fraction
{
    private: 
        unsigned long long int _numerator = 0;
        unsigned long long int _denominator = 1;
    public:
        //constructor
        Fraction(const unsigned long long int& arg_numerator = 0,const unsigned long long int& arg_denominator = 1):_numerator(arg_numerator),_denominator(arg_denominator){};
        unsigned long long int get_numerator(){return _numerator;};
        unsigned long long int get_denominator(){return _denominator;};
        void set_numerator(unsigned long long int& arg_numerator){_numerator=arg_numerator;};
        void set_denominator(unsigned long long int& arg_denominator){_denominator=arg_denominator;};
        void reduction();
        ~Fraction(){};
};
unsigned long long int get_gcd(unsigned long long int a,unsigned long long int b);
Fraction sum_of_two_fractions(Fraction& arg_p,Fraction& arg_q);
int main()
{
    unsigned long long int numerator = 0, denominator = 1;
    Fraction ans(0,1);
    int num_of_fractions=0;//Unknown
    char c=' ';
    while(cin>>numerator)//Unknown how many fractions to enter
    {
        cin>>denominator;
        Fraction p(numerator,denominator);
        p.reduction();
        ans=sum_of_two_fractions(p,ans);
    }
    cout<<ans.get_numerator()<<'/'<<ans.get_denominator()<<endl;
    return 0;
}
// Use Euclidean algorithm to get the gcd
unsigned long long int get_gcd(unsigned long long int a,unsigned long long int b)
{
    while( a%b!=0 && b%a!=0)
    {
        (a<b)?b%=a:a%=b;
    }
    return (a<b)?a:b;
}
void Fraction::reduction()
{
    unsigned long long int gcd=get_gcd(_numerator,_denominator);
    _numerator/=gcd;
    _denominator/=gcd;
}
Fraction sum_of_two_fractions(Fraction& arg_p,Fraction& arg_q)
{
    unsigned long long int gcd=get_gcd(arg_p.get_denominator(),arg_q.get_denominator());
    Fraction r((arg_p.get_numerator()*(arg_q.get_denominator()/gcd))+(arg_q.get_numerator()*(arg_p.get_denominator()/gcd)),(arg_p.get_denominator()/gcd)*arg_q.get_denominator());
    r.reduction();
    return r;
}