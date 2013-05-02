#include "SaveAction.h"
#include "ViewServiceOperator.h"
SaveAction::SaveAction(QObject * parent)
	: IAction(parent)
{

}

SaveAction::~SaveAction()
{

}


void SaveAction::execute()
{
	UiUtils::ViewServiceOperator::instance().saveEditors();
}

long SaveAction::serviceId()
{
	return RegisteredSeviceID::RSI_ACTION_SAVE;
}

QString SaveAction::title()
{
	return tr("&save");
}