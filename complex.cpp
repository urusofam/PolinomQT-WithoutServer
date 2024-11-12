#include "complex.h"
#include <cmath>

Tcomplex::Tcomplex() {

}

Tcomplex::Tcomplex(double r) {
    re = r;
}

Tcomplex::Tcomplex(double r, double i) {
    re = r;
    im = i;
}

Tcomplex Tcomplex::stepen(double amount) const {
    Tcomplex res;
    double norm = sqrt(re * re + im * im);
    double cos_phi = re / norm;
    double phi = acos(cos_phi);
    double norm_stepen = pow(norm, amount);
    res.re = norm_stepen * cos(amount * phi);
    res.im = norm_stepen * sin(amount * phi);
    return res;
}

Tcomplex Tcomplex::koren() const {
    Tcomplex res;
    res.im = sqrt((-re + sqrt(re * re + im * im)) / 2);
    res.re = im / (2 * res.im);
    return res;
}

bool Tcomplex::compareUp(Tcomplex c) const {
    double norm1 = sqrt(re * re + im * im);
    double norm2 = sqrt(c.re * c.re + c.im * c.im);

    if (norm1 != norm2) {
        return norm1 > norm2;
    }
    else {
        double cos_phi1 = re / norm1;
        double phi1 = acos(cos_phi1);
        double cos_phi2 = c.re / norm2;
        double phi2 = acos(cos_phi2);
        return phi1 > phi2;
    }
}

bool Tcomplex::compareDown(Tcomplex c) const {
    double norm1 = sqrt(re * re + im * im);
    double norm2 = sqrt(c.re * c.re + c.im * c.im);

    if (norm1 != norm2) {
        return norm1 < norm2;
    }
    else {
        double cos_phi1 = re / norm1;
        double phi1 = acos(cos_phi1);
        double cos_phi2 = c.re / norm2;
        double phi2 = acos(cos_phi2);
        return phi1 < phi2;
    }
}

double Tcomplex::getRe() const {
    return re;
}

double Tcomplex::getIm() const {
    return im;
}


Tcomplex Tcomplex::operator / (Tcomplex c) const{
    Tcomplex res;
    res.re = (re * c.re + im * c.im) / (c.re * c.re + c.im * c.im);
    res.im = (c.re * im - re * c.im) / (c.re * c.re + c.im * c.im);
    return res;
}

Tcomplex Tcomplex::operator + (Tcomplex c) const{
    Tcomplex res;
    res.re = re + c.re;
    res.im = im + c.im;
    return res;
}

Tcomplex Tcomplex::operator - (Tcomplex c) const{
    Tcomplex res;
    res.re = re - c.re;
    res.im = re - c.im;
    return res;
}

Tcomplex Tcomplex::operator * (Tcomplex c) const{
    Tcomplex res;
    res.re = re * c.re - im * c.im;
    res.im = re * c.im + im * c.re;
    return res;
}

ostream& operator << (ostream& os, Tcomplex c){
    if (c.im >= 0) os << c.re << '+' << c.im << 'i';
    else os << c.re << c.im << 'i';
    return os;
}

istream& operator >> (istream& is, Tcomplex& c){
    is >> c.re >> c.im;
    return is;
}
