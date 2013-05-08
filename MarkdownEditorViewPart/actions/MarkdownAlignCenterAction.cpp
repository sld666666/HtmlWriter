#include "MarkdownAlignCenterAction.h"
#include "ApplicationConfig.h"

MarkdownAlignCenterAction::MarkdownAlignCenterAction(QObject * parent)
	: BaseMarkdownAction(parent)
{
	 this->setCheckable(true);
}

MarkdownAlignCenterAction::~MarkdownAlignCenterAction()
{

}

long MarkdownAlignCenterAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString MarkdownAlignCenterAction::title()
{
	return tr("center");
}

QIcon MarkdownAlignCenterAction::getIcon()
{
	QString image = QString::fromStdString(ApplicationConfig::instance().getIconPath())
		+ "/textcenter.png";
	return QIcon(image);
}

void MarkdownAlignCenterAction::doExecute()
{
	textAlign();
}

void MarkdownAlignCenterAction::textAlign()
{
	textEdit_->setAlignment(Qt::AlignHCenter);
}