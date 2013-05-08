#include "RichAlignRightAction.h"
#include "config/ApplicationConfig.h"

RichAlignRightAction::RichAlignRightAction(QObject * parent)
	: BaseRichAction(parent)
{
	 this->setCheckable(true);
}

RichAlignRightAction::~RichAlignRightAction()
{

}

long RichAlignRightAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString RichAlignRightAction::title()
{
	return tr("Right");
}

QIcon RichAlignRightAction::getIcon()
{
	QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
		+ "/textright.png";
	return QIcon(image);
}

void RichAlignRightAction::doExecute()
{
	textAlign();
}

void RichAlignRightAction::textAlign()
{
	textEdit_->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
}