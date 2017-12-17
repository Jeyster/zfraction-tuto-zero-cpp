#ifndef ZFRACTION_H
#define ZFRACTION_H

#include <iostream>

class ZFraction
{
    public:
        ZFraction(int numerator = 0, int denominator = 1);
        void display(std::ostream &flux) const;
        ZFraction& operator+=(ZFraction const& fraction);
        ZFraction& operator-=(ZFraction const& fraction);
        ZFraction& operator*=(ZFraction const& fraction);
        ZFraction& operator/=(ZFraction const& fraction);
        bool isSmallerThan(ZFraction const& fraction) const;
        bool isEqual(ZFraction const& fraction) const;
        void reduct();

    private:
        int m_numerator;
        int m_denominator;
};

int highestCommonDenominator(int a, int b);

#endif // ZFRACTION_H



