#include "batimentwidget.h"
#include "ui_batimentwidget.h"
#include "carte_bat_merv.h"

BatimentWidget::BatimentWidget(Batiment* b)
    : ui(new Ui::BatimentWidget)
{
    ui->setupUi(this);
    ptrBatiment = b;
    imageLabel = new QLabel(this);
}

BatimentWidget::~BatimentWidget()
{
    delete ui;
}

void BatimentWidget::setPixmap(int a){

    QString imagePath = "ressource:/batiments/age_" + QString::fromStdString(std::to_string(a)) + QString::fromStdString(ptrBatiment->getNom()) + ".png";
    QPixmap pixmap(imagePath);

    // Si l'image existe, on l'affiche
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(75, 100, Qt::KeepAspectRatio));
    } else {
        imageLabel->setText("Image non trouvée");
    }

}
