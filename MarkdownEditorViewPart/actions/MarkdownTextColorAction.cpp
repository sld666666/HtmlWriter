#include <QColorDialog>
#include "MarkdownTextColorAction.h"
#include "widget/TextEdit.h"

MarkdownTextColorAction::MarkdownTextColorAction(QObject * parent)
	: BaseMarkdownAction(parent)
{
	 this->setCheckable(true);
}

MarkdownTextColorAction::~MarkdownTextColorAction()
{

}

long MarkdownTextColorAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString MarkdownTextColorAction::title()
{
	return tr("Color");
}

QIcon MarkdownTextColorAction::getIcon()
{
	QPixmap pix(16, 16);
	pix.fill(Qt::black);

	return QIcon(pix);
}

void MarkdownTextColorAction::doExecute()
{
	textColor();
}

void MarkdownTextColorAction::textColor()
{
	QColor col = QColorDialog::getColor(textEdit_->textColor(), this->parentWidget());
	if (!col.isValid())
		return;
	QTextCharFormat fmt;
	fmt.setForeground(col);
	textEdit_->mergeFormatOnWordOrSelection(fmt);
	colorChanged(col);;
}

void MarkdownTextColorAction::colorChanged(const QColor &c)
{
	QPixmap pix(16, 16);
	pix.fill(c);
	this->setIcon(pix);
}