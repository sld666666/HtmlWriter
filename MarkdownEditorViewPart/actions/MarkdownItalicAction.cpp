#include "MarkdownItalicAction.h"
#include "config/ApplicationConfig.h"
#include "widget/TextEdit.h"

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
	QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
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