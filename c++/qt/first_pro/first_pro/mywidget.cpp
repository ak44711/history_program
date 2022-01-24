#include "mywidget.h"
#include<QPushButton>
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{

    QPushButton * btn2 = new QPushButton("print", this);
    QPushButton * exit_btn = new QPushButton("exit", this);
    setFixedSize(600,400);
    exit_btn->move(100,100);
    //信号的发送者， 发送的信号(地址)， 接收者， 槽函数（地址）
    //信号：signals 槽:Slots
    connect(exit_btn, &QPushButton::clicked, this, &myWidget::close);
}

myWidget::~myWidget()
{

}

