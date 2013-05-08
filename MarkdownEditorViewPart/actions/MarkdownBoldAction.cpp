#include "MarkdownBoldAction.h"
#include "ApplicationConfig.h"

MarkdownBoldAction::MarkdownBoldAction(QObject * parent)
	: BaseMarkdownAction(parent)
{
	 this->setCheckable(true);
}

MarkdownBoldAction::~MarkdownBoldAction()
{

}

long MarkdownBoldAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString MarkdownBoldAction::title()
{
	return tr("Bold");
}

QIcon MarkdownBoldAction::getIcon()
{
	QString image = QString::fromStdString(ApplicationConfig::instance().getIconPath())
		+ "/textbold.png";
	return QIcon(image);
}

void MarkdownBoldAction::doExecute()
{
	textBold();
}

void MarkdownBoldAction::textBold()
{
	textEdit_->insertSymmetricalMark("**");
}