#include "IContextAction.h"
#include "config/ApplicationConfig.h"


namespace UiUtils{

	IContextAction::IContextAction(QObject * parent)
		: QAction(parent)
	{
	}

	IContextAction::~IContextAction()
	{

	}

	QIcon IContextAction::getIcon()
	{
		QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
			+ "/default.png";
		return QIcon(image);
	}
}

