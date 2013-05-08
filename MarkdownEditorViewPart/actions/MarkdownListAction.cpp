#include "MarkdownListAction.h"
#include "config/ApplicationConfig.h"

MarkdownListAction::MarkdownListAction(QObject * parent)
	: BaseMarkdownAction(parent)
{
	this->setShortcut(Qt::CTRL + Qt::Key_U);
}

MarkdownListAction::~MarkdownListAction()
{

}

long MarkdownListAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString MarkdownListAction::title()
{
	return tr("List(ctrl+u)");
}

QIcon MarkdownListAction::getIcon()
{
	QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
		+ "/mdList.png";
	return QIcon(image);
}

void MarkdownListAction::doExecute()
{
	textList();
}

void MarkdownListAction::textList()
{
	textEdit_->insertEnter();
	textEdit_->insertMark("-", " ");
}