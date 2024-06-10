#ifndef JETONPROGRESWIDGET_H
#define JETONPROGRESWIDGET_H

#include "carte_bat_merv.h"

#include <QWidget>
#include <QLabel>

namespace Ui {
class JetonProgresWidget;
}

class JetonProgresWidget : public QWidget
{
    Q_OBJECT

public:
    explicit JetonProgresWidget(JetonProgres* j = nullptr);
    ~JetonProgresWidget();
    JetonProgres* getjetonProgres() {return ptrJetonProgres;}
    void setPixmap();
private:
    Ui::JetonProgresWidget *ui;
    JetonProgres* ptrJetonProgres;
    QLabel* imageLabel;
};

#endif // JETONPROGRESWIDGET_H
