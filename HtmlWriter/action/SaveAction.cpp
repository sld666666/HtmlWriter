#include "SaveAction.h"

SaveAction::SaveAction(const QString& text, QObject * parent)
	: IAction(text, parent)
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
	return -1;
}