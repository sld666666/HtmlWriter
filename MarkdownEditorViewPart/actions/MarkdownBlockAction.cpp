#include "MarkdownBlockAction.h"
#include "config/ApplicationConfig.h"
#include "widget/TextEdit.h"

MarkdownBlockAction::MarkdownBlockAction(QObject * parent)
	: BaseMarkdownAction(parent)
{
	this->setShortcut(Qt::CTRL + Qt::Key_B);
}

MarkdownBlockAction::~MarkdownBlockAction()
{

}

long MarkdownBlockAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString MarkdownBlockAction::title()
{
	return tr("Block(ctrl+b)");
}

QIcon MarkdownBlockAction::getIcon()
{
	QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
		+ "/mdBlock.png";
	return QIcon(image);
}

void MarkdownBlockAction::doExecute()
{
	textBlock();
}

void MarkdownBlockAction::textBlock()
{
	textEdit_->insertMark(">", " ");
}