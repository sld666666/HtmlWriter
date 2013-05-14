/** 
* @file         EditorTabWidgetActions.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-14
*/
#ifndef UIUTILS_EDITORTABWIDGETACTIONS_H
#define UIUTILS_EDITORTABWIDGETACTIONS_H

#include "action/IContextAction.h"
#include "../ActionTabWidget.h"

namespace UiUtils{

	class BaseEditorTabRightAction : public IContextAction
	{
	public:
		BaseEditorTabRightAction(QObject * parent);
		~BaseEditorTabRightAction();

		virtual	void	execute(IContextPtr context);

	protected:
		virtual	void  doExeute(ActionTabWidget* tablWidget) = 0;

	};

	class OpenFolderAction : public BaseEditorTabRightAction
	{
	public:
		OpenFolderAction(QObject * parent);
		~OpenFolderAction();

		virtual QString title();

	protected:
		virtual	void  doExeute(ActionTabWidget* tablWidget);

	};

	class CloseEditorAction : public BaseEditorTabRightAction
	{
	public:
		CloseEditorAction(QObject * parent);
		~CloseEditorAction();

		virtual QString title();

	protected:
		virtual	void  doExeute(ActionTabWidget* tablWidget);

	};

	class CloseOtherEditorsAction : public BaseEditorTabRightAction
	{
	public:
		CloseOtherEditorsAction(QObject * parent);
		~CloseOtherEditorsAction();

		virtual QString title();

	protected:
		virtual	void  doExeute(ActionTabWidget* tablWidget);

	};
}


#endif // WDITORTABWIDGETACTIONS_H
