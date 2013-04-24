#include <QWebFrame>
#include "HtmlPreviewWidget.h"
#include "DataManager.h"
#include "chadmarkdown.h"

HtmlPreviewWidget::HtmlPreviewWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//ui.webViewHtml_->page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
	//ui.webViewHtml_->page()->mainFrame()->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
}

HtmlPreviewWidget::~HtmlPreviewWidget()
{

}


void HtmlPreviewWidget::reflesh(const QString& filePath)
{
	QString datas;
	data::DataManager::instance().getString(filePath, datas);
	QString html = ChadMarkdown().makedownToHtml(datas);
	ui.webViewHtml_->setHtml(html.toAscii());
}
