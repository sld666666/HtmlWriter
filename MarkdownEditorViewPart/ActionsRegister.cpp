#include "ActionsRegister.h"
#include "actions/MarkdownEditorToolBar.h"
#include "ServiceManager.h"

using service::ServiceManager;

ActionsRegister::ActionsRegister(QObject *parent)
	: QObject(parent)
{

}

ActionsRegister::~ActionsRegister()
{

}

void ActionsRegister::registerActions()
{
	ServiceManager::instance().appendService(new MarkdownEditorToolBar(NULL));
}