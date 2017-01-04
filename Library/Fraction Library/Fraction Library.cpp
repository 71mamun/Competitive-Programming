#include<bits/stdc++.h>

using namespace std;

int _lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}

struct Fraction
{
    int num,dnm,gcd;

    void normalize()
    {
        // numerator and denominator must be co-prime.
        gcd = __gcd(num,dnm);
        num/=gcd;dnm/=gcd;
        // negative sing is always with numerator.
        num = (num*dnm<0?-num:num);
        dnm = (dnm<0?-dnm:dnm);
    }

    Fraction (int a,int b)
    {
        num = a,dnm = b;
        normalize();
    }

    void operator=(const Fraction  &other)
    {
        num = other.num;
        dnm = other.dnm;
        normalize();
    }

    bool operator<(Fraction  other) const
    {
        int lcm = _lcm(dnm,other.dnm);
        return (lcm/dnm)*num < (lcm/other.dnm)*other.num;
//        return num*other.dnm < dnm*other.num;// skip to reduce overflow.
    }

    bool operator>(Fraction  other) const
    {
        int lcm = _lcm(dnm,other.dnm);
        return (lcm/dnm)*num > (lcm/other.dnm)*other.num;
    }

    bool operator==(Fraction  other) const
    {
        int lcm = _lcm(dnm,other.dnm);
        return (lcm/dnm)*num == (lcm/other.dnm)*other.num;
    }

    bool operator!=(Fraction  other) const
    {
        int lcm = _lcm(dnm,other.dnm);
        return (lcm/dnm)*num != (lcm/other.dnm)*other.num;
    }

    bool operator>=(Fraction  other) const
    {
        int lcm = _lcm(dnm,other.dnm);
        return (lcm/dnm)*num >= (lcm/other.dnm)*other.num;
    }

    bool operator<=(Fraction  other) const
    {
        int lcm = _lcm(dnm,other.dnm);
        return (lcm/dnm)*num <= (lcm/other.dnm)*other.num;
    }

    Fraction operator+(Fraction  other) const
    {
        int lcm = _lcm(dnm,other.dnm);
        return Fraction((lcm/dnm)*num + (lcm/other.dnm)*other.num,lcm);
    }

    Fraction operator-(Fraction  other) const
    {
        int lcm = _lcm(dnm,other.dnm);
        return Fraction((lcm/dnm)*num - (lcm/other.dnm)*other.num,lcm);
    }

    Fraction operator*(Fraction  other) const
    {
        return Fraction(num*other.num,dnm*other.dnm);
    }

    Fraction operator/(Fraction  other) const
    {
        return Fraction(num*other.dnm,dnm*other.num);
    }

    Fraction operator- ()
    {
        return Fraction(-num,dnm);
    }

    string to_string()
    {
        ostringstream oss;
        oss<<num<<"/"<<dnm;
        oss.flush();
        return oss.str();
    }

    double to_double()
    {
        return double(num)/double(dnm);
    }

};

int main()
{
    cout<<(Fraction(1,2)==Fraction(5,10))<<endl;
    return 0;
}
