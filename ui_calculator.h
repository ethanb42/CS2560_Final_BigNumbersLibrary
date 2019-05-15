/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralWidget;
    QPushButton *ONE_Button;
    QPushButton *TWO_Button;
    QPushButton *THREE_Button;
    QPushButton *SIX_Button;
    QPushButton *FOUR_Button;
    QPushButton *FIVE_Button;
    QPushButton *NINE_Button;
    QPushButton *EIGHT_Button;
    QPushButton *SEVEN_Button;
    QPushButton *CLEAR_Button;
    QPushButton *ZERO_Button;
    QPushButton *NEGATIVE_Button;
    QPushButton *DIVIDE_Button;
    QPushButton *MULTIPLY_Button;
    QPushButton *SUBTRACT_Button;
    QPushButton *ADDITION_Button;
    QPushButton *MOD_Button;
    QPushButton *EQUAL_Button;
    QTextEdit *textEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(428, 518);
        centralWidget = new QWidget(Calculator);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ONE_Button = new QPushButton(centralWidget);
        ONE_Button->setObjectName(QString::fromUtf8("ONE_Button"));
        ONE_Button->setGeometry(QRect(0, 100, 91, 81));
        TWO_Button = new QPushButton(centralWidget);
        TWO_Button->setObjectName(QString::fromUtf8("TWO_Button"));
        TWO_Button->setGeometry(QRect(90, 100, 91, 81));
        THREE_Button = new QPushButton(centralWidget);
        THREE_Button->setObjectName(QString::fromUtf8("THREE_Button"));
        THREE_Button->setGeometry(QRect(180, 100, 91, 81));
        SIX_Button = new QPushButton(centralWidget);
        SIX_Button->setObjectName(QString::fromUtf8("SIX_Button"));
        SIX_Button->setGeometry(QRect(180, 190, 91, 81));
        FOUR_Button = new QPushButton(centralWidget);
        FOUR_Button->setObjectName(QString::fromUtf8("FOUR_Button"));
        FOUR_Button->setGeometry(QRect(0, 190, 91, 81));
        FIVE_Button = new QPushButton(centralWidget);
        FIVE_Button->setObjectName(QString::fromUtf8("FIVE_Button"));
        FIVE_Button->setGeometry(QRect(90, 190, 91, 81));
        NINE_Button = new QPushButton(centralWidget);
        NINE_Button->setObjectName(QString::fromUtf8("NINE_Button"));
        NINE_Button->setGeometry(QRect(180, 280, 91, 81));
        EIGHT_Button = new QPushButton(centralWidget);
        EIGHT_Button->setObjectName(QString::fromUtf8("EIGHT_Button"));
        EIGHT_Button->setGeometry(QRect(90, 280, 91, 81));
        SEVEN_Button = new QPushButton(centralWidget);
        SEVEN_Button->setObjectName(QString::fromUtf8("SEVEN_Button"));
        SEVEN_Button->setGeometry(QRect(0, 280, 91, 81));
        CLEAR_Button = new QPushButton(centralWidget);
        CLEAR_Button->setObjectName(QString::fromUtf8("CLEAR_Button"));
        CLEAR_Button->setGeometry(QRect(180, 370, 91, 81));
        ZERO_Button = new QPushButton(centralWidget);
        ZERO_Button->setObjectName(QString::fromUtf8("ZERO_Button"));
        ZERO_Button->setGeometry(QRect(90, 370, 91, 81));
        NEGATIVE_Button = new QPushButton(centralWidget);
        NEGATIVE_Button->setObjectName(QString::fromUtf8("NEGATIVE_Button"));
        NEGATIVE_Button->setGeometry(QRect(0, 370, 91, 81));
        DIVIDE_Button = new QPushButton(centralWidget);
        DIVIDE_Button->setObjectName(QString::fromUtf8("DIVIDE_Button"));
        DIVIDE_Button->setGeometry(QRect(270, 100, 131, 61));
        MULTIPLY_Button = new QPushButton(centralWidget);
        MULTIPLY_Button->setObjectName(QString::fromUtf8("MULTIPLY_Button"));
        MULTIPLY_Button->setGeometry(QRect(270, 160, 131, 61));
        SUBTRACT_Button = new QPushButton(centralWidget);
        SUBTRACT_Button->setObjectName(QString::fromUtf8("SUBTRACT_Button"));
        SUBTRACT_Button->setGeometry(QRect(270, 220, 131, 61));
        ADDITION_Button = new QPushButton(centralWidget);
        ADDITION_Button->setObjectName(QString::fromUtf8("ADDITION_Button"));
        ADDITION_Button->setGeometry(QRect(270, 280, 131, 61));
        MOD_Button = new QPushButton(centralWidget);
        MOD_Button->setObjectName(QString::fromUtf8("MOD_Button"));
        MOD_Button->setGeometry(QRect(270, 340, 131, 61));
        EQUAL_Button = new QPushButton(centralWidget);
        EQUAL_Button->setObjectName(QString::fromUtf8("EQUAL_Button"));
        EQUAL_Button->setGeometry(QRect(270, 400, 131, 61));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 401, 101));
        Calculator->setCentralWidget(centralWidget);
        textEdit->raise();
        ONE_Button->raise();
        TWO_Button->raise();
        THREE_Button->raise();
        SIX_Button->raise();
        FOUR_Button->raise();
        FIVE_Button->raise();
        NINE_Button->raise();
        EIGHT_Button->raise();
        SEVEN_Button->raise();
        CLEAR_Button->raise();
        ZERO_Button->raise();
        NEGATIVE_Button->raise();
        DIVIDE_Button->raise();
        MULTIPLY_Button->raise();
        SUBTRACT_Button->raise();
        ADDITION_Button->raise();
        MOD_Button->raise();
        EQUAL_Button->raise();
        mainToolBar = new QToolBar(Calculator);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Calculator->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Calculator);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Calculator->setStatusBar(statusBar);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QApplication::translate("Calculator", "Calculator", nullptr));
        ONE_Button->setText(QApplication::translate("Calculator", "1", nullptr));
        TWO_Button->setText(QApplication::translate("Calculator", "2", nullptr));
        THREE_Button->setText(QApplication::translate("Calculator", "3", nullptr));
        SIX_Button->setText(QApplication::translate("Calculator", "6", nullptr));
        FOUR_Button->setText(QApplication::translate("Calculator", "4", nullptr));
        FIVE_Button->setText(QApplication::translate("Calculator", "5", nullptr));
        NINE_Button->setText(QApplication::translate("Calculator", "9", nullptr));
        EIGHT_Button->setText(QApplication::translate("Calculator", "8", nullptr));
        SEVEN_Button->setText(QApplication::translate("Calculator", "7", nullptr));
        CLEAR_Button->setText(QApplication::translate("Calculator", "C", nullptr));
        ZERO_Button->setText(QApplication::translate("Calculator", "0", nullptr));
        NEGATIVE_Button->setText(QApplication::translate("Calculator", "-", nullptr));
        DIVIDE_Button->setText(QApplication::translate("Calculator", "/", nullptr));
        MULTIPLY_Button->setText(QApplication::translate("Calculator", "x", nullptr));
        SUBTRACT_Button->setText(QApplication::translate("Calculator", "-", nullptr));
        ADDITION_Button->setText(QApplication::translate("Calculator", "+", nullptr));
        MOD_Button->setText(QApplication::translate("Calculator", "%", nullptr));
        EQUAL_Button->setText(QApplication::translate("Calculator", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
