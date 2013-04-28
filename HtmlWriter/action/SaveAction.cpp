#include "SaveAction.h"

SaveAction::SaveAction(QObject * parent)
	: IAction(parent)
{

}

SaveAction::~SaveAction()
{

}


void SaveAction::execute()
{

}

long SaveAction::serviceId()
{
	return RegisteredSeviceID::RSI_ACTION_SAVE;
}

QString SaveAction::title()
{
	return tr("&save");
}