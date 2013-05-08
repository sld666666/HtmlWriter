#include "MarkdownLinkAction.h"
#include "ApplicationConfig.h"

MarkdownLinkAction::MarkdownLinkAction(QObject * parent)
	: BaseMarkdownAction(parent)
{
	this->setShortcut(Qt::CTRL + Qt::Key_L);
}

MarkdownLinkAction::~MarkdownLinkAction()
{

}

long MarkdownLinkAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString MarkdownLinkAction::title()
{
	return tr("Link(ctrl+l)");
}

QIcon MarkdownLinkAction::getIcon()
{
	QString image = QString::fromStdString(ApplicationConfig::instance().getIconPath())
		+ "/mdLink.png";
	return QIcon(image);
}

void MarkdownLinkAction::doExecute()
{
	textLink();
}

void MarkdownLinkAction::textLink()
{
	textEdit_->insertSymmetricalMark("*");
}