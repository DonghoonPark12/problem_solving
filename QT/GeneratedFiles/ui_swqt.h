/********************************************************************************
** Form generated from reading UI file 'swqt.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWQT_H
#define UI_SWQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_swQTClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *swQTClass)
    {
        if (swQTClass->objectName().isEmpty())
            swQTClass->setObjectName(QStringLiteral("swQTClass"));
        swQTClass->resize(600, 400);
        centralWidget = new QWidget(swQTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(420, 240, 111, 41));
        swQTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(swQTClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        swQTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(swQTClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        swQTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(swQTClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        swQTClass->setStatusBar(statusBar);

        retranslateUi(swQTClass);

        QMetaObject::connectSlotsByName(swQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *swQTClass)
    {
        swQTClass->setWindowTitle(QApplication::translate("swQTClass", "swQT", Q_NULLPTR));
        pushButton->setText(QApplication::translate("swQTClass", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class swQTClass: public Ui_swQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWQT_H
