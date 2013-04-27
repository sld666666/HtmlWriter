#include "OpenAction.h"

OpenAction::OpenAction(const QString& text, QObject * parent)
	: IAction(text, parent)
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
	return RegisteredSeviceID::RSI_UNREGISTER;
}