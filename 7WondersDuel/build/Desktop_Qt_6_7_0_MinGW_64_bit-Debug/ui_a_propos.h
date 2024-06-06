/********************************************************************************
** Form generated from reading UI file 'a_propos.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_A_PROPOS_H
#define UI_A_PROPOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_A_propos
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QDialog *A_propos)
    {
        if (A_propos->objectName().isEmpty())
            A_propos->setObjectName("A_propos");
        A_propos->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(A_propos->sizePolicy().hasHeightForWidth());
        A_propos->setSizePolicy(sizePolicy);
        A_propos->setMinimumSize(QSize(400, 300));
        textBrowser = new QTextBrowser(A_propos);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(0, 0, 400, 300));
        textBrowser->setMinimumSize(QSize(400, 300));
        textBrowser->setMaximumSize(QSize(400, 300));

        retranslateUi(A_propos);

        QMetaObject::connectSlotsByName(A_propos);
    } // setupUi

    void retranslateUi(QDialog *A_propos)
    {
        A_propos->setWindowTitle(QCoreApplication::translate("A_propos", "Dialog", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("A_propos", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Cette application, r\303\251alis\303\251e dans le cadre du projet de LO21 au printemps 2024 \303\240 l'UTC, propose une impl\303\251mentation du jeu </span><span style=\" font-size:14pt; font-weight:700;\">7 Wonders Duel</span><span style=\" font-size:14pt;\"> sur ordinateur. </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-rig"
                        "ht:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Les membres du projet sont : </span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" font-size:14pt;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Chlo\303\251 TAUREL </li>\n"
"<li style=\" font-size:14pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Nadji BENSALEM </li>\n"
"<li style=\" font-size:14pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Joshua NANCEY </li>\n"
"<li style=\" font-size:14pt;\" style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Valentin RONSSERAY </li></ul></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class A_propos: public Ui_A_propos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_A_PROPOS_H
