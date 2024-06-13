#ifndef BATIMENTWIDGET_H
#define BATIMENTWIDGET_H

#include "jeu.h"
#include "carte_bat_merv.h"

#include <QWidget>
#include <QLabel>

using namespace std;

namespace Ui {
class BatimentWidget;
}

class BatimentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BatimentWidget(Batiment* b = nullptr);
    ~BatimentWidget();
    Batiment* getPtrBatiment() {return ptrBatiment;}
    QLabel* getImageLabel() {return imageLabel;}
    QLabel* getEmplacementLabel() {return emplacementLabel;}
    void setEmplacementLabel(QLabel* e) {emplacementLabel = e;}
    void setPixmap(int a);

private:
    Ui::BatimentWidget *ui;
    Batiment* ptrBatiment;
    QLabel* imageLabel;
    QLabel* emplacementLabel = nullptr;
};

#endif // BATIMENTWIDGET_H
