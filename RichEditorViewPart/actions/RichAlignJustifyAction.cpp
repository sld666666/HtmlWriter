#include "RichAlignJustifyAction.h"
#include "config/ApplicationConfig.h"

RichAlignJustifyAction::RichAlignJustifyAction(QObject * parent)
	: BaseRichAction(parent)
{
	 this->setCheckable(true);
}

RichAlignJustifyAction::~RichAlignJustifyAction()
{

}

long RichAlignJustifyAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString RichAlignJustifyAction::title()
{
	return tr("Justify");
}

QIcon RichAlignJustifyAction::getIcon()
{
	QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
		+ "/textjustify.png";
	return QIcon(image);
}

void RichAlignJustifyAction::doExecute()
{
	textAlign();
}

void RichAlignJustifyAction::textAlign()
{
	textEdit_->setAlignment(Qt::AlignJustify);
}