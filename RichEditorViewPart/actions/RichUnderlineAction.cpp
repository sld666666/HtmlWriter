#include "RichUnderlineAction.h"
#include "ApplicationConfig.h"

RichUnderlineAction::RichUnderlineAction(QObject * parent)
	: BaseRichAction(parent)
{
	 this->setCheckable(true);
}

RichUnderlineAction::~RichUnderlineAction()
{

}

long RichUnderlineAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString RichUnderlineAction::title()
{
	return tr("Underline");
}

QIcon RichUnderlineAction::getIcon()
{
	QString image = QString::fromStdString(ApplicationConfig::instance().getIconPath())
		+ "/textunder.png";
	return QIcon(image);
}

void RichUnderlineAction::doExecute()
{
	textUnderline();
}

void RichUnderlineAction::textUnderline()
{
	QTextCharFormat fmt;
	fmt.setFontUnderline(this->isChecked());
	textEdit_->mergeFormatOnWordOrSelection(fmt);
}