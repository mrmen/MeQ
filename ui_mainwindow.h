/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionQuit;
    QAction *actionSave;
    QAction *actionLaTeX;
    QAction *actionBash;
    QAction *actionMarkdown;
    QAction *actionOrg_mode;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *MainLayout;
    QHBoxLayout *ButtonLayout;
    QPushButton *dollarButton;
    QPushButton *backslashButton;
    QPushButton *laccolButton;
    QPushButton *raccolButton;
    QPushButton *lparentButton;
    QPushButton *rparentButton;
    QPushButton *lbracketButton;
    QPushButton *rbracketButton;
    QPushButton *aboveButton;
    QPushButton *underButton;
    QPushButton *beginEndButton;
    QTextEdit *editor;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menu;
    QMenu *menuLexer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(854, 577);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLaTeX = new QAction(MainWindow);
        actionLaTeX->setObjectName(QString::fromUtf8("actionLaTeX"));
        actionBash = new QAction(MainWindow);
        actionBash->setObjectName(QString::fromUtf8("actionBash"));
        actionMarkdown = new QAction(MainWindow);
        actionMarkdown->setObjectName(QString::fromUtf8("actionMarkdown"));
        actionOrg_mode = new QAction(MainWindow);
        actionOrg_mode->setObjectName(QString::fromUtf8("actionOrg_mode"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        MainLayout = new QVBoxLayout();
        MainLayout->setSpacing(6);
        MainLayout->setObjectName(QString::fromUtf8("MainLayout"));
        ButtonLayout = new QHBoxLayout();
        ButtonLayout->setSpacing(6);
        ButtonLayout->setObjectName(QString::fromUtf8("ButtonLayout"));
        ButtonLayout->setSizeConstraint(QLayout::SetNoConstraint);
        dollarButton = new QPushButton(centralWidget);
        dollarButton->setObjectName(QString::fromUtf8("dollarButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dollarButton->sizePolicy().hasHeightForWidth());
        dollarButton->setSizePolicy(sizePolicy);
        dollarButton->setMinimumSize(QSize(50, 50));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        dollarButton->setFont(font);

        ButtonLayout->addWidget(dollarButton);

        backslashButton = new QPushButton(centralWidget);
        backslashButton->setObjectName(QString::fromUtf8("backslashButton"));
        sizePolicy.setHeightForWidth(backslashButton->sizePolicy().hasHeightForWidth());
        backslashButton->setSizePolicy(sizePolicy);
        backslashButton->setMinimumSize(QSize(50, 50));
        backslashButton->setFont(font);

        ButtonLayout->addWidget(backslashButton);

        laccolButton = new QPushButton(centralWidget);
        laccolButton->setObjectName(QString::fromUtf8("laccolButton"));
        sizePolicy.setHeightForWidth(laccolButton->sizePolicy().hasHeightForWidth());
        laccolButton->setSizePolicy(sizePolicy);
        laccolButton->setMinimumSize(QSize(50, 50));
        laccolButton->setFont(font);

        ButtonLayout->addWidget(laccolButton);

        raccolButton = new QPushButton(centralWidget);
        raccolButton->setObjectName(QString::fromUtf8("raccolButton"));
        sizePolicy.setHeightForWidth(raccolButton->sizePolicy().hasHeightForWidth());
        raccolButton->setSizePolicy(sizePolicy);
        raccolButton->setMinimumSize(QSize(50, 50));
        raccolButton->setFont(font);

        ButtonLayout->addWidget(raccolButton);

        lparentButton = new QPushButton(centralWidget);
        lparentButton->setObjectName(QString::fromUtf8("lparentButton"));
        sizePolicy.setHeightForWidth(lparentButton->sizePolicy().hasHeightForWidth());
        lparentButton->setSizePolicy(sizePolicy);
        lparentButton->setMinimumSize(QSize(50, 50));
        lparentButton->setFont(font);

        ButtonLayout->addWidget(lparentButton);

        rparentButton = new QPushButton(centralWidget);
        rparentButton->setObjectName(QString::fromUtf8("rparentButton"));
        sizePolicy.setHeightForWidth(rparentButton->sizePolicy().hasHeightForWidth());
        rparentButton->setSizePolicy(sizePolicy);
        rparentButton->setMinimumSize(QSize(50, 50));
        rparentButton->setFont(font);

        ButtonLayout->addWidget(rparentButton);

        lbracketButton = new QPushButton(centralWidget);
        lbracketButton->setObjectName(QString::fromUtf8("lbracketButton"));
        sizePolicy.setHeightForWidth(lbracketButton->sizePolicy().hasHeightForWidth());
        lbracketButton->setSizePolicy(sizePolicy);
        lbracketButton->setMinimumSize(QSize(50, 50));
        lbracketButton->setFont(font);

        ButtonLayout->addWidget(lbracketButton);

        rbracketButton = new QPushButton(centralWidget);
        rbracketButton->setObjectName(QString::fromUtf8("rbracketButton"));
        sizePolicy.setHeightForWidth(rbracketButton->sizePolicy().hasHeightForWidth());
        rbracketButton->setSizePolicy(sizePolicy);
        rbracketButton->setMinimumSize(QSize(50, 50));
        rbracketButton->setFont(font);

        ButtonLayout->addWidget(rbracketButton);

        aboveButton = new QPushButton(centralWidget);
        aboveButton->setObjectName(QString::fromUtf8("aboveButton"));
        aboveButton->setMinimumSize(QSize(50, 50));
        aboveButton->setFont(font);

        ButtonLayout->addWidget(aboveButton);

        underButton = new QPushButton(centralWidget);
        underButton->setObjectName(QString::fromUtf8("underButton"));
        underButton->setMinimumSize(QSize(50, 50));
        underButton->setFont(font);

        ButtonLayout->addWidget(underButton);

        beginEndButton = new QPushButton(centralWidget);
        beginEndButton->setObjectName(QString::fromUtf8("beginEndButton"));
        beginEndButton->setMinimumSize(QSize(100, 50));
        beginEndButton->setFont(font);

        ButtonLayout->addWidget(beginEndButton);


        MainLayout->addLayout(ButtonLayout);

        editor = new QTextEdit(centralWidget);
        editor->setObjectName(QString::fromUtf8("editor"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Monospace"));
        font1.setPointSize(14);
        editor->setFont(font1);

        MainLayout->addWidget(editor);


        gridLayout->addLayout(MainLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 854, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuLexer = new QMenu(menuBar);
        menuLexer->setObjectName(QString::fromUtf8("menuLexer"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuLexer->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionQuit);
        menuLexer->addAction(actionBash);
        menuLexer->addAction(actionLaTeX);
        menuLexer->addAction(actionMarkdown);
        menuLexer->addAction(actionOrg_mode);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionLaTeX->setText(QApplication::translate("MainWindow", "LaTeX", 0, QApplication::UnicodeUTF8));
        actionBash->setText(QApplication::translate("MainWindow", "Bash", 0, QApplication::UnicodeUTF8));
        actionMarkdown->setText(QApplication::translate("MainWindow", "Markdown", 0, QApplication::UnicodeUTF8));
        actionOrg_mode->setText(QApplication::translate("MainWindow", "org-mode", 0, QApplication::UnicodeUTF8));
        dollarButton->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        backslashButton->setText(QApplication::translate("MainWindow", "\\", 0, QApplication::UnicodeUTF8));
        laccolButton->setText(QApplication::translate("MainWindow", "{", 0, QApplication::UnicodeUTF8));
        raccolButton->setText(QApplication::translate("MainWindow", "}", 0, QApplication::UnicodeUTF8));
        lparentButton->setText(QApplication::translate("MainWindow", "(", 0, QApplication::UnicodeUTF8));
        rparentButton->setText(QApplication::translate("MainWindow", ")", 0, QApplication::UnicodeUTF8));
        lbracketButton->setText(QApplication::translate("MainWindow", "[", 0, QApplication::UnicodeUTF8));
        rbracketButton->setText(QApplication::translate("MainWindow", "]", 0, QApplication::UnicodeUTF8));
        aboveButton->setText(QApplication::translate("MainWindow", "^", 0, QApplication::UnicodeUTF8));
        underButton->setText(QApplication::translate("MainWindow", "_", 0, QApplication::UnicodeUTF8));
        beginEndButton->setText(QApplication::translate("MainWindow", "Begin/End", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        menuLexer->setTitle(QApplication::translate("MainWindow", "Lexer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
