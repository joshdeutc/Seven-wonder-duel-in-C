#include "merveillewidget.h"
#include "ui_merveillewidget.h"

MerveilleWidget::MerveilleWidget(Merveille* m)
    : ui(new Ui::MerveilleWidget)
{
    ui->setupUi(this);
    ptrMerveille = m;
    imageLabel = new QLabel(this);

    this->setFixedSize(100, 75);

    connect(this, &QPushButton::clicked, this, [this]() {
        emit selected(this);
    });
}

MerveilleWidget::~MerveilleWidget()
{
    delete ui;
}

void MerveilleWidget::setImage(){

    QString imagePath = "ressource:/merveille/" + QString::fromStdString(ptrMerveille->getNom()) + ".png";
    QPixmap pixmap(imagePath);

    // Si l'image existe, on l'affiche
    if (!pixmap.isNull()) {
        // Redimensionner le pixmap pour correspondre à la taille du bouton
        QSize buttonSize = this->size();
        QPixmap scaledPixmap = pixmap.scaled(buttonSize, Qt::KeepAspectRatio);

        // Définir l'icône du bouton
        this->setIcon(QIcon(scaledPixmap));

        // Définir la taille de l'icône pour qu'elle corresponde à la taille du bouton
        this->setIconSize(buttonSize);
    } else {
        this->setText("Image non trouvée");
    }
}

void MerveilleWidget::setEmplacementLabel(QLabel* e) {
    emplacementLabel = e;
    if (emplacementLabel) {

        QPoint emplacementLabelPos = emplacementLabel->mapToParent(QPoint(0, 0));

        this->move(emplacementLabelPos);

        emplacementLabel->raise(); // Pour que le widget implicite soit bien affiché au-dessus de l'emplacement
    }
}


