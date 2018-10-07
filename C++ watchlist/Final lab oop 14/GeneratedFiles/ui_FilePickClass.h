/********************************************************************************
** Form generated from reading UI file 'FilePickClass.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEPICKCLASS_H
#define UI_FILEPICKCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilePickClass
{
public:
    QPushButton *htmlButton;
    QLabel *titlelabel;
    QPushButton *csvButton;

    void setupUi(QWidget *FilePickClass)
    {
        if (FilePickClass->objectName().isEmpty())
            FilePickClass->setObjectName(QStringLiteral("FilePickClass"));
        FilePickClass->resize(782, 435);
        htmlButton = new QPushButton(FilePickClass);
        htmlButton->setObjectName(QStringLiteral("htmlButton"));
        htmlButton->setGeometry(QRect(380, 100, 291, 221));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(72);
        htmlButton->setFont(font);
        titlelabel = new QLabel(FilePickClass);
        titlelabel->setObjectName(QStringLiteral("titlelabel"));
        titlelabel->setGeometry(QRect(20, 10, 711, 111));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(36);
        titlelabel->setFont(font1);
        csvButton = new QPushButton(FilePickClass);
        csvButton->setObjectName(QStringLiteral("csvButton"));
        csvButton->setGeometry(QRect(30, 100, 291, 221));
        csvButton->setFont(font);

        retranslateUi(FilePickClass);

        QMetaObject::connectSlotsByName(FilePickClass);
    } // setupUi

    void retranslateUi(QWidget *FilePickClass)
    {
        FilePickClass->setWindowTitle(QApplication::translate("FilePickClass", "FilePickClass", nullptr));
        htmlButton->setText(QApplication::translate("FilePickClass", "HTML", nullptr));
        titlelabel->setText(QApplication::translate("FilePickClass", "Pick the type of file to print in", nullptr));
        csvButton->setText(QApplication::translate("FilePickClass", "CSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilePickClass: public Ui_FilePickClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEPICKCLASS_H
