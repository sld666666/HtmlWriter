#include "EditorHeaderAction.h"
#include "ApplicationConfig.h"

EditorHeaderAction::EditorHeaderAction(QObject * parent)
	: BaseMarkdownAction(parent)
{

}

EditorHeaderAction::~EditorHeaderAction()
{

}

long EditorHeaderAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
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

void EditorHeaderAction::doExecute()
{
	textEdit_->insertSymmetricalMark(",");
}