#include <iostream>
#include <math.h>
#include "ZFraction.h"
#include "overload.h"

using namespace std;

ZFraction::ZFraction(int numerator, int denominator)
: m_numerator(numerator), m_denominator(denominator)
{
    reduct();
}

void ZFraction::display(ostream &flux) const
{
    if (m_numerator == 0)
    {
        flux << 0;
    }
    else if (m_denominator == 1)
    {
        flux << m_numerator;
    }
    else
    {
        flux << m_numerator << "/" << m_denominator;
    }
}

ZFraction& ZFraction::operator+=(ZFraction const& fraction)
{
    m_numerator = (m_numerator * fraction.m_denominator) + (fraction.m_numerator * m_denominator);
    m_denominator = m_denominator * fraction.m_denominator;

    reduct();

    return *this;
}

ZFraction& ZFraction::operator-=(ZFraction const& fraction)
{
    m_numerator = (m_numerator * fraction.m_denominator) - (fraction.m_numerator * m_denominator);
    m_denominator = m_denominator * fraction.m_denominator;

    reduct();

    return *this;
}

ZFraction& ZFraction::operator*=(ZFraction const& fraction)
{
    m_numerator *= fraction.m_numerator;
    m_denominator *= fraction.m_denominator;

    reduct();

    return *this;
}

ZFraction& ZFraction::operator/=(ZFraction const& fraction)
{
    m_numerator = m_numerator * fraction.m_denominator;
    m_denominator = m_denominator * fraction.m_numerator;

    reduct();

    return *this;
}

bool ZFraction::isSmallerThan(ZFraction const& fraction) const
{
    double thisNumerator(m_numerator), thisDenominator(m_denominator), numerator(fraction.m_numerator), denominator(fraction.m_denominator);

    return (thisNumerator/thisDenominator) < (numerator/denominator);
}

bool ZFraction::isEqual(ZFraction const& fraction) const
{
    double thisNumerator(m_numerator), thisDenominator(m_denominator), numerator(fraction.m_numerator), denominator(fraction.m_denominator);

    return (thisNumerator/thisDenominator) == (numerator/denominator);
}

int highestCommonDenominator(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return fabs(a);
}

void ZFraction::reduct()
{
    int hcd = highestCommonDenominator(m_numerator, m_denominator);
    m_numerator /= hcd;
    m_denominator /= hcd;
}
