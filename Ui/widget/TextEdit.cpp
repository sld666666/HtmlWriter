#include <QTextCursor>
#include "TextEdit.h"

namespace UiUtils{

	TextEdit::TextEdit(const QString& path, QWidget *parent)
		: QTextEdit(parent)
		, path_(path)
	{
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

}
