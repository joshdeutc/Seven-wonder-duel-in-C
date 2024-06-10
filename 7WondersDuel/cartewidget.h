#ifndef CARTEWIDGET_H
#define CARTEWIDGET_H

#include <QWidget>

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
