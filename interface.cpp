#include "interface.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

Tinterface::Tinterface(QWidget *parent) : QWidget(parent) {
    anInputRe = new QLineEdit(this);
    anInputIm = new QLineEdit(this);
    rootsInputRe = new QLineEdit(this);
    rootsInputIm = new QLineEdit(this);
    xInputRe = new QLineEdit(this);
    xInputIm = new QLineEdit(this);
    inputSize = new QLineEdit(this);
    indexInput = new QLineEdit(this);

    resultLabel = new QLabel("Результат:", this);

    addButton = new QPushButton("Добавить корень", this);
    changeButton = new QPushButton("Изменить коэффициент", this);
    evaluateButton = new QPushButton("Вычислить значение", this);
    resizeButton = new QPushButton("Изменить размер корней", this);
    displayForm1Button = new QPushButton("Вывести полином в 1 форме", this);
    displayForm2Button = new QPushButton("Вывести полином во 2 форме", this);
    indexButton = new QPushButton("Изменить корень по номеру", this);

    connect(addButton, &QPushButton::clicked, this, &Tinterface::addRoot);
    connect(changeButton, &QPushButton::clicked, this, &Tinterface::changeCoefficient);
    connect(evaluateButton, &QPushButton::clicked, this, &Tinterface::evaluatePolinom);
    connect(resizeButton, &QPushButton::clicked, this, &Tinterface::resizeRoots);
    connect(displayForm1Button, &QPushButton::clicked, this, &Tinterface::displayPolinomForm1);
    connect(displayForm2Button, &QPushButton::clicked, this, &Tinterface::displayPolinomForm2);
    connect(indexButton, &QPushButton::clicked, this, &Tinterface::changeRoot);



    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new QLabel("Коэффициент an:", this));
    QHBoxLayout *anLayout = new QHBoxLayout();
    anLayout->addWidget(anInputRe);
    anLayout->addWidget(anInputIm);
    anLayout->addWidget(new QLabel("i", this));
    mainLayout->addLayout(anLayout);
    mainLayout->addWidget(new QLabel("Номер корня:", this));
    mainLayout->addWidget(indexInput);
    mainLayout->addWidget(new QLabel("Корень:", this));
    QHBoxLayout *rootsLayout = new QHBoxLayout();
    rootsLayout->addWidget(rootsInputRe);
    rootsLayout->addWidget(rootsInputIm);
    rootsLayout->addWidget(new QLabel("i", this));
    mainLayout->addLayout(rootsLayout);
    mainLayout->addWidget(new QLabel("Размер массива корней:", this));
    mainLayout->addWidget(inputSize);
    mainLayout->addWidget(new QLabel("x:", this));
    QHBoxLayout *xLayout = new QHBoxLayout();
    xLayout->addWidget(xInputRe);
    xLayout->addWidget(xInputIm);
    xLayout->addWidget(new QLabel("i", this));
    mainLayout->addLayout(xLayout);
    mainLayout->addWidget(resultLabel);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(changeButton);
    buttonLayout->addWidget(indexButton);
    buttonLayout->addWidget(evaluateButton);
    buttonLayout->addWidget(resizeButton);
    buttonLayout->addWidget(displayForm1Button);
    buttonLayout->addWidget(displayForm2Button);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);
}

Tinterface::~Tinterface() {}

void Tinterface::addRoot() {
    polinom.getRoots().addElement(number(rootsInputRe->text().toDouble(), rootsInputIm->text().toDouble()));
    polinom.calculateCoefficients();
    QMessageBox::information(this, "Полином", "Корень добавлен!");
}

void Tinterface::changeCoefficient() {
    number newAn(anInputRe->text().toDouble(), anInputIm->text().toDouble());
    polinom = Tpolinom(newAn, polinom.getRoots());
    QMessageBox::information(this, "Изменение", "Коэффициент изменен!");
}

void Tinterface::evaluatePolinom() {
    number x(xInputRe->text().toDouble(), xInputIm->text().toDouble());
    number result = polinom.evaluate(x);
    resultLabel->setText((result.getIm() > 0) ? "Результат: " + QString::number(result.getRe()) + "+" + QString::number(result.getIm()) + "i"
                        : "Результат: " + QString::number(result.getRe()) + QString::number(result.getIm()) + "i");
}

void Tinterface::resizeRoots() {
    int newSize = inputSize->text().toInt();
    polinom.getRoots().changeSize(newSize);
    polinom.calculateCoefficients();
    QMessageBox::information(this, "Изменение", "Размер массива корней изменен!");
}

void Tinterface::displayPolinomForm1() {
    QString output;
    Tarray coefficients = polinom.getCoefficients();
    for (int i = coefficients.getSize() - 1; i >= 0; i--) {
        if (coefficients[i].getIm() < 0) output += "(" + QString::number(coefficients[i].getRe()) + QString::number(coefficients[i].getIm()) + "i)x^" + QString::number(i);
        else output += "(" + QString::number(coefficients[i].getRe()) + "+" + QString::number(coefficients[i].getIm()) + "i)x^" + QString::number(i);
        if (i > 0) output += " + ";
    }
    resultLabel->setText(output);
}

void Tinterface::displayPolinomForm2() {
    QString output;
    Tarray roots = polinom.getRoots();
    if (polinom.getAn().getIm() < 0) output += "(" + QString::number(polinom.getAn().getRe()) + QString::number(polinom.getAn().getIm()) + "i)";
    else output += "(" + QString::number(polinom.getAn().getRe()) + "+" + QString::number(polinom.getAn().getIm()) + "i)";
    for (int i = 0; i < roots.getSize(); i++){
        if (roots[i].getIm() < 0) output += "(x - (" + QString::number(roots[i].getRe()) + QString::number(roots[i].getIm()) + "i))";
        else output += "(x - (" + QString::number(roots[i].getRe()) + "+" + QString::number(roots[i].getIm()) + "i))";
    }
    resultLabel->setText(output);
}

void Tinterface::changeRoot() {
    int index = indexInput->text().toInt();
    number root(rootsInputRe->text().toDouble(), rootsInputIm->text().toDouble());
    polinom.getRoots().changeElement(index, root);
    polinom.calculateCoefficients();
    QMessageBox::information(this, "Изменение", "Корень изменён по номеру!");
}
