/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *Read;
    QPushButton *delete_item;
    QPushButton *setText;
    QPushButton *addTrapezoid;
    QPushButton *addRect;
    QPushButton *addNode;
    QPushButton *addEllipse;
    QPushButton *connect;
    QLineEdit *textToSet;
    QGraphicsView *graphicsView;
    QLineEdit *fileToRead;
    QPushButton *addRomb;
    QPushButton *save;
    QLineEdit *fileToSave;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 692);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Read = new QPushButton(centralwidget);
        Read->setObjectName(QString::fromUtf8("Read"));

        gridLayout->addWidget(Read, 9, 3, 1, 1);

        delete_item = new QPushButton(centralwidget);
        delete_item->setObjectName(QString::fromUtf8("delete_item"));

        gridLayout->addWidget(delete_item, 10, 3, 1, 1);

        setText = new QPushButton(centralwidget);
        setText->setObjectName(QString::fromUtf8("setText"));

        gridLayout->addWidget(setText, 8, 3, 1, 1);

        addTrapezoid = new QPushButton(centralwidget);
        addTrapezoid->setObjectName(QString::fromUtf8("addTrapezoid"));

        gridLayout->addWidget(addTrapezoid, 2, 3, 1, 1);

        addRect = new QPushButton(centralwidget);
        addRect->setObjectName(QString::fromUtf8("addRect"));

        gridLayout->addWidget(addRect, 3, 2, 1, 1);

        addNode = new QPushButton(centralwidget);
        addNode->setObjectName(QString::fromUtf8("addNode"));

        gridLayout->addWidget(addNode, 4, 2, 1, 1);

        addEllipse = new QPushButton(centralwidget);
        addEllipse->setObjectName(QString::fromUtf8("addEllipse"));

        gridLayout->addWidget(addEllipse, 3, 3, 1, 1);

        connect = new QPushButton(centralwidget);
        connect->setObjectName(QString::fromUtf8("connect"));

        gridLayout->addWidget(connect, 10, 2, 1, 1);

        textToSet = new QLineEdit(centralwidget);
        textToSet->setObjectName(QString::fromUtf8("textToSet"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textToSet->sizePolicy().hasHeightForWidth());
        textToSet->setSizePolicy(sizePolicy);

        gridLayout->addWidget(textToSet, 8, 2, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 6, 2, 1, 2);

        fileToRead = new QLineEdit(centralwidget);
        fileToRead->setObjectName(QString::fromUtf8("fileToRead"));
        sizePolicy.setHeightForWidth(fileToRead->sizePolicy().hasHeightForWidth());
        fileToRead->setSizePolicy(sizePolicy);

        gridLayout->addWidget(fileToRead, 9, 2, 1, 1);

        addRomb = new QPushButton(centralwidget);
        addRomb->setObjectName(QString::fromUtf8("addRomb"));

        gridLayout->addWidget(addRomb, 2, 2, 1, 1);

        save = new QPushButton(centralwidget);
        save->setObjectName(QString::fromUtf8("save"));

        gridLayout->addWidget(save, 7, 3, 1, 1);

        fileToSave = new QLineEdit(centralwidget);
        fileToSave->setObjectName(QString::fromUtf8("fileToSave"));
        sizePolicy.setHeightForWidth(fileToSave->sizePolicy().hasHeightForWidth());
        fileToSave->setSizePolicy(sizePolicy);

        gridLayout->addWidget(fileToSave, 7, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Read->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
        delete_item->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        setText->setText(QCoreApplication::translate("MainWindow", "set Text", nullptr));
        addTrapezoid->setText(QCoreApplication::translate("MainWindow", "add Trapezoid", nullptr));
        addRect->setText(QCoreApplication::translate("MainWindow", "add Rect", nullptr));
        addNode->setText(QCoreApplication::translate("MainWindow", "add Node", nullptr));
        addEllipse->setText(QCoreApplication::translate("MainWindow", "add Ellipse", nullptr));
        connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        addRomb->setText(QCoreApplication::translate("MainWindow", "add Romb", nullptr));
        save->setText(QCoreApplication::translate("MainWindow", "save as", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
