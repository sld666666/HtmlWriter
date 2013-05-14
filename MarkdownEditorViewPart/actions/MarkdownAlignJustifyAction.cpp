#include "MarkdownAlignJustifyAction.h"
#include "config/ApplicationConfig.h"
#include "widget/TextEdit.h"

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
	QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
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