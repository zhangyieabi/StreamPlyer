/********************************************************************************
** Form generated from reading UI file 'playermainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERMAINWIN_H
#define UI_PLAYERMAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerMainWin
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *PlayerMainWin)
    {
        if (PlayerMainWin->objectName().isEmpty())
            PlayerMainWin->setObjectName(QStringLiteral("PlayerMainWin"));
        PlayerMainWin->resize(122, 444);
        PlayerMainWin->setMouseTracking(true);
        PlayerMainWin->setLayoutDirection(Qt::LeftToRight);
        PlayerMainWin->setAutoFillBackground(true);
        centralWidget = new QWidget(PlayerMainWin);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PlayerMainWin->setCentralWidget(centralWidget);

        retranslateUi(PlayerMainWin);

        QMetaObject::connectSlotsByName(PlayerMainWin);
    } // setupUi

    void retranslateUi(QMainWindow *PlayerMainWin)
    {
        PlayerMainWin->setWindowTitle(QApplication::translate("PlayerMainWin", "PlayerMainWin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerMainWin: public Ui_PlayerMainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERMAINWIN_H
