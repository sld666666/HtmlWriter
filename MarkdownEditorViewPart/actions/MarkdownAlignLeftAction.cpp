#include "MarkdownAlignLeftAction.h"
#include "config/ApplicationConfig.h"

MarkdownAlignLeftAction::MarkdownAlignLeftAction(QObject * parent)
	: BaseMarkdownAction(parent)
{
	 this->setCheckable(true);
}

MarkdownAlignLeftAction::~MarkdownAlignLeftAction()
{

}

long MarkdownAlignLeftAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString MarkdownAlignLeftAction::title()
{
	return tr("Left");
}

QIcon MarkdownAlignLeftAction::getIcon()
{
	QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
		+ "/textleft.png";
	return QIcon(image);
}

void MarkdownAlignLeftAction::doExecute()
{
	textAlign();
}

void MarkdownAlignLeftAction::textAlign()
{
	 textEdit_->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
}