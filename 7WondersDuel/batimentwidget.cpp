#include "batimentwidget.h"
#include "ui_batimentwidget.h"

BatimentWidget::BatimentWidget(QWidget* parent, const Carte* c){
    ptrCarte = c;
};

BatimentWidget::~BatimentWidget()
{
    delete ui;
}
