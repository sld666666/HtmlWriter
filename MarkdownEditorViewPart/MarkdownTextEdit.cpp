#include "MarkdownTextEdit.h"
#include "DataManager.h"


MarkdownTextEdit::MarkdownTextEdit(const QString& path, QWidget *parent)
	: QTextEdit(parent)
	, path_(path)
{
	QString data;
	data::DataManager::instance().getString(path_, data);
	this->setText(data);
}

MarkdownTextEdit::~MarkdownTextEdit()
{

}

QString MarkdownTextEdit::getPath()
{
	return path_;
}
