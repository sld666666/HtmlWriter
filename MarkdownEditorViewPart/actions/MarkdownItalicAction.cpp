#include "MarkdownItalicAction.h"
#include "ApplicationConfig.h"

MarkdownItalicAction::MarkdownItalicAction(QObject * parent)
	: BaseMarkdownAction(parent)
{
	 this->setCheckable(true);
}

MarkdownItalicAction::~MarkdownItalicAction()
{

}

long MarkdownItalicAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString MarkdownItalicAction::title()
{
	return tr("Italic");
}

QIcon MarkdownItalicAction::getIcon()
{
	QString image = QString::fromStdString(ApplicationConfig::instance().getIconPath())
		+ "/textitalic.png";
	return QIcon(image);
}

void MarkdownItalicAction::doExecute()
{
	textItalic();
}

void MarkdownItalicAction::textItalic()
{
	textEdit_->insertSymmetricalMark("*");
}