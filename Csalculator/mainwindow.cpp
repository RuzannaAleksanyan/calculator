#include "mainwindow.h"
#include "./ui_mainwindow.h"

bool userIsTypingSecondNumber = false;
double firstNum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("0");

    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digit_pressed()));

    connect(ui->pushButton_plusMinus, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pushButton_precent, SIGNAL(released()), this, SLOT(unary_operation_pressed()));

    connect(ui->pushButton_add, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_sub, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_mul, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_div, SIGNAL(released()), this, SLOT(binary_operation_pressed()));


    ui->pushButton_add->setCheckable(true);
    ui->pushButton_sub->setCheckable(true);
    ui->pushButton_mul->setCheckable(true);
    ui->pushButton_div->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed() {
    QPushButton* button = (QPushButton*)sender();
    double labelNumber;
    QString newLable;
    if((ui->pushButton_add->isChecked() || ui->pushButton_sub->isChecked() ||
         ui->pushButton_mul->isChecked() || ui->pushButton_div->isChecked()) && (!userIsTypingSecondNumber)) {
        labelNumber = button->text().toDouble();
        userIsTypingSecondNumber = true;
        newLable = QString::number(labelNumber, 'g', 15);
    } else {
        if(ui->label->text().contains(",") && button->text() == "0") {
            newLable = ui->label->text() + button->text();
        } else {
            labelNumber = (ui->label->text() + button->text()).toDouble();
            newLable = QString::number(labelNumber, 'g', 15);
        }
    }
    ui->label->setText(newLable);
}



void MainWindow::on_pushButton_dat_released()
{
    if (!ui->label->text().contains(".")) {
        ui->label->setText(ui->label->text() + ".");
    }
}

void MainWindow::unary_operation_pressed() {
    QPushButton* button = (QPushButton*)sender();
    double lableNumber;
    QString newLable;
    if(button->text() == "+/-") {
        lableNumber = ui->label->text().toDouble();
        lableNumber = lableNumber * -1;
        newLable = QString::number(lableNumber, 'g', 15);
        ui->label->setText(newLable);
    }
    if(button->text() == "%") {
        lableNumber = ui->label->text().toDouble();
        lableNumber = lableNumber * 0.01;
        newLable = QString::number(lableNumber, 'g', 15);
        ui->label->setText(newLable);
    }
}

void MainWindow::binary_operation_pressed() {
    firstNum = ui->label->text().toDouble();
    ui->label->clear();
}


void MainWindow::on_pushButton_equal_released()
{
    double labelNumber;
    QString newLable;
    double secondNum;
    secondNum = ui->label->text().toDouble();
    if(ui->pushButton_add->isChecked()) {
        labelNumber = firstNum + secondNum;
        newLable = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLable);
        ui->pushButton_add->setChecked(false);
    } else if(ui->pushButton_sub->isChecked()) {
        labelNumber = firstNum - secondNum;
        newLable = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLable);
        ui->pushButton_sub->setCheckable(false);
    } else if(ui->pushButton_mul->isCheckable()) {
        labelNumber = firstNum * secondNum;
        newLable = QString::number(labelNumber);
        ui->pushButton_mul->setCheckable(false);
    } else if(ui->pushButton_div->isCheckable()) {
        if(secondNum == 0) {
            return;
        }
        labelNumber = firstNum / secondNum;
        newLable = QString::number(labelNumber);
        ui->label->setText(newLable);
        ui->pushButton_div->setCheckable(false);
    }

    userIsTypingSecondNumber= false;
}


void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_add->setCheckable(false);
    ui->pushButton_sub->setCheckable(false);
    ui->pushButton_mul->setCheckable(false);
    ui->pushButton_div->setCheckable(false);

    userIsTypingSecondNumber = false;

    ui->label->setText("0");
}

