#include "array.h"
#include <iostream>

using namespace std;

Tarray::Tarray(int size_) {
    arr = new number[size_];
    for (int i = 0; i < size_; i++) {
        arr[i] = number(0, 0);
    }
    size = size_;
}

Tarray::Tarray() {
    arr = new number[0];
    size = 0;
}

Tarray::Tarray(const Tarray& other) {
    size = other.size;
    arr = new number[size];
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

Tarray::~Tarray(){
    delete[] arr;
}

void Tarray::changeElement(int position, number value) {
    if (position > 0 && position <= size) arr[position - 1] = value;
}

void Tarray::changeSize(int newSize) {
    auto* newArr = new number[newSize];

    for (int i = 0; i < newSize; i++) newArr[i] = (i < size) ? arr[i] : number(0, 0);

    delete[] arr;
    arr = newArr;
    size = newSize;
}

void Tarray::addElement(number x){
    size++;
    auto* newArr = new number[size];

    for (int i = 0; i < size - 1; i++) newArr[i] = arr[i];
    newArr[size - 1] = x;

    delete[] arr;
    arr = newArr;
}

int Tarray::getSize() const {
    return size;
}

number Tarray::average() {
    if (size == 0) return 0;

    number sum = 0;

    for(int i = 0; i < size; i++){
        sum = sum + arr[i];
    }

    return sum / size;
}

number Tarray::SKO() {
    if (size == 0) return 0;

    number avg = average();
    number sum = 0;

    for(int i = 0; i < size; i++) {
        number a = (arr[i] - avg).stepen(2);
        sum = sum + a;
    }
    return sum.koren();
}

void Tarray::swap(number& a, number& b) {
    number temp = a;
    a = b;
    b = temp;
}

void Tarray::sortUp() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].compareUp(arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Tarray::sortDown(){
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].compareDown(arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

Tarray& Tarray::operator = (const Tarray& other) {
    if (this != &other) {
        delete[] arr;
        size = other.size;
        arr = new number[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

ostream& operator << (ostream& out, Tarray& a) {
    for (int i = 0; i < a.size; i++) {
        out << a.arr[i] << " ";
    }
    return out;
}

istream& operator >> (istream &in, Tarray &a) {
    for (int i = 0; i < a.size; i++){
        in >> a.arr[i];
    }
    return in;
}

number& Tarray::operator[](int index) {
    return arr[index];
}
