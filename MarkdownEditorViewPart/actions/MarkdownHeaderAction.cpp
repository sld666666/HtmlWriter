#include "MarkdownHeaderAction.h"
#include "ApplicationConfig.h"

MarkdownHeaderAction::MarkdownHeaderAction(QObject * parent)
	: BaseMarkdownAction(parent)
{
	 //this->setCheckable(true);
	this->setShortcut(Qt::CTRL + Qt::Key_H);
}

MarkdownHeaderAction::~MarkdownHeaderAction()
{

}

long MarkdownHeaderAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString MarkdownHeaderAction::title()
{
	return tr("Header(ctlr+h)");
}

QIcon MarkdownHeaderAction::getIcon()
{
	QString image = QString::fromStdString(ApplicationConfig::instance().getIconPath())
		+ "/mdHeader.png";
	return QIcon(image);
}

void MarkdownHeaderAction::doExecute()
{
	textHeader();
}

void MarkdownHeaderAction::textHeader()
{
	textEdit_->insertMark("##", " ");
}