#include "IAction.h"
#include "ApplicationConfig.h"


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
		QString image = QString::fromStdString(ApplicationConfig::instance().getIconPath())
			+ "/default.png";
		return QIcon(image);
	}
}

