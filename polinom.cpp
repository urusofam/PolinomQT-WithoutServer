#include "polinom.h"

Tpolinom::Tpolinom() {
    an = Tcomplex(0, 0);
    roots = Tarray(0);
}

Tpolinom::Tpolinom(number an_, const Tarray& roots_) {
    an = an_;
    roots = roots_;
    calculateCoefficients();
}

Tpolinom::~Tpolinom() {
}

void Tpolinom::calculateCoefficients() {
    coefficients = Tarray(1);
    coefficients[0] = Tcomplex(1, 0);

    for (int i = 0; i < roots.getSize(); i++) {
        Tarray temp = Tarray(2);
        temp[0] = Tcomplex(-1, 0) * roots[i];
        temp[1] = Tcomplex(1, 0);
        int n1 = coefficients.getSize(), n2 = temp.getSize();
        Tarray result = Tarray(n1 + n2 - 1);
        for(int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                result[i + j] = result[i + j] + coefficients[i] * temp[j];
            }
        }
        coefficients = result;
    }

    for (int i = 0; i < coefficients.getSize(); i++) {
        coefficients[i] = coefficients[i] * an;
    }
}


number Tpolinom::evaluate(number x) {
    number result = coefficients[coefficients.getSize() - 1];
    for (int i = coefficients.getSize() - 2; i >= 0; i--) {
        result = result * x + coefficients[i];
    }
    return result;
}

Tarray& Tpolinom::getRoots() {
    return roots;
}

Tarray& Tpolinom::getCoefficients() {
    return coefficients;
}

number Tpolinom::getAn() {
    return an;
}

istream& operator>>(istream& in, Tpolinom& p) {
    cout << "Введите коэффициент при старшей степени (an): ";
    in >> p.an;

    cout << "Введите количество корней: ";
    int rootCount;
    in >> rootCount;

    p.roots.changeSize(rootCount);
    cout << "Введите корни: ";
    for (int i = 0; i < rootCount; i++) {
        in >> p.roots[i];
    }

    p.calculateCoefficients();
    return in;
}

ostream &operator<<(ostream& out, Tpolinom p) {
    out << "Коэффициенты полинома: ";
    for (int i = p.coefficients.getSize() - 1; i >= 0; i--) {
        out << "(" << p.coefficients[i] << ")x^" << i;
        if (i > 0) out << " + ";
    }
    return out;
}
