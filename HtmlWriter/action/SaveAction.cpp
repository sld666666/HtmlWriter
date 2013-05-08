#include "SaveAction.h"
#include "ViewServiceOperator.h"
#include "config/ApplicationConfig.h"
SaveAction::SaveAction(QObject * parent)
	: IAction(parent)
{
	this->setShortcut(Qt::CTRL + Qt::Key_S);
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
	return tr("&save(ctrl+s)");
}

QIcon	SaveAction::getIcon()
{
	QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
		+ "/save.png";
	return QIcon(image);
}