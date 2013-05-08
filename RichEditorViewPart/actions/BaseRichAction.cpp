#include "BaseRichAction.h"
#include "ServiceManager.h"


BaseRichAction::BaseRichAction(QObject * parent)
	: IAction(parent)
	, textEdit_(NULL)
{

}

BaseRichAction::~BaseRichAction()
{
	
}


void BaseRichAction::execute()
{
	IService* service = ServiceManager::instance().find(RegisteredSeviceID::RSI_EDITOR_RICHEDITORVIEW);
	RichEditorViewPart* richEditorViewPart = static_cast<RichEditorViewPart*>(service);
	if (richEditorViewPart){
		textEdit_ = richEditorViewPart->getRichEditorWidget()->getCurrentEditor();
		if (textEdit_){
			doExecute();
		}
	}
}
