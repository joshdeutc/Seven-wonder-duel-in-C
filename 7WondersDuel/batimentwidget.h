#ifndef BATIMENTWIDGET_H
#define BATIMENTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <string>

#include "jeu.h"
#include "carte_bat_merv.h"

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
    Batiment* getPtrBatiment(){return ptrBatiment;}
    QLabel* getImageLabel(){return imageLabel;};
    void setPixmap(int a);

private:
    Ui::BatimentWidget *ui;
    Batiment* ptrBatiment;
    QLabel* imageLabel;
};

#endif // BATIMENTWIDGET_H
