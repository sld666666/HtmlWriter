#ifndef MARKDOWNTEXTEDIT_H
#define MARKDOWNTEXTEDIT_H

#include <QTextEdit>

class MarkdownTextEdit : public QTextEdit
{
	Q_OBJECT

public:
	MarkdownTextEdit(const QString& path, QWidget *parent);
	~MarkdownTextEdit();

	QString		getPath();
public:
	//functor
	static bool isExist(MarkdownTextEdit* edit, const QString& path)
	{
		return (edit && edit->getPath() == path);
	}
private:
	QString		path_;
	
};

#endif // MARKDOWNTEXTEDIT_H
