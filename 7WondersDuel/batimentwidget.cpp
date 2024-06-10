#include "cartewidget.h"
#include "ui_cartewidget.h"

CarteWidget::CarteWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CarteWidget)
{
    ui->setupUi(this);
}

CarteWidget::~CarteWidget()
{
    delete ui;
}
