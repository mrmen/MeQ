/*
*
*    Thomas "Mr Men" Etcheverria
*    <tetcheve (at) gmail .com>
*
*    Created on : 28-12-2013 20:36:29
*    Time-stamp: <28-12-2013 20:39:12>
*
*    File name : highlighter.h
*    Description : try to highlight some LaTeX code using QSyntaxHighlighter
*    
*/
#ifndef MARKDOWNHIGHLIGHTER_H
#define MARKDOWNHIGHLIGHTER_H

#include <QSyntaxHighlighter>

#include <QHash>
#include <QTextCharFormat>

class QTextDocument;

class MarkdownHighlighter : public QSyntaxHighlighter
{
Q_OBJECT

public:
MarkdownHighlighter(QTextDocument *parent = 0);

protected:
void highlightBlock(const QString &text);

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };

    QVector<HighlightingRule> highlightingRules;

QRegExp commentStartExpression;
QRegExp commentEndExpression;

QTextCharFormat keywordFormat;
QTextCharFormat classFormat;
QTextCharFormat singleLineCommentFormat;
QTextCharFormat mathDollarFormat;
QTextCharFormat mathCenterFormat;
QTextCharFormat backslashFormat;
QTextCharFormat multiLineCommentFormat;
QTextCharFormat quotationFormat;
QTextCharFormat functionFormat;
};


#endif // MARKDOWNHIGHLIGHTER_H
