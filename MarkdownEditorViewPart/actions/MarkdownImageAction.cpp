#include "MarkdownImageAction.h"
#include "config/ApplicationConfig.h"

MarkdownImageAction::MarkdownImageAction(QObject * parent)
	: BaseMarkdownAction(parent)
{
	this->setShortcut(Qt::CTRL + Qt::Key_I);
}

MarkdownImageAction::~MarkdownImageAction()
{

}

long MarkdownImageAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString MarkdownImageAction::title()
{
	return tr("Image(ctrl+i)");
}

QIcon MarkdownImageAction::getIcon()
{
	QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
		+ "/mdImage.png";
	return QIcon(image);
}

void MarkdownImageAction::doExecute()
{
	textImage();
}

void MarkdownImageAction::textImage()
{
	textEdit_->insertSymmetricalMark("*");
}