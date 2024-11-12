#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <Qlabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include "polinom.h"

class Tinterface : public QWidget {
    Q_OBJECT

    Tpolinom polinom;

    QLineEdit *anInputRe;
    QLineEdit *indexInput;
    QLineEdit *anInputIm;
    QLineEdit *rootsInputRe;
    QLineEdit *rootsInputIm;
    QLineEdit *xInputRe;
    QLineEdit *xInputIm;
    QLineEdit *inputSize;
    QLabel *resultLabel;

    QPushButton *addButton;
    QPushButton *changeButton;
    QPushButton *evaluateButton;
    QPushButton *resizeButton;
    QPushButton *indexButton;
    QPushButton *displayForm1Button;
    QPushButton *displayForm2Button;
private slots:
    void addRoot();
    void changeCoefficient();
    void changeRoot();
    void evaluatePolinom();
    void resizeRoots();
    void displayPolinomForm1();
    void displayPolinomForm2();
public:
    Tinterface(QWidget *parent = nullptr);
    ~Tinterface();
};
#endif // INTERFACE_H
