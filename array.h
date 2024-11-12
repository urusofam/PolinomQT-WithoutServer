#ifndef PRAKTIKA1_ARRAY_H
#define PRAKTIKA1_ARRAY_H

#include "number.h"
#include <iostream>

using namespace std;

class Tarray {
    number* arr;
    int size;
public:
    Tarray();
    Tarray(int size);
    Tarray(const Tarray&);
    ~Tarray();

    void changeElement(int, number);
    void addElement(number);
    void changeSize(int);
    int getSize() const;
    number average();
    number SKO();
    static void swap(number&, number&);
    void sortUp();
    void sortDown();

    number& operator [] (int);
    Tarray& operator = (const Tarray&);
    friend ostream& operator << (ostream&, Tarray&);
    friend istream& operator >> (istream&, Tarray&);
};


#endif //PRAKTIKA1_ARRAY_H
