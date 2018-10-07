/********************************************************************************
** Form generated from reading UI file 'SDAfinalproject.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SDAFINALPROJECT_H
#define UI_SDAFINALPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SDAfinalprojectClass
{
public:
    QWidget *centralWidget;
    QListWidget *multiMapElementsListWidget;
    QLineEdit *keyLineEdit;
    QLineEdit *valueLineEdit;
    QPushButton *addButton;
    QPushButton *removeButton;
    QLabel *errorLabel;
    QLabel *emptyPositionsLabel;
    QLabel *pairLabel;
    QPushButton *searchButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SDAfinalprojectClass)
    {
        if (SDAfinalprojectClass->objectName().isEmpty())
            SDAfinalprojectClass->setObjectName(QStringLiteral("SDAfinalprojectClass"));
        SDAfinalprojectClass->resize(600, 517);
        centralWidget = new QWidget(SDAfinalprojectClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        multiMapElementsListWidget = new QListWidget(centralWidget);
        multiMapElementsListWidget->setObjectName(QStringLiteral("multiMapElementsListWidget"));
        multiMapElementsListWidget->setGeometry(QRect(10, 60, 321, 311));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(12);
        multiMapElementsListWidget->setFont(font);
        keyLineEdit = new QLineEdit(centralWidget);
        keyLineEdit->setObjectName(QStringLiteral("keyLineEdit"));
        keyLineEdit->setGeometry(QRect(410, 30, 121, 31));
        keyLineEdit->setFont(font);
        valueLineEdit = new QLineEdit(centralWidget);
        valueLineEdit->setObjectName(QStringLiteral("valueLineEdit"));
        valueLineEdit->setGeometry(QRect(410, 80, 121, 31));
        valueLineEdit->setFont(font);
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(410, 130, 121, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(16);
        addButton->setFont(font1);
        removeButton = new QPushButton(centralWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(410, 200, 121, 51));
        removeButton->setFont(font1);
        errorLabel = new QLabel(centralWidget);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setGeometry(QRect(350, 330, 231, 71));
        QFont font2;
        font2.setPointSize(12);
        errorLabel->setFont(font2);
        emptyPositionsLabel = new QLabel(centralWidget);
        emptyPositionsLabel->setObjectName(QStringLiteral("emptyPositionsLabel"));
        emptyPositionsLabel->setGeometry(QRect(10, 380, 371, 51));
        QFont font3;
        font3.setFamily(QStringLiteral("Comic Sans MS"));
        font3.setPointSize(14);
        emptyPositionsLabel->setFont(font3);
        pairLabel = new QLabel(centralWidget);
        pairLabel->setObjectName(QStringLiteral("pairLabel"));
        pairLabel->setGeometry(QRect(10, 10, 371, 51));
        pairLabel->setFont(font3);
        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(410, 260, 121, 51));
        searchButton->setFont(font1);
        SDAfinalprojectClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SDAfinalprojectClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        SDAfinalprojectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SDAfinalprojectClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SDAfinalprojectClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SDAfinalprojectClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SDAfinalprojectClass->setStatusBar(statusBar);

        retranslateUi(SDAfinalprojectClass);

        QMetaObject::connectSlotsByName(SDAfinalprojectClass);
    } // setupUi

    void retranslateUi(QMainWindow *SDAfinalprojectClass)
    {
        SDAfinalprojectClass->setWindowTitle(QApplication::translate("SDAfinalprojectClass", "SDAfinalproject", nullptr));
        addButton->setText(QApplication::translate("SDAfinalprojectClass", "Add", nullptr));
        removeButton->setText(QApplication::translate("SDAfinalprojectClass", "Remove", nullptr));
        errorLabel->setText(QApplication::translate("SDAfinalprojectClass", "Message of operaition", nullptr));
        emptyPositionsLabel->setText(QApplication::translate("SDAfinalprojectClass", "Empty positions: ", nullptr));
        pairLabel->setText(QApplication::translate("SDAfinalprojectClass", "Pair: <student,class>", nullptr));
        searchButton->setText(QApplication::translate("SDAfinalprojectClass", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SDAfinalprojectClass: public Ui_SDAfinalprojectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDAFINALPROJECT_H
