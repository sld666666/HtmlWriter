#ifndef UIUTILS_EXTEDIT_H
#define UIUTILS_EXTEDIT_H

#include <QTextEdit>
#include <QTextCharFormat>

#include "ui_global.h"

namespace UiUtils{
	class UI_EXPORT TextEdit : public QTextEdit
	{
		Q_OBJECT

	public:
		TextEdit(const QString& path, QWidget *parent);
		~TextEdit();

		QString		getPath();

		void		mergeFormatOnWordOrSelection(QTextCharFormat fmt);
		void		insertEnter();
		void		insertMark(const QString& mark);
		void		insertMark(const QString& mark,const QString& external);
		void		insertSymmetricalMark(const QString& mark);
	public:
		//functor
		static bool isExist(TextEdit* edit, const QString& path)
		{
			return (edit && edit->getPath() == path);
		}
	private:
		QString		path_;

	};
}


#endif // UIUTILS_EXTEDIT_H
