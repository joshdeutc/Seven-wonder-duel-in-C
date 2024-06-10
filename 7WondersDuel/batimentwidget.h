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
    BatimentWidget(QWidget *parent = nullptr, const Carte* c = nullptr);
    ~BatimentWidget();

private:
    Ui::BatimentWidget *ui;
    Carte* ptrCarte;
};

#endif // BATIMENTWIDGET_H
