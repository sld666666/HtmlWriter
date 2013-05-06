#include "RichItalicAction.h"
#include "ApplicationConfig.h"

RichItalicAction::RichItalicAction(QObject * parent)
	: BaseRichAction(parent)
{
	 this->setCheckable(true);
}

RichItalicAction::~RichItalicAction()
{

}

long RichItalicAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString RichItalicAction::title()
{
	return tr("Italic");
}

QIcon RichItalicAction::getIcon()
{
	QString image = QString::fromStdString(ApplicationConfig::instance().getIconPath())
		+ "/textitalic.png";
	return QIcon(image);
}

void RichItalicAction::doExecute()
{
	textItalic();
}

void RichItalicAction::textItalic()
{
	QTextCharFormat fmt;
	fmt.setFontItalic(this->isChecked());
	textEdit_->mergeFormatOnWordOrSelection(fmt);
}