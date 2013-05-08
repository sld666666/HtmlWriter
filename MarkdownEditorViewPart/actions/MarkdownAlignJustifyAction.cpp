#include "MarkdownAlignJustifyAction.h"
#include "ApplicationConfig.h"

MarkdownAlignJustifyAction::MarkdownAlignJustifyAction(QObject * parent)
	: BaseMarkdownAction(parent)
{
	 this->setCheckable(true);
}

MarkdownAlignJustifyAction::~MarkdownAlignJustifyAction()
{

}

long MarkdownAlignJustifyAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString MarkdownAlignJustifyAction::title()
{
	return tr("Justify");
}

QIcon MarkdownAlignJustifyAction::getIcon()
{
	QString image = QString::fromStdString(ApplicationConfig::instance().getIconPath())
		+ "/textjustify.png";
	return QIcon(image);
}

void MarkdownAlignJustifyAction::doExecute()
{
	textAlign();
}

void MarkdownAlignJustifyAction::textAlign()
{
	textEdit_->setAlignment(Qt::AlignJustify);
}