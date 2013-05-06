#include "MarkdownEditorWidget.h"
#include "ViewServiceOperator.h"
#include "DataManager.h"

MarkdownEditorWidget::MarkdownEditorWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.tabWidgetEditor_->clear();
}

MarkdownEditorWidget::~MarkdownEditorWidget()
{

}

void MarkdownEditorWidget::reflesh(const QString& filePath)
{
	vector<TextEdit*>::iterator iter =  std::find_if(
		markdownTextEdits_.begin(), markdownTextEdits_.end()
		, bind(&TextEdit::isExist, _1, filePath));

	if (iter != markdownTextEdits_.end()){
		ui.tabWidgetEditor_->setCurrentWidget(*iter);
	}else{
		TextEdit* textEdit = new TextEdit(filePath, this);
		QString data;
		data::DataManager::instance().getString(filePath, data);
		textEdit->setText(data);
		markdownTextEdits_.push_back(textEdit);
		ui.tabWidgetEditor_->insertTab(markdownTextEdits_.size()-1, textEdit, filePath);
		ui.tabWidgetEditor_->setCurrentWidget(textEdit);
		connect(textEdit, SIGNAL(textChanged())
		, this, SLOT(onEditorTextChangedSlot()));
	}
}

void MarkdownEditorWidget::onEditorTextChangedSlot()
{
	TextEdit* textEdit = static_cast<TextEdit*>(sender());
	if (textEdit){
		QString textPath = textEdit->getPath();
		data::DataManager::instance().insert(textPath, textEdit->toPlainText());
		UiUtils::ViewServiceOperator::instance().viewReflesh(
			QString::fromStdString(BUNDELNAME), textPath);
	}
}

void MarkdownEditorWidget::save()
{
	for_each(markdownTextEdits_.begin(), markdownTextEdits_.end()
		, bind(&MarkdownEditorWidget::doSave, this, _1));
}

void MarkdownEditorWidget::saveAs(const QString& targetPath)
{
	TextEdit* textEdit = static_cast<TextEdit*>(
		ui.tabWidgetEditor_->currentWidget());
	if (textEdit){
		QString textPath = textEdit->getPath();
		data::DataManager::instance().writeData(textPath, textEdit->toPlainText());
	}
}


void MarkdownEditorWidget::doSave(TextEdit* textEdit)
{
	if (!textEdit)return;

	QString textPath = textEdit->getPath();
	data::DataManager::instance().writeData(textPath);
}

