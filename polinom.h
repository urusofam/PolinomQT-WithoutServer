#ifndef PRAKTIKA3_POLINOM_H
#define PRAKTIKA3_POLINOM_H

#include "array.h"

class Tpolinom {
    number an;
    Tarray roots;
    Tarray coefficients;

public:
    Tpolinom();
    Tpolinom(number, const Tarray&);
    ~Tpolinom();
    void calculateCoefficients();
    number evaluate(number);
    Tarray& getRoots();
    Tarray& getCoefficients();
    number getAn();

    friend ostream& operator << (ostream&, Tpolinom);
    friend istream& operator >> (istream&, Tpolinom&);
};


#endif //PRAKTIKA3_POLINOM_H
