#ifndef UIUTILS_ACTIONTABWIDGET_H
#define UIUTILS_ACTIONTABWIDGET_H

#include <QTabWidget>

#include "ui_global.h"

namespace UiUtils{
	class EditorTabWidgetRightMenu;
	class TextEdit;

	class UI_EXPORT ActionTabWidget : public QTabWidget 
	{
		Q_OBJECT

	public:
		ActionTabWidget(QWidget *parent);
		~ActionTabWidget();

	public:
		void				addTextEditor(TextEdit* textEditor);
		vector<TextEdit*>  getTextEditors();
		void				removeCurTab();
		void				removeExceptCurTab();

	private slots:
		void	onShowRightMenuSlot(const QPoint point);
	private:
		void	initConnect();
	private:
		shared_ptr<EditorTabWidgetRightMenu>  tabRightMenu_;
		vector<TextEdit*>  textEditors_;
	};
}


#endif // ACTIONTABWIDGET_H
