#include "a_propos.h"
#include "ui_a_propos.h"

A_propos::A_propos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::A_propos)
{
    ui->setupUi(this);
    this->setFixedSize(400, 300);
}

A_propos::~A_propos()
{
    delete ui;
}
