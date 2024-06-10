#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "jeu.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_JvsJ_clicked();

    void on_pushButton_JvsIA_clicked();

    void on_pushButton_IAvsIA_clicked();

    void on_actionAller_au_menu_principal_triggered();

    void on_action_propos_triggered();

private:
    Ui::MainWindow *ui;
    Jeu* jeu;
};
#endif // MAINWINDOW_H
