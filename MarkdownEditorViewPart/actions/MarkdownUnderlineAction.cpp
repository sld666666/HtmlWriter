#include "MarkdownUnderlineAction.h"
#include "config/ApplicationConfig.h"

MarkdownUnderlineAction::MarkdownUnderlineAction(QObject * parent)
	: BaseMarkdownAction(parent)
{
	 this->setCheckable(true);
}

MarkdownUnderlineAction::~MarkdownUnderlineAction()
{

}

long MarkdownUnderlineAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString MarkdownUnderlineAction::title()
{
	return tr("Underline");
}

QIcon MarkdownUnderlineAction::getIcon()
{
	QString image = QString::fromStdString(utils::ApplicationConfig::instance().getIconPath())
		+ "/textunder.png";
	return QIcon(image);
}

void MarkdownUnderlineAction::doExecute()
{
	textUnderline();
}

void MarkdownUnderlineAction::textUnderline()
{
	QTextCharFormat fmt;
	fmt.setFontUnderline(this->isChecked());
	textEdit_->mergeFormatOnWordOrSelection(fmt);
}