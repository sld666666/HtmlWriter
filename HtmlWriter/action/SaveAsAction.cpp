#include "SaveAsAction.h"

SaveAsAction::SaveAsAction(QObject * parent)
	: IAction(parent)
{

}

SaveAsAction::~SaveAsAction()
{

}


void SaveAsAction::execute()
{

}

long SaveAsAction::serviceId()
{
	return RegisteredSeviceID::RSI_ACTION_SAVEAS;
}

QString SaveAsAction::title()
{
	return tr("&saveAs");
}