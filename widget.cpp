#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    pbEnabled();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::pbEnabled() {
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 200);
    ui->pbTang->setEnabled(money >= 300);
    ui->pbReset->setEnabled(money > 0);
}

void Widget::changeMoney(int diff) {
    money += diff;
    ui->lcdNumber->display(money);

    pbEnabled();
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    int coins[] = {500, 100, 50, 10};
    int tmp = money, coinCounts[4] = {0};
    QString msg = "";

    for(int i = 0; i < 4; i++) {
        coinCounts[i] =tmp / coins[i];
        tmp = tmp % coins[i];

        if(coinCounts[i]) {
            msg += QString::number(coins[i]) + ": " + QString::number(coinCounts[i]) + "\n";
        }
    }

    mb.information(nullptr, "title", msg);
    money = 0;
    changeMoney(0);
}

