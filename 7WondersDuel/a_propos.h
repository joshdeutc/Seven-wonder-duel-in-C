#ifndef A_PROPOS_H
#define A_PROPOS_H

#include <QDialog>

namespace Ui {
class A_propos;
}

class A_propos : public QDialog
{
    Q_OBJECT

public:
    explicit A_propos(QWidget *parent = nullptr);
    ~A_propos();

private:
    Ui::A_propos *ui;
};

#endif // A_PROPOS_H
