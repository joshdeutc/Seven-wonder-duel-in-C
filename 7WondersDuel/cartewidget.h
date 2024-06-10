#ifndef CARTEWIDGET_H
#define CARTEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include "carte_bat_merv.h" // Votre fichier existant

namespace Ui {
class CarteWidget;
}

class CarteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CarteWidget(QWidget *parent = nullptr);
    ~CarteWidget();

private:
    Ui::CarteWidget *ui;
};

#endif // CARTEWIDGET_H
