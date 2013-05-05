#include "EditorHeaderAction.h"
#include "ApplicationConfig.h"

EditorHeaderAction::EditorHeaderAction(QObject * parent)
	: IAction(parent)
{

}

EditorHeaderAction::~EditorHeaderAction()
{

}


void EditorHeaderAction::execute()
{

}

long EditorHeaderAction::serviceId()
{
	return RegisteredSeviceID::RSI_ACTION_EDITORHEADER;
}

QString EditorHeaderAction::title()
{
	return tr("EditorHeader");
}

QIcon EditorHeaderAction::getIcon()
{
	QString image = QString::fromStdString(ApplicationConfig::instance().getIconPath())
		+ "/hear.png";
	return QIcon(image);
}