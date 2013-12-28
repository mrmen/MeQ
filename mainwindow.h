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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void open();
    void printButtonText();
    void beginEnd();
    void hiliteCurrentLine();
    void saveFile();
};

#endif // MAINWINDOW_H
