#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <BigNumbersLibs/BigNumbers.h>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT
    /*
    BigNumbers one;
    BigNumbers two;
*/

public:
    //Has two bignumbers to work with

    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:


    void on_ONE_Button_clicked();

    void on_TWO_Button_clicked();

    void on_THREE_Button_clicked();

    void on_FOUR_Button_clicked();

    void on_FIVE_Button_clicked();

    void on_SIX_Button_clicked();

    void on_SEVEN_Button_clicked();

    void on_EIGHT_Button_clicked();

    void on_NINE_Button_clicked();

    void on_NEGATIVE_Button_clicked();

    void on_ZERO_Button_clicked();

    void on_CLEAR_Button_clicked();

    void on_DIVIDE_Button_clicked();

    void on_MULTIPLY_Button_clicked();

    void on_SUBTRACT_Button_clicked();

    void on_ADDITION_Button_clicked();

    void on_MOD_Button_clicked();

    void on_EQUAL_Button_clicked();

private:
    Ui::Calculator *ui;
};

#endif // CALCULATOR_H
