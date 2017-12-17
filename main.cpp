#include <iostream>
#include "ZFraction.h"
#include "overload.h"

using namespace std;

int main()
{
    ZFraction a(160,200);      //Déclare une fraction valant 4/5
    ZFraction b(2);        //Déclare une fraction valant 2/1 (ce qui vaut 2)
    ZFraction c,d,e,f;         //Déclare deux fractions valant 0

    c = a+b;               //Calcule 4/5 + 2/1 = 14/5
    e = b-a;
    f = a-b;
    d = a*b;               //Calcule 4/5 * 2/1 = 8/5

    cout << a << " + " << b << " = " << c << endl;
    cout << b << " - " << a << " = " << e << endl;
    cout << a << " - " << b << " = " << f << endl;
    cout << e << " + " << f << " = " << e + f << endl;

    cout << a << " * " << b << " = " << d << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    cout << a << " / " << e << " = " << a / e << endl;

    if(c > a)
        cout << c << " est plus grand que " << a << endl;
    else if(c==a)
        cout << c << " est egal a " << a << endl;
    else
        cout << c << " est plus petit que " << a << endl;

    return 0;
}
