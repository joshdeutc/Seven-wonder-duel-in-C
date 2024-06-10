#include "jetonprogreswidget.h"
#include "ui_jetonprogreswidget.h"
#include "carte_bat_merv.h"

JetonProgresWidget::JetonProgresWidget(JetonProgres* j)
    : ui(new Ui::JetonProgresWidget)
{
    ui->setupUi(this);
    ptrJetonProgres = j;
    imageLabel = new QLabel(this);
}

JetonProgresWidget::~JetonProgresWidget()
{
    delete ui;
}

void JetonProgresWidget::setPixmap(){

    QString imagePath = "ressource:/batiments/jetons" + QString::fromStdString(ptrJetonProgres->getNom()) + ".png";
    QPixmap pixmap(imagePath);

    // Si l'image existe, on l'affiche
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(75, 75, Qt::KeepAspectRatio));
    } else {
        imageLabel->setText("Image non trouvée");
    }

}
