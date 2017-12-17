#include <ostream>
#include "ZFraction.h"

using namespace std;

ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie += b;
    return copie;
}

ZFraction operator-(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie -= b;
    return copie;
}

ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie *= b;
    return copie;
}

ZFraction operator/(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie /= b;
    return copie;
}

bool operator==(ZFraction const& a, ZFraction const& b)
{
    return a.isEqual(b);
}

bool operator!=(ZFraction const& a, ZFraction const& b)
{
    return !(a==b);
}

bool operator<(ZFraction const& a, ZFraction const& b)
{
    return a.isSmallerThan(b);
}

bool operator>(ZFraction const& a, ZFraction const& b)
{
    return (!(a<b) || (a==b));
}

bool operator<=(ZFraction const& a, ZFraction const& b)
{
    return !(a>b);
}

bool operator>=(ZFraction const& a, ZFraction const& b)
{
    return !(a<b);
}

ostream& operator<<(ostream &flux, ZFraction const& fraction)
{
    fraction.display(flux);
    return flux;
}

int pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}
