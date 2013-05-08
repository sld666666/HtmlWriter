#include "IAction.h"
#include "config/ApplicationConfig.h"


namespace UiUtils{

	IAction::IAction(QObject * parent)
		: QAction(parent)
	{
	}

	IAction::~IAction()
	{

	}

	QIcon IAction::getIcon()
	{
		QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
			+ "/default.png";
		return QIcon(image);
	}
}

