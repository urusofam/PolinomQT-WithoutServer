#ifndef PRAKTIKA2_COMPLEX_H
#define PRAKTIKA2_COMPLEX_H

#include <iostream>

using namespace std;

class Tcomplex {
    double re, im;
public:
    Tcomplex();
    Tcomplex(double);
    Tcomplex(double, double);

    Tcomplex operator / (Tcomplex) const;
    Tcomplex operator + (Tcomplex) const;
    Tcomplex operator - (Tcomplex) const;
    Tcomplex operator * (Tcomplex) const;

    Tcomplex stepen(double amount) const;
    Tcomplex koren() const;
    double getRe() const;
    double getIm() const;
    bool compareUp(Tcomplex) const;
    bool compareDown(Tcomplex) const;

    friend ostream& operator << (ostream&, Tcomplex);
    friend istream& operator >> (istream&, Tcomplex&);
};


#endif //PRAKTIKA2_COMPLEX_H
