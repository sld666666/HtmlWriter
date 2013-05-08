#include "RichAlignCenterAction.h"
#include "config/ApplicationConfig.h"

RichAlignCenterAction::RichAlignCenterAction(QObject * parent)
	: BaseRichAction(parent)
{
	 this->setCheckable(true);
}

RichAlignCenterAction::~RichAlignCenterAction()
{

}

long RichAlignCenterAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString RichAlignCenterAction::title()
{
	return tr("center");
}

QIcon RichAlignCenterAction::getIcon()
{
	QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
		+ "/textcenter.png";
	return QIcon(image);
}

void RichAlignCenterAction::doExecute()
{
	textAlign();
}

void RichAlignCenterAction::textAlign()
{
	textEdit_->setAlignment(Qt::AlignHCenter);
}