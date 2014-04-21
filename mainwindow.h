/*
*
*    Thomas "Mr Men" Etcheverria
*    <tetcheve (at) gmail .com>
*
*    Created on : 28-12-2013 20:36:29
*    Time-stamp: <28-12-2013 20:41:29>
*
*    File name : mainwindow.h
*    Description : mainwindow for code editor
*                  highlight support done with highlight.{h,cpp}
*    
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCursor>
#include <QString>
#include "finddialog.h"
#include "findreplacedialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


protected:
     void closeEvent(QCloseEvent *event);
     bool eventFilter(QObject*, QEvent*);
     void changeEvent(QEvent *e);
     void createActions();


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString bufferName;
    QString keyCC;


private:
    Ui::MainWindow *ui;
    FindDialog *m_findDialog;
    FindReplaceDialog *m_findReplaceDialog;


private slots:
    void findDialog();
    void findReplaceDialog();

public slots:
    void open();
    void printButtonText();
    void beginEnd();
    void addItem();
    void hiliteCurrentLine();
    void saveFile();
    void setLexerLaTeX();
//    void setLexerBash();
    void setLexerOrgMode();
    void setLexerMarkdown();

    void setThemeSolarizedDark();
    void setThemeZenburn();

    void updateFont(const QFont &font);
    void updateFontSize(int);
};

#endif // MAINWINDOW_H
