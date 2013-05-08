#include "RichBoldAction.h"
#include "config/ApplicationConfig.h"

RichBoldAction::RichBoldAction(QObject * parent)
	: BaseRichAction(parent)
{
	 this->setCheckable(true);
}

RichBoldAction::~RichBoldAction()
{

}

long RichBoldAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString RichBoldAction::title()
{
	return tr("Bold");
}

QIcon RichBoldAction::getIcon()
{
	QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
		+ "/textbold.png";
	return QIcon(image);
}

void RichBoldAction::doExecute()
{
	textBold();
}

void RichBoldAction::textBold()
{
	QTextCharFormat fmt;
	fmt.setFontWeight(this->isChecked() ? QFont::Bold : QFont::Normal);
	textEdit_->mergeFormatOnWordOrSelection(fmt);
}