/*
*
*    Thomas "Mr Men" Etcheverria
*    <tetcheve (at) gmail .com>
*
*    Created on : 28-12-2013 20:36:29
*    Time-stamp: <28-12-2013 20:40:53>
*
*    File name : mainwindow.cpp
*    Description : mainwindow for code editor
*                  highlight support done with highlight.{h,cpp}
*    
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "highlighter.h"
#include <iostream>
#include <QTextCodec>
#include <QInputDialog>
#include <QFile>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ButtonLayout->setAlignment(Qt::AlignLeft);
    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(open()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(saveFile()));

    // connect buttons
    connect(ui->dollarButton,SIGNAL(clicked()),this,SLOT(printButtonText()));
    connect(ui->backslashButton,SIGNAL(clicked()),this,SLOT(printButtonText()));
    connect(ui->lparentButton,SIGNAL(clicked()),this,SLOT(printButtonText()));
    connect(ui->rparentButton,SIGNAL(clicked()),this,SLOT(printButtonText()));
    connect(ui->laccolButton,SIGNAL(clicked()),this,SLOT(printButtonText()));
    connect(ui->raccolButton,SIGNAL(clicked()),this,SLOT(printButtonText()));
    connect(ui->lbracketButton,SIGNAL(clicked()),this,SLOT(printButtonText()));
    connect(ui->rbracketButton,SIGNAL(clicked()),this,SLOT(printButtonText()));
    connect(ui->underButton,SIGNAL(clicked()),this,SLOT(printButtonText()));
    connect(ui->aboveButton,SIGNAL(clicked()),this,SLOT(printButtonText()));

    connect(ui->beginEndButton,SIGNAL(clicked()),this,SLOT(beginEnd()));

    connect(ui->editor,SIGNAL(cursorPositionChanged()),this,SLOT(hiliteCurrentLine()));

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    // do the higlight stuff
    Highlighter *highlighter = new Highlighter(ui->editor->document());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open(){
    // open file
    QString filename = QFileDialog::getOpenFileName(this,
                                                       tr("Open File"),"");
    if(!filename.isEmpty()){
        QFile file(filename);
        if (file.open(QFile::ReadOnly | QFile::Text)){
            ui->editor->setPlainText(file.readAll());
        }
    }
    // setup editor
    QFont font;
    font.setFamily("Monospace");
    font.setFixedPitch(true);
    font.setPointSize(11);
    ui->editor->setFont(font);

    // do the higlight stuff
    Highlighter *highlighter = new Highlighter(ui->editor->document());
}


void MainWindow::printButtonText(){
    QPushButton *button = (QPushButton*)sender();
    ui->editor->insertPlainText(button->text());
    ui->editor->setFocus();
}

void MainWindow::beginEnd(){
    QString environment = QInputDialog::getText(this, tr("QInputDialog::getText()"),tr("Environment Name : "),QLineEdit::Normal);
    if (!environment.isEmpty()){
        ui->editor->insertPlainText("\\begin{"+environment+"}");
        ui->editor->insertPlainText("\n");
        ui->editor->insertPlainText("\n");
        ui->editor->insertPlainText("\\end{"+environment+"}");
        ui->editor->setFocus();
    }
}

void MainWindow::hiliteCurrentLine(){
    QTextEdit::ExtraSelection hiliteline;
    hiliteline.cursor = ui->editor->textCursor();
    hiliteline.format.setProperty(QTextTableFormat::FullWidthSelection, true);
    QColor yellowColor = QColor(255,248,220);
    hiliteline.format.setBackground(yellowColor);

    QList<QTextEdit::ExtraSelection> extras;
    extras << hiliteline;
    ui->editor->setExtraSelections(extras);
}

void MainWindow::saveFile(){
    QString fichier = QFileDialog::getSaveFileName(this,
                                                   "Save LaTeX File",
                                                   QString(),
                                                   "Fichier LaTeX (*.tex)");
    QFileInfo info(fichier);
    if (info.suffix().isEmpty())
        fichier+=".tex";
    QFile file(fichier);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    file.write(ui->editor->toPlainText().toUtf8());
    file.close();
    // wait for file close
}