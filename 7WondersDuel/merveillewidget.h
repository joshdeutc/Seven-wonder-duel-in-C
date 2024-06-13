#ifndef MERVEILLEWIDGET_H
#define MERVEILLEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "carte_bat_merv.h"

namespace Ui {
class MerveilleWidget;
}

class MerveilleWidget : public QPushButton
{
    Q_OBJECT

public:
    explicit MerveilleWidget(Merveille* m);
    ~MerveilleWidget();
    Merveille* getPtrMerveille() {return ptrMerveille;}
    QLabel* getImageLabel() {return imageLabel;}
    QLabel* getEmplacementLabel() {return emplacementLabel;}
    void setEmplacementLabel(QLabel* e);
    void setImage();

private:
    Ui::MerveilleWidget *ui;
    Merveille* ptrMerveille;
    QLabel* imageLabel;
    QLabel* emplacementLabel = nullptr;

signals:
    void selected(MerveilleWidget*);

};

#endif // MERVEILLEWIDGET_H
