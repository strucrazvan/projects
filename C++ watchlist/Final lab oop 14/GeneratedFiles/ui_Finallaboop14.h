/********************************************************************************
** Form generated from reading UI file 'Finallaboop14.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINALLABOOP14_H
#define UI_FINALLABOOP14_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
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

class Ui_Finallaboop14Class
{
public:
    QWidget *centralWidget;
    QPushButton *printFileButton;
    QPushButton *nextButton;
    QPushButton *addToWatchListButton;
    QLabel *errorLabel;
    QComboBox *showComboBox;
    QPushButton *playButton;
    QListWidget *tutorialsList;
    QLineEdit *fileNameLineEdit;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QPushButton *addButton;
    QLabel *presenterLabel;
    QLineEdit *presenterLineEdit;
    QPushButton *removeButton;
    QLabel *minutesLabel;
    QLineEdit *minutesLineEdit;
    QPushButton *updateButton;
    QLabel *secondsLabel;
    QLineEdit *secondsLineEdit;
    QLineEdit *titleUpdateLineEdit;
    QLabel *likeLabel;
    QLineEdit *likesLineEdit;
    QPushButton *filterButton;
    QLineEdit *presenterFilterLineEdit;
    QLabel *linkLabel;
    QLineEdit *linkLineEdit;
    QListWidget *watchList;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QPushButton *undoWatchListButton;
    QPushButton *redoWatchListButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Finallaboop14Class)
    {
        if (Finallaboop14Class->objectName().isEmpty())
            Finallaboop14Class->setObjectName(QStringLiteral("Finallaboop14Class"));
        Finallaboop14Class->resize(1239, 761);
        centralWidget = new QWidget(Finallaboop14Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        printFileButton = new QPushButton(centralWidget);
        printFileButton->setObjectName(QStringLiteral("printFileButton"));
        printFileButton->setGeometry(QRect(750, 400, 131, 31));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(14);
        printFileButton->setFont(font);
        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setGeometry(QRect(800, 350, 91, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(16);
        nextButton->setFont(font1);
        addToWatchListButton = new QPushButton(centralWidget);
        addToWatchListButton->setObjectName(QStringLiteral("addToWatchListButton"));
        addToWatchListButton->setGeometry(QRect(560, 130, 75, 61));
        QFont font2;
        font2.setFamily(QStringLiteral("Comic Sans MS"));
        font2.setPointSize(48);
        addToWatchListButton->setFont(font2);
        errorLabel = new QLabel(centralWidget);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setGeometry(QRect(0, 610, 801, 81));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 63, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        errorLabel->setPalette(palette);
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        errorLabel->setFont(font3);
        errorLabel->setCursor(QCursor(Qt::ArrowCursor));
        showComboBox = new QComboBox(centralWidget);
        showComboBox->addItem(QString());
        showComboBox->addItem(QString());
        showComboBox->setObjectName(QStringLiteral("showComboBox"));
        showComboBox->setGeometry(QRect(10, 10, 541, 22));
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(690, 350, 91, 31));
        playButton->setFont(font1);
        tutorialsList = new QListWidget(centralWidget);
        tutorialsList->setObjectName(QStringLiteral("tutorialsList"));
        tutorialsList->setGeometry(QRect(10, 30, 541, 311));
        fileNameLineEdit = new QLineEdit(centralWidget);
        fileNameLineEdit->setObjectName(QStringLiteral("fileNameLineEdit"));
        fileNameLineEdit->setGeometry(QRect(890, 400, 201, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Comic Sans MS"));
        font4.setPointSize(12);
        fileNameLineEdit->setFont(font4);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 370, 548, 224));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        titleLabel = new QLabel(layoutWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setFont(font);

        gridLayout->addWidget(titleLabel, 0, 0, 1, 3);

        titleLineEdit = new QLineEdit(layoutWidget);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));
        titleLineEdit->setFont(font4);

        gridLayout->addWidget(titleLineEdit, 0, 3, 1, 2);

        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setFont(font);

        gridLayout->addWidget(addButton, 0, 5, 2, 1);

        presenterLabel = new QLabel(layoutWidget);
        presenterLabel->setObjectName(QStringLiteral("presenterLabel"));
        presenterLabel->setFont(font);

        gridLayout->addWidget(presenterLabel, 1, 0, 2, 4);

        presenterLineEdit = new QLineEdit(layoutWidget);
        presenterLineEdit->setObjectName(QStringLiteral("presenterLineEdit"));
        presenterLineEdit->setFont(font4);

        gridLayout->addWidget(presenterLineEdit, 2, 4, 1, 1);

        removeButton = new QPushButton(layoutWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setFont(font);

        gridLayout->addWidget(removeButton, 2, 5, 2, 1);

        minutesLabel = new QLabel(layoutWidget);
        minutesLabel->setObjectName(QStringLiteral("minutesLabel"));
        minutesLabel->setFont(font);

        gridLayout->addWidget(minutesLabel, 3, 0, 2, 2);

        minutesLineEdit = new QLineEdit(layoutWidget);
        minutesLineEdit->setObjectName(QStringLiteral("minutesLineEdit"));
        minutesLineEdit->setFont(font4);

        gridLayout->addWidget(minutesLineEdit, 3, 2, 1, 3);

        updateButton = new QPushButton(layoutWidget);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        updateButton->setFont(font);

        gridLayout->addWidget(updateButton, 4, 5, 2, 1);

        secondsLabel = new QLabel(layoutWidget);
        secondsLabel->setObjectName(QStringLiteral("secondsLabel"));
        secondsLabel->setFont(font);

        gridLayout->addWidget(secondsLabel, 5, 0, 1, 1);

        secondsLineEdit = new QLineEdit(layoutWidget);
        secondsLineEdit->setObjectName(QStringLiteral("secondsLineEdit"));
        secondsLineEdit->setFont(font4);

        gridLayout->addWidget(secondsLineEdit, 5, 1, 1, 4);

        titleUpdateLineEdit = new QLineEdit(layoutWidget);
        titleUpdateLineEdit->setObjectName(QStringLiteral("titleUpdateLineEdit"));
        titleUpdateLineEdit->setFont(font4);

        gridLayout->addWidget(titleUpdateLineEdit, 5, 6, 1, 1);

        likeLabel = new QLabel(layoutWidget);
        likeLabel->setObjectName(QStringLiteral("likeLabel"));
        likeLabel->setFont(font);

        gridLayout->addWidget(likeLabel, 6, 0, 2, 1);

        likesLineEdit = new QLineEdit(layoutWidget);
        likesLineEdit->setObjectName(QStringLiteral("likesLineEdit"));
        likesLineEdit->setFont(font4);

        gridLayout->addWidget(likesLineEdit, 6, 1, 1, 4);

        filterButton = new QPushButton(layoutWidget);
        filterButton->setObjectName(QStringLiteral("filterButton"));
        filterButton->setFont(font);

        gridLayout->addWidget(filterButton, 6, 5, 3, 1);

        presenterFilterLineEdit = new QLineEdit(layoutWidget);
        presenterFilterLineEdit->setObjectName(QStringLiteral("presenterFilterLineEdit"));
        presenterFilterLineEdit->setFont(font4);

        gridLayout->addWidget(presenterFilterLineEdit, 7, 6, 2, 1);

        linkLabel = new QLabel(layoutWidget);
        linkLabel->setObjectName(QStringLiteral("linkLabel"));
        linkLabel->setFont(font);

        gridLayout->addWidget(linkLabel, 8, 0, 1, 2);

        linkLineEdit = new QLineEdit(layoutWidget);
        linkLineEdit->setObjectName(QStringLiteral("linkLineEdit"));
        linkLineEdit->setFont(font4);

        gridLayout->addWidget(linkLineEdit, 8, 2, 1, 3);

        watchList = new QListWidget(centralWidget);
        watchList->setObjectName(QStringLiteral("watchList"));
        watchList->setGeometry(QRect(650, 30, 541, 311));
        watchList->setSelectionMode(QAbstractItemView::SingleSelection);
        undoButton = new QPushButton(centralWidget);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setGeometry(QRect(550, 370, 75, 34));
        undoButton->setFont(font);
        redoButton = new QPushButton(centralWidget);
        redoButton->setObjectName(QStringLiteral("redoButton"));
        redoButton->setGeometry(QRect(550, 410, 75, 34));
        redoButton->setFont(font);
        undoWatchListButton = new QPushButton(centralWidget);
        undoWatchListButton->setObjectName(QStringLiteral("undoWatchListButton"));
        undoWatchListButton->setGeometry(QRect(1120, 360, 75, 34));
        undoWatchListButton->setFont(font);
        redoWatchListButton = new QPushButton(centralWidget);
        redoWatchListButton->setObjectName(QStringLiteral("redoWatchListButton"));
        redoWatchListButton->setGeometry(QRect(1120, 400, 75, 34));
        redoWatchListButton->setFont(font);
        Finallaboop14Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Finallaboop14Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1239, 21));
        Finallaboop14Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Finallaboop14Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Finallaboop14Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Finallaboop14Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Finallaboop14Class->setStatusBar(statusBar);

        retranslateUi(Finallaboop14Class);

        QMetaObject::connectSlotsByName(Finallaboop14Class);
    } // setupUi

    void retranslateUi(QMainWindow *Finallaboop14Class)
    {
        Finallaboop14Class->setWindowTitle(QApplication::translate("Finallaboop14Class", "Finallaboop14", nullptr));
        printFileButton->setText(QApplication::translate("Finallaboop14Class", "Save to file", nullptr));
        nextButton->setText(QApplication::translate("Finallaboop14Class", "Next", nullptr));
        addToWatchListButton->setText(QApplication::translate("Finallaboop14Class", ">", nullptr));
        errorLabel->setText(QApplication::translate("Finallaboop14Class", "Result of operation:", nullptr));
        showComboBox->setItemText(0, QApplication::translate("Finallaboop14Class", "Detailed", nullptr));
        showComboBox->setItemText(1, QApplication::translate("Finallaboop14Class", "Short", nullptr));

        playButton->setText(QApplication::translate("Finallaboop14Class", "Play", nullptr));
        fileNameLineEdit->setText(QApplication::translate("Finallaboop14Class", "filename . csv/html", nullptr));
        titleLabel->setText(QApplication::translate("Finallaboop14Class", "Title", nullptr));
        addButton->setText(QApplication::translate("Finallaboop14Class", "Add", nullptr));
        presenterLabel->setText(QApplication::translate("Finallaboop14Class", "Presenter", nullptr));
        removeButton->setText(QApplication::translate("Finallaboop14Class", "Remove", nullptr));
        minutesLabel->setText(QApplication::translate("Finallaboop14Class", "Min", nullptr));
        updateButton->setText(QApplication::translate("Finallaboop14Class", "Update", nullptr));
        secondsLabel->setText(QApplication::translate("Finallaboop14Class", "Sec", nullptr));
        titleUpdateLineEdit->setText(QApplication::translate("Finallaboop14Class", "old title", nullptr));
        likeLabel->setText(QApplication::translate("Finallaboop14Class", "Likes", nullptr));
        filterButton->setText(QApplication::translate("Finallaboop14Class", "Filter", nullptr));
        presenterFilterLineEdit->setText(QApplication::translate("Finallaboop14Class", "presenter", nullptr));
        linkLabel->setText(QApplication::translate("Finallaboop14Class", "Link", nullptr));
        undoButton->setText(QApplication::translate("Finallaboop14Class", "Undo", nullptr));
        redoButton->setText(QApplication::translate("Finallaboop14Class", "Redo", nullptr));
        undoWatchListButton->setText(QApplication::translate("Finallaboop14Class", "Undo", nullptr));
        redoWatchListButton->setText(QApplication::translate("Finallaboop14Class", "Redo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Finallaboop14Class: public Ui_Finallaboop14Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINALLABOOP14_H
