#include "calculator.h"
#include "ui_calculator.h"
#include "BigNumbersLibs/BigNumbers.h"


Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    //Two numbers are only ever used for the calculator

}

Calculator::~Calculator()
{
    delete ui;
}


void Calculator::on_ONE_Button_clicked()
{
    ui->textEdit->insertPlainText("1");
    QString s = ui->textEdit->toPlainText();

}


void Calculator::on_TWO_Button_clicked()
{
    ui->textEdit->insertPlainText("2");
    QString s = ui->textEdit->toPlainText();

}

void Calculator::on_THREE_Button_clicked()
{
    ui->textEdit->insertPlainText("3");
    QString s = ui->textEdit->toPlainText();
}

void Calculator::on_FOUR_Button_clicked()
{
    ui->textEdit->insertPlainText("4");
    QString s = ui->textEdit->toPlainText();
}

void Calculator::on_FIVE_Button_clicked()
{
    ui->textEdit->insertPlainText("5");
    QString s = ui->textEdit->toPlainText();
}

void Calculator::on_SIX_Button_clicked()
{
    ui->textEdit->insertPlainText("6");
    QString s = ui->textEdit->toPlainText();
}

void Calculator::on_SEVEN_Button_clicked()
{
    ui->textEdit->insertPlainText("7");
    QString s = ui->textEdit->toPlainText();
}

void Calculator::on_EIGHT_Button_clicked()
{
    ui->textEdit->insertPlainText("8");
    QString s = ui->textEdit->toPlainText();
}

void Calculator::on_NINE_Button_clicked()
{
    ui->textEdit->insertPlainText("9");
    QString s = ui->textEdit->toPlainText();
}

void Calculator::on_NEGATIVE_Button_clicked()
{
    ui->textEdit->insertPlainText("-");
    QString s = ui->textEdit->toPlainText();
}

void Calculator::on_ZERO_Button_clicked()
{
    ui->textEdit->insertPlainText("0");
    QString s = ui->textEdit->toPlainText();
}

void Calculator::on_CLEAR_Button_clicked()
{
    ui->textEdit->clear();
    QString s = ui->textEdit->toPlainText();

    //Wipe out both Big Numbers

}

void Calculator::on_DIVIDE_Button_clicked()
{
    ui->textEdit->insertPlainText("/");
    QString s = ui->textEdit->toPlainText();
}

void Calculator::on_MULTIPLY_Button_clicked()
{
    ui->textEdit->insertPlainText("*");
    QString s = ui->textEdit->toPlainText();
}

void Calculator::on_SUBTRACT_Button_clicked()
{
    ui->textEdit->insertPlainText("_");
    QString s = ui->textEdit->toPlainText();
}

void Calculator::on_ADDITION_Button_clicked()
{
    ui->textEdit->insertPlainText("+");
    QString s = ui->textEdit->toPlainText();
}

void Calculator::on_MOD_Button_clicked()
{
    ui->textEdit->insertPlainText("%");
    QString s = ui->textEdit->toPlainText();
}

void Calculator::on_EQUAL_Button_clicked()
{
    ui->textEdit->insertPlainText("=");
    QString s = ui->textEdit->toPlainText();
    //Now we have to do the calculations
    //first lets split the sting of input type "BigNumber" + "opperator" + "BigNumber"
    bool first=true;
    QString one; //first big number
    QChar op;
    QString two; //second big number

    for(int x=0; x< s.length();x++){
        if (first){
            //add the element to first
            if(s.at(x) == '+' || s.at(x)=='-'||s.at(x) == '/'||s.at(x)=='*'||s.at(x) == '%' ){
                op = s.at(x);
                first = false;
            }
            else{
                one += s.at(x);
            }
        }
        else{
            two += s.at(x);
        }
    }

    //Now we split the Qstring into parts
    std::string o = one.toStdString();
    std::string t =two.toStdString();

    //Create two BigNumbers from the strings
    BigNumbers bigOne(o);
    BigNumbers bigTwo(t);
    BigNumbers result;


    //Lets conver Qstrings to strings for making our big number
    if(op=='+'){
        //Addition
        result = bigOne + bigTwo;
    }
    else if(op=='-'){
        //Subtraction
        result = bigOne - bigTwo;
    }
    else if(op=='/'){
        //division
        result = bigOne /bigTwo;
    }
    else if (op== '*'){
        //multiplication
        result = bigOne *bigTwo;
    }
    else if(op == '%'){
        //mod
        result = bigOne % bigTwo;

    }

    //Display the results to the screen
    QString answer =QString::fromStdString(result.toString());
    ui->textEdit->insertPlainText(answer);


    }
