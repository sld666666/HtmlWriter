#include "MarkdownAlignRightAction.h"
#include "ApplicationConfig.h"

MarkdownAlignRightAction::MarkdownAlignRightAction(QObject * parent)
	: BaseMarkdownAction(parent)
{
	 this->setCheckable(true);
}

MarkdownAlignRightAction::~MarkdownAlignRightAction()
{

}

long MarkdownAlignRightAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString MarkdownAlignRightAction::title()
{
	return tr("Right");
}

QIcon MarkdownAlignRightAction::getIcon()
{
	QString image = QString::fromStdString(ApplicationConfig::instance().getIconPath())
		+ "/textright.png";
	return QIcon(image);
}

void MarkdownAlignRightAction::doExecute()
{
	textAlign();
}

void MarkdownAlignRightAction::textAlign()
{
	textEdit_->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
}