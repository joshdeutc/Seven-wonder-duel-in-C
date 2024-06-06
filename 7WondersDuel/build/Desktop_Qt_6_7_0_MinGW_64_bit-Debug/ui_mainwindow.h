/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter_l_application;
    QAction *actionAller_au_menu_principal;
    QAction *action_propos;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_JvsJ;
    QPushButton *pushButton_JvsIA;
    QPushButton *pushButton_IAvsIA;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_Quitter;
    QWidget *page_2;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuAide;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        actionQuitter_l_application = new QAction(MainWindow);
        actionQuitter_l_application->setObjectName("actionQuitter_l_application");
        actionAller_au_menu_principal = new QAction(MainWindow);
        actionAller_au_menu_principal->setObjectName("actionAller_au_menu_principal");
        actionAller_au_menu_principal->setCheckable(false);
        action_propos = new QAction(MainWindow);
        action_propos->setObjectName("action_propos");
        action_propos->setMenuRole(QAction::AboutQtRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1280, 720));
        page = new QWidget();
        page->setObjectName("page");
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(410, 50, 500, 251));
        label->setSizeIncrement(QSize(0, 0));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/7WondersDuelLogo.png")));
        label->setScaledContents(true);
        verticalLayoutWidget = new QWidget(page);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(450, 340, 420, 241));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_JvsJ = new QPushButton(verticalLayoutWidget);
        pushButton_JvsJ->setObjectName("pushButton_JvsJ");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_JvsJ->sizePolicy().hasHeightForWidth());
        pushButton_JvsJ->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setPointSize(16);
        pushButton_JvsJ->setFont(font);

        verticalLayout_3->addWidget(pushButton_JvsJ);

        pushButton_JvsIA = new QPushButton(verticalLayoutWidget);
        pushButton_JvsIA->setObjectName("pushButton_JvsIA");
        sizePolicy.setHeightForWidth(pushButton_JvsIA->sizePolicy().hasHeightForWidth());
        pushButton_JvsIA->setSizePolicy(sizePolicy);
        pushButton_JvsIA->setFont(font);

        verticalLayout_3->addWidget(pushButton_JvsIA);

        pushButton_IAvsIA = new QPushButton(verticalLayoutWidget);
        pushButton_IAvsIA->setObjectName("pushButton_IAvsIA");
        sizePolicy.setHeightForWidth(pushButton_IAvsIA->sizePolicy().hasHeightForWidth());
        pushButton_IAvsIA->setSizePolicy(sizePolicy);
        pushButton_IAvsIA->setFont(font);

        verticalLayout_3->addWidget(pushButton_IAvsIA);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        pushButton_Quitter = new QPushButton(verticalLayoutWidget);
        pushButton_Quitter->setObjectName("pushButton_Quitter");
        sizePolicy.setHeightForWidth(pushButton_Quitter->sizePolicy().hasHeightForWidth());
        pushButton_Quitter->setSizePolicy(sizePolicy);
        pushButton_Quitter->setFont(font);

        verticalLayout_3->addWidget(pushButton_Quitter);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 21));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName("menuFichier");
        menuAide = new QMenu(menubar);
        menuAide->setObjectName("menuAide");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionAller_au_menu_principal);
        menuFichier->addAction(actionQuitter_l_application);
        menuAide->addAction(action_propos);

        retranslateUi(MainWindow);
        QObject::connect(actionQuitter_l_application, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));
        QObject::connect(pushButton_Quitter, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));
        QObject::connect(pushButton_JvsJ, &QPushButton::clicked, stackedWidget, qOverload<>(&QStackedWidget::update));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuitter_l_application->setText(QCoreApplication::translate("MainWindow", "Quitter l'application", nullptr));
        actionAller_au_menu_principal->setText(QCoreApplication::translate("MainWindow", "Aller au menu principal", nullptr));
        action_propos->setText(QCoreApplication::translate("MainWindow", "\303\200 propos", nullptr));
        label->setText(QString());
        pushButton_JvsJ->setText(QCoreApplication::translate("MainWindow", "Joueur vs Joueur", nullptr));
        pushButton_JvsIA->setText(QCoreApplication::translate("MainWindow", "Joueur vs IA", nullptr));
        pushButton_IAvsIA->setText(QCoreApplication::translate("MainWindow", "IA vs IA", nullptr));
        pushButton_Quitter->setText(QCoreApplication::translate("MainWindow", "Quitter l'application", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("MainWindow", "Fichier", nullptr));
        menuAide->setTitle(QCoreApplication::translate("MainWindow", "Aide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
