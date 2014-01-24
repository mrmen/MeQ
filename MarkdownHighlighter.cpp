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

#include "MarkdownHighlighter.h"

MarkdownHighlighter::MarkdownHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

// org-mode

    // markdown-mode
        functionFormat.setForeground(Qt::blue);
        rule.pattern = QRegExp("^#+ .*");
        rule.format = functionFormat;
        highlightingRules.append(rule);
        // -
        functionFormat.setForeground(Qt::blue);
        functionFormat.setFontWeight(QFont::Bold);
        rule.pattern = QRegExp("^[ \t]*(\\-|\\*)");
        rule.format = functionFormat;
        highlightingRules.append(rule);
        functionFormat.setFontWeight(QFont::Normal);

        functionFormat.setForeground(Qt::blue);
        functionFormat.setFontWeight(QFont::Bold);
        rule.pattern = QRegExp("^(\\-|=)+");
        rule.format = functionFormat;
    highlightingRules.append(rule);

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}

void MarkdownHighlighter::highlightBlock(const QString &text)
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

