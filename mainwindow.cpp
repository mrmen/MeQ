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
#include "OrgModeHighlighter.h"
#include "MarkdownHighlighter.h"
#include "LaTeXHighlighter.h"

#include "finddialog.h"
#include "findreplacedialog.h"

#include <iostream>
#include <QTextCodec>
#include <QInputDialog>
#include <QFile>
#include <QFileDialog>
#include <QFontComboBox>
#include <QEvent>
#include <QKeyEvent>
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    m_findDialog = new FindDialog(this);
    m_findDialog->setModal(false);
    m_findDialog->setTextEdit(ui->editor);

    m_findReplaceDialog = new FindReplaceDialog(this);
    m_findReplaceDialog->setModal(false);
    m_findReplaceDialog->setTextEdit(ui->editor);

    createActions();


    ui->ButtonLayout->setAlignment(Qt::AlignLeft);
    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(open()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(saveFile()));
    connect(ui->actionOrg_mode,SIGNAL(triggered()),this,SLOT(setLexerOrgMode()));
    connect(ui->actionMarkdown,SIGNAL(triggered()),this,SLOT(setLexerMarkdown()));
    connect(ui->actionLaTeX,SIGNAL(triggered()),this,SLOT(setLexerLaTeX()));

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

    connect(ui->fontComboBox, SIGNAL(currentFontChanged(QFont)),this,SLOT(updateFont(QFont)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(updateFontSize(int)));

    connect(ui->actionSolarized_dark,SIGNAL(triggered()),this,SLOT(setThemeSolarizedDark()));
    connect(ui->actionZenburn,SIGNAL(triggered()),this,SLOT(setThemeZenburn()));


    connect(ui->beginEndButton,SIGNAL(clicked()),this,SLOT(beginEnd()));

    connect(ui->editor,SIGNAL(cursorPositionChanged()),this,SLOT(hiliteCurrentLine()));


//    connect(ui->actionBeginEnd, SIGNAL(triggered()), this, SLOT(beginEnd()));
//    ui->actionBeginEnd->setShortcut(tr("Ctrl+C, Ctrl+E"));
//    connect(ui->actionItem, SIGNAL(triggered()),SLOT(addItem()));
//    ui->actionItem->setShortcut(tr("Ctrl+C,Ctrl+J"));


    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    ui->spinBox->setValue(14);
#ifdef __gnu_linux__
    ui->fontComboBox->setCurrentFont(QFont("Monospace"));
#endif


    ui->editor->installEventFilter(this);


    // do the higlight stuff
    //Highlighter *highlighter = new Highlighter(ui->editor->document());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::createActions() {
    connect(ui->actionFind, SIGNAL(triggered()), this, SLOT(findDialog()));
    connect(ui->actionReplace, SIGNAL(triggered()), this, SLOT(findReplaceDialog()));

//    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));

//    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    connect(ui->actionFindNext, SIGNAL(triggered()), m_findDialog, SLOT(findNext()));
    connect(ui->actionFindPrevious, SIGNAL(triggered()), m_findDialog, SLOT(findPrev()));
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::findDialog() {
    m_findDialog->show();
}

void MainWindow::findReplaceDialog() {
    m_findReplaceDialog->show();
}






void MainWindow::open(){
  // save before opening
  saveFile();

  // open file
    bufferName = QFileDialog::getOpenFileName(this,
                                                       tr("Open File"),"");
    if(!bufferName.isEmpty()){
        QFile file(bufferName);
        if (file.open(QFile::ReadOnly | QFile::Text)){
            ui->editor->setPlainText(QString::fromUtf8(file.readAll()));
        }
    }
    // setup editor
    QFont font;
    font.setFamily("Monospace");
    font.setFixedPitch(true);
    font.setPointSize(11);
    ui->editor->setFont(font);

    // do the higlight stuff
    //Highlighter *highlighter = new Highlighter(ui->editor->document());
}


bool MainWindow::eventFilter(QObject* object, QEvent* event){
  if (event->type() == QEvent::KeyPress){
      QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

      int keyInt = keyEvent->key();
      Qt::Key key = static_cast<Qt::Key>(keyInt);


      // check for a combination of user clicks
      Qt::KeyboardModifiers modifiers = keyEvent->modifiers();
      QString keyText = keyEvent->text();

      QList<Qt::Key> modifiersList;
      if(modifiers & Qt::ShiftModifier)
          keyInt += Qt::SHIFT;
      if(modifiers & Qt::ControlModifier)
          keyInt += Qt::CTRL;
      if(modifiers & Qt::AltModifier)
          keyInt += Qt::ALT;
      if(modifiers & Qt::MetaModifier)
          keyInt += Qt::META;

      if (QKeySequence(keyInt).toString(QKeySequence::NativeText)=="Ctrl+C"){
          keyCC = "Ctrl+C";
        }
      else{
          if (QKeySequence(keyInt).toString(QKeySequence::NativeText)=="Ctrl+E" && keyCC == "Ctrl+C"){
              keyCC = "";
              beginEnd();
            }
          if (QKeySequence(keyInt).toString(QKeySequence::NativeText)=="Ctrl+J" && keyCC == "Ctrl+C"){
              keyCC = "";
              addItem();
            }
          else{
              return QObject::eventFilter(object, event);
            }
        }

//      qDebug() << "New KeySequence:" << QKeySequence(keyInt).toString(QKeySequence::NativeText);
  }
  else{
      return QObject::eventFilter(object, event);
    }
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

void MainWindow::addItem(){
  ui->editor->insertPlainText("\n");
  ui->editor->insertPlainText("\\item ");
  ui->editor->setFocus();
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
  if (bufferName.isEmpty()){
      bufferName = QFileDialog::getSaveFileName(this,
                                                     "Save LaTeX File",
                                                     QString(),
                                                     "Fichier LaTeX (*.tex)");
  }
    QFileInfo info(bufferName);
    if (info.suffix().isEmpty())
        bufferName+=".tex";
    QFile file(bufferName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    file.write(ui->editor->toPlainText().toUtf8());
    file.close();
    // wait for file close
}




void MainWindow::updateFont(const QFont &font){
    int pixel = ui->spinBox->value();
    QFont tempFont = font;
    tempFont.setPointSize(pixel);
    ui->editor->setFont(tempFont);
}

void MainWindow::updateFontSize(int i){
    QFont tempFont = ui->fontComboBox->currentFont();
    tempFont.setPointSize(i);
    ui->editor->setFont(tempFont);
}



void MainWindow::closeEvent(QCloseEvent *event){
  saveFile();
}



void MainWindow::setLexerOrgMode(){
    OrgModeHighlighter *orgmodehighlighter =  new OrgModeHighlighter(ui->editor->document());
}

void MainWindow::setLexerLaTeX(){
    LaTeXHighlighter *latexhighlighter =  new LaTeXHighlighter(ui->editor->document());
}

void MainWindow::setLexerMarkdown(){
    MarkdownHighlighter *markdownhighlighter =  new MarkdownHighlighter(ui->editor->document());
}

void MainWindow::setThemeSolarizedDark(){
    ui->editor->setStyleSheet("background : #002b36; color : #657b83");
}

void MainWindow::setThemeZenburn(){
    ui->editor->setStyleSheet("background : #efefef; color : #4d4d4c;");
}

