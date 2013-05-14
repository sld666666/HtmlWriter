#include <QTextCursor>
#include "TextEdit.h"

namespace UiUtils{

	TextEdit::TextEdit(const QString& path, QWidget *parent)
		: QTextEdit(parent)
		, path_(path)
	{
		this->setStyleSheet(QString::fromUtf8("QScrollBar:vertical {\
								border: 2px solid grey;\
								width: 10px;}"));
	}

	TextEdit::~TextEdit()
	{

	}

	QString TextEdit::getPath()
	{
		return path_;
	}

	void TextEdit::mergeFormatOnWordOrSelection(QTextCharFormat fmt)
	{
		QTextCursor cursor = this->textCursor();
		if (!cursor.hasSelection())
			cursor.select(QTextCursor::WordUnderCursor);
		cursor.mergeCharFormat(fmt);
		this->mergeCurrentCharFormat(fmt);
	}

	void TextEdit::insertMark(const QString& mark
							, const QString& external)
	{
		QTextCursor cursor = this->textCursor();
		cursor.insertText(mark);
		cursor.insertText(external );
	}

	void TextEdit::insertMark(const QString& mark)
	{
		QTextCursor cursor = this->textCursor();
		cursor.insertText(mark);
	}

	void TextEdit::insertEnter()
	{
		insertMark("\n");
	}

	void TextEdit::insertSymmetricalMark(const QString& mark)
	{
		int markSize = mark.size();
		QTextCursor cursor = this->textCursor();
		if (cursor.hasSelection()){
			QString text = cursor.selectedText();
			int startPos = cursor.selectionStart();
			int endPos = cursor.selectionEnd();
			cursor.setPosition(startPos);
			cursor.insertText(mark);
			cursor.setPosition(endPos+markSize);
			cursor.insertText(mark);
		}else{
			cursor.insertText(mark);
			cursor.insertText(mark);
			cursor.movePosition(QTextCursor::Left, QTextCursor::MoveAnchor
				, markSize);
			this->setTextCursor(cursor);
		}
	}

}
