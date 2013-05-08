#include "RichAlignLeftAction.h"
#include "config/ApplicationConfig.h"

RichAlignLeftAction::RichAlignLeftAction(QObject * parent)
	: BaseRichAction(parent)
{
	 this->setCheckable(true);
}

RichAlignLeftAction::~RichAlignLeftAction()
{

}

long RichAlignLeftAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString RichAlignLeftAction::title()
{
	return tr("Left");
}

QIcon RichAlignLeftAction::getIcon()
{
	QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
		+ "/textleft.png";
	return QIcon(image);
}

void RichAlignLeftAction::doExecute()
{
	textAlign();
}

void RichAlignLeftAction::textAlign()
{
	 textEdit_->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
}