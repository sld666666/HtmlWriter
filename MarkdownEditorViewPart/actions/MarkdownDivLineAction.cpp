#include "MarkdownDivLineAction.h"
#include "config/ApplicationConfig.h"

MarkdownDivLineAction::MarkdownDivLineAction(QObject * parent)
	: BaseMarkdownAction(parent)
{
	this->setShortcut(Qt::CTRL + Qt::Key_D);
}

MarkdownDivLineAction::~MarkdownDivLineAction()
{

}

long MarkdownDivLineAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString MarkdownDivLineAction::title()
{
	return tr("DivLine(ctrl+d)");
}

QIcon MarkdownDivLineAction::getIcon()
{
	QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
		+ "/mdDivLine.png";
	return QIcon(image);
}

void MarkdownDivLineAction::doExecute()
{
	textDivLine();
}

void MarkdownDivLineAction::textDivLine()
{
	textEdit_->insertEnter();
	textEdit_->insertMark("------", " ");
}