/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *add_File;
    QAction *save_as_pdf;
    QAction *save_as_jpg;
    QAction *actionPT1000_Data;
    QAction *actioncan_add_other_stuff_in_future;
    QCustomPlot *customPlot;
    QMenuBar *menuBar;
    QMenu *menuAdd_File;
    QMenu *menuSaveFile;
    QMenu *menuView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QStringLiteral("snowflake.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        add_File = new QAction(MainWindow);
        add_File->setObjectName(QStringLiteral("add_File"));
        save_as_pdf = new QAction(MainWindow);
        save_as_pdf->setObjectName(QStringLiteral("save_as_pdf"));
        save_as_jpg = new QAction(MainWindow);
        save_as_jpg->setObjectName(QStringLiteral("save_as_jpg"));
        actionPT1000_Data = new QAction(MainWindow);
        actionPT1000_Data->setObjectName(QStringLiteral("actionPT1000_Data"));
        actioncan_add_other_stuff_in_future = new QAction(MainWindow);
        actioncan_add_other_stuff_in_future->setObjectName(QStringLiteral("actioncan_add_other_stuff_in_future"));
        customPlot = new QCustomPlot(MainWindow);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        MainWindow->setCentralWidget(customPlot);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 31));
        menuAdd_File = new QMenu(menuBar);
        menuAdd_File->setObjectName(QStringLiteral("menuAdd_File"));
        menuSaveFile = new QMenu(menuAdd_File);
        menuSaveFile->setObjectName(QStringLiteral("menuSaveFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuAdd_File->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuAdd_File->addAction(add_File);
        menuAdd_File->addAction(menuSaveFile->menuAction());
        menuSaveFile->addAction(save_as_pdf);
        menuSaveFile->addAction(save_as_jpg);
        menuView->addAction(actionPT1000_Data);
        menuView->addAction(actioncan_add_other_stuff_in_future);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ISM Graphing", Q_NULLPTR));
        add_File->setText(QApplication::translate("MainWindow", "Add Data", Q_NULLPTR));
        save_as_pdf->setText(QApplication::translate("MainWindow", "Save as .pdf", Q_NULLPTR));
        save_as_jpg->setText(QApplication::translate("MainWindow", "Save as .jpg", Q_NULLPTR));
        actionPT1000_Data->setText(QApplication::translate("MainWindow", "PT1000 Data", Q_NULLPTR));
        actioncan_add_other_stuff_in_future->setText(QApplication::translate("MainWindow", "can add other stuff in future", Q_NULLPTR));
        menuAdd_File->setTitle(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
        menuSaveFile->setTitle(QApplication::translate("MainWindow", "Save Graph", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
