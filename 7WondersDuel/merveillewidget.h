#ifndef MERVEILLEWIDGET_H
#define MERVEILLEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

#include "carte_bat_merv.h"

namespace Ui {
class MerveilleWidget;
}

class MerveilleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MerveilleWidget(Merveille* m);
    ~MerveilleWidget();
    Merveille* getPtrMerveille() {return ptrMerveille;}
    QLabel* getImageLabel() {return imageLabel;}
    void setPixmap();

private:
    Ui::MerveilleWidget *ui;
    Merveille* ptrMerveille;
    QLabel* imageLabel;
};

#endif // MERVEILLEWIDGET_H
