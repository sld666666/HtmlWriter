#include <QDesktopServices>
#include <QUrl>

#include "EditorTabWidgetActions.h"
#include "context/EditorTabWidgetContext.h"
#include "../TextEdit.h"

namespace UiUtils{
	BaseEditorTabRightAction::BaseEditorTabRightAction(QObject * parent)
		: IContextAction(parent)
	{

	}

	BaseEditorTabRightAction::~BaseEditorTabRightAction()
	{

	}

	void BaseEditorTabRightAction::execute(IContextPtr context)
	{
		EditorTabWidgetContextPtr tabContext = boost::static_pointer_cast<EditorTabWidgetContext>(context);
		if (tabContext.get()){
			ActionTabWidget* acitonTabWidget = static_cast<ActionTabWidget*>(tabContext->getContextWidget());
			doExeute(acitonTabWidget);
		}
	}

	OpenFolderAction::OpenFolderAction(QObject * parent)
		: BaseEditorTabRightAction(parent)
	{
		this->setShortcut(Qt::Key_O);
	}

	OpenFolderAction::~OpenFolderAction()
	{

	}

	QString OpenFolderAction::title()
	{
		return tr("open folder(O)");
	}


	void OpenFolderAction::doExeute(ActionTabWidget* tablWidget)
	{
		TextEdit* textEdit = static_cast<TextEdit*>(
			tablWidget->currentWidget());
		if (textEdit){
			QString textPath = textEdit->getPath();
			int stuffIndex = textPath.lastIndexOf("/");
			textPath = textPath.left(stuffIndex);
			QDesktopServices::openUrl(QUrl(textPath));
		}
	}


	CloseEditorAction::CloseEditorAction(QObject * parent)
		: BaseEditorTabRightAction(parent)
	{	
		this->setShortcut(Qt::Key_C);
	}
	CloseEditorAction::~CloseEditorAction()
	{
		
	}

	QString CloseEditorAction::title()
	{
		return tr("close(C)");
	}

	void CloseEditorAction::doExeute(ActionTabWidget* tablWidget)
	{
		tablWidget->removeCurTab();
	}

	CloseOtherEditorsAction::CloseOtherEditorsAction(QObject * parent)
		: BaseEditorTabRightAction(parent)
	{
		this->setShortcut(Qt::Key_A);
	}
	CloseOtherEditorsAction::~CloseOtherEditorsAction()
	{

	}

	QString CloseOtherEditorsAction::title()
	{
		return tr("close others(A)");
	}

	void CloseOtherEditorsAction::doExeute(ActionTabWidget* tablWidget)
	{
		tablWidget->removeExceptCurTab();
	}
		
}