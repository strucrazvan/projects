/********************************************************************************
** Form generated from reading UI file 'WatchListWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WATCHLISTWIDGET_H
#define UI_WATCHLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WatchListWidget
{
public:
    QTableView *tableView;

    void setupUi(QWidget *WatchListWidget)
    {
        if (WatchListWidget->objectName().isEmpty())
            WatchListWidget->setObjectName(QStringLiteral("WatchListWidget"));
        WatchListWidget->resize(841, 555);
        tableView = new QTableView(WatchListWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 30, 721, 471));

        retranslateUi(WatchListWidget);

        QMetaObject::connectSlotsByName(WatchListWidget);
    } // setupUi

    void retranslateUi(QWidget *WatchListWidget)
    {
        WatchListWidget->setWindowTitle(QApplication::translate("WatchListWidget", "WatchListWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WatchListWidget: public Ui_WatchListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATCHLISTWIDGET_H
