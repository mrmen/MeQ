/*
*
*    Thomas "Mr Men" Etcheverria
*    <tetcheve (at) gmail .com>
*
*    Created on : 28-12-2013 20:36:29
*    Time-stamp: <28-12-2013 20:38:28>
*
*    File name : highlighter.cpp
*    Description : try to highlight some LaTeX code using QSyntaxHighlighter
*    
*/
#include <QtGui>

#include "LaTeXHighlighter.h"

LaTeXHighlighter::LaTeXHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bsection\\b" << "\\bsubsection\\b" << "\\bsubsubsection\\b" << "\\bchapter\\b"
            << "\\bdfrac\\b";
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }


    /*aa
     * FIXME: voire comment gérer les notion de \textbf{aaa \textit{bbbb} cccc}
     *
     */


//// org-mode

//    // *
//    functionFormat.setForeground(Qt::red);
//    rule.pattern = QRegExp("^\\* .*");
//    rule.format = functionFormat;
//    highlightingRules.append(rule);
//    // **
//    functionFormat.setForeground(Qt::blue);
//    rule.pattern = QRegExp("^\\*\\* .*");
//    rule.format = functionFormat;
//    highlightingRules.append(rule);
//    // ***
//    functionFormat.setForeground(Qt::darkGreen);
//    rule.pattern = QRegExp("^\\*\\*\\* .*");
//    rule.format = functionFormat;
//    highlightingRules.append(rule);

//    // -
//    functionFormat.setForeground(Qt::blue);
//    functionFormat.setFontWeight(QFont::Bold);
//    rule.pattern = QRegExp("^[ \t]*\\-");
//    rule.format = functionFormat;
//    highlightingRules.append(rule);
//    functionFormat.setFontWeight(QFont::Normal);


    //
// accol
//
    functionFormat.setForeground(QColor(255,200,110));
    rule.pattern = QRegExp("\\{[^\\{\\}]*\\}");
    rule.format = functionFormat;
    highlightingRules.append(rule);
    functionFormat.setFontUnderline(false);
    functionFormat.setForeground(Qt::blue);
    rule.pattern = QRegExp("\\{|\\}");
    rule.format = functionFormat;
    highlightingRules.append(rule);


//
// LaTeX command
//
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegExp("\\\\[A-Za-z]*");
    rule.format = classFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(Qt::gray);
    rule.pattern = QRegExp("%[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    // \ style
    backslashFormat.setForeground(Qt::red);
    backslashFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegExp("\\\\");
    rule.format = backslashFormat;
    highlightingRules.append(rule);

    // $.*$ style
    mathDollarFormat.setForeground(Qt::red);
    mathDollarFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegExp("\\$[^\\$]*\\$");
    rule.format = mathDollarFormat;
    highlightingRules.append(rule);

    // \[.*\] style
    mathCenterFormat.setForeground(Qt::red);
    mathCenterFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegExp("\\\\\\[.*\\\\\\]");
    rule.format = mathCenterFormat;
    highlightingRules.append(rule);

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}

void LaTeXHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

    while (startIndex >= 0) {
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}

