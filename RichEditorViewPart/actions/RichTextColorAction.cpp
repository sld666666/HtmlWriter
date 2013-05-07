#include <QColorDialog>
#include "RichTextColorAction.h"
#include "ApplicationConfig.h"

RichTextColorAction::RichTextColorAction(QObject * parent)
	: BaseRichAction(parent)
{
	 this->setCheckable(true);
}

RichTextColorAction::~RichTextColorAction()
{

}

long RichTextColorAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

QString RichTextColorAction::title()
{
	return tr("Color");
}

QIcon RichTextColorAction::getIcon()
{
	QPixmap pix(16, 16);
	pix.fill(Qt::black);

	return QIcon(pix);
}

void RichTextColorAction::doExecute()
{
	textColor();
}

void RichTextColorAction::textColor()
{
	QColor col = QColorDialog::getColor(textEdit_->textColor(), this->parentWidget());
	if (!col.isValid())
		return;
	QTextCharFormat fmt;
	fmt.setForeground(col);
	textEdit_->mergeFormatOnWordOrSelection(fmt);
	colorChanged(col);;
}

void RichTextColorAction::colorChanged(const QColor &c)
{
	QPixmap pix(16, 16);
	pix.fill(c);
	this->setIcon(pix);
}