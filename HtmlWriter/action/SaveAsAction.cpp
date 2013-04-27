#include "SaveAsAction.h"

SaveAsAction::SaveAsAction(const QString& text, QObject * parent)
	: IAction(text, parent)
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
	return -1;
}