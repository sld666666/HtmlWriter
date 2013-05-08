#include "BaseMarkdownAction.h"
#include "ServiceManager.h"


BaseMarkdownAction::BaseMarkdownAction(QObject * parent)
	: IAction(parent)
	, textEdit_(NULL)
{

}

BaseMarkdownAction::~BaseMarkdownAction()
{
	
}


void BaseMarkdownAction::execute()
{
	IService* service = ServiceManager::instance().find(RegisteredSeviceID::RSI_EDITOR_MARKDOWNEDITORVIEW);
	MarkdownEditorViewPart* markdownEditorViewPart = static_cast<MarkdownEditorViewPart*>(service);
	if (markdownEditorViewPart){
		textEdit_ = markdownEditorViewPart->getEditor()->getCurTextEditor();
		if (textEdit_){
			doExecute();
		}
	}
}
