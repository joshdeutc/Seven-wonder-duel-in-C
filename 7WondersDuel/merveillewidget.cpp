#include "merveillewidget.h"
#include "ui_merveillewidget.h"

MerveilleWidget::MerveilleWidget(Merveille* m)
    : ui(new Ui::MerveilleWidget)
{
    ui->setupUi(this);
    ptrMerveille = m;
    imageLabel = new QLabel(this);
}

MerveilleWidget::~MerveilleWidget()
{
    delete ui;
}

void MerveilleWidget::setPixmap(){

    QString imagePath = "ressource:/merveille/" + QString::fromStdString(ptrMerveille->getNom()) + ".png";
    QPixmap pixmap(imagePath);

    // Si l'image existe, on l'affiche
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(75, 100, Qt::KeepAspectRatio));
    } else {
        imageLabel->setText("Image non trouvée");
    }

}

