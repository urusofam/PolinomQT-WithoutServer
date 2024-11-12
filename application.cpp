#include "application.h"
#include <iostream>
#include "polinom.h"

using namespace std;

Tapplication::Tapplication() {

}

int Tapplication::exec() {
    int choice;
    Tpolinom polinom = Tpolinom();
    while (true) {
        choice = menu();
        system("cls");
        switch (choice) {
            case 1: {
                cin >> polinom;
                system("cls");
                break;
            }
            case 2: {
                int option;
                cout << "1. Изменить коэффициент an\n";
                cout << "2. Изменить один из корней по номеру\n";
                cin >> option;
                if (option == 1) {
                    number newAn;
                    cout << "Введите новый коэффициент an: ";
                    cin >> newAn;
                    polinom = Tpolinom(newAn, polinom.getRoots());
                } else if (option == 2) {
                    int index;
                    number newRoot;
                    cout << "Введите номер корня: ";
                    cin >> index;
                    cout << "Введите новый корень: ";
                    cin >> newRoot;
                    polinom.getRoots().changeElement(index, newRoot);
                    polinom.calculateCoefficients();
                }
                system("cls");
                break;
            }
            case 3: {
                number x;
                cout << "Введите значение x для вычисления значения полинома: ";
                cin >> x;
                cout << "Значение полинома в точке x = " << x << " : " << polinom.evaluate(x) << endl;
                break;
            }
            case 4:
                int newSize;
                cout << "Введите новую размерность массива корней: ";
                cin >> newSize;
                polinom.getRoots().changeSize(newSize);
                polinom.getCoefficients().changeSize(1);
                polinom.calculateCoefficients();
                system("cls");
                break;
            case 5: {
                int form;
                cout << "Выберите форму вывода:\n";
                cout << "1. an * x^n + a(n-1) * x^(n-1) + ... + a1 * x + a0\n";
                cout << "2. an(x - r1)(x - r2)...(x - rn)\n";
                cin >> form;
                system("cls");
                if (form == 1) {
                    cout << polinom << endl;
                } else if (form == 2) {
                    Tarray roots = polinom.getRoots();
                    cout << "(" << polinom.getAn() << ')';
                    for (int i = 0; i < roots.getSize(); i++){
                        cout << "(x - (" << roots[i] << "))";
                    }
                    cout << endl;
                }
                break;
            }
            case 6:
                return 0;
            default:
                cout << "Нет такой команды!\n";
                break;
        }
    }
}

int Tapplication::menu(){
    cout << "1. Ввод значений для создания объекта полином\n";
    cout << "2. Изменение коэффициента an или одного из корней\n";
    cout << "3. Вычисление значения полинома в заданной точке\n";
    cout << "4. Изменение размерности массива корней\n";
    cout << "5. Вывод полинома (форма 1 или форма 2)\n";
    cout << "6. Выход из программы\n";
    cout << "Введите ваш выбор: ";

    int ch;
    cin >> ch;
    return ch;
}