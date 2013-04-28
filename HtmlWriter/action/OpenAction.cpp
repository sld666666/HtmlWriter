#include "OpenAction.h"

OpenAction::OpenAction(QObject * parent)
	: IAction(parent)
{

}

OpenAction::~OpenAction()
{

}


void OpenAction::execute()
{

}

long OpenAction::serviceId()
{
	return RegisteredSeviceID::RSI_ACTION_OPEN;
}

QString OpenAction::title()
{
	return tr("&open");
}