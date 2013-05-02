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
	vector<MarkdownTextEdit*>::iterator iter =  std::find_if(
		markdownTextEdits_.begin(), markdownTextEdits_.end()
		, bind(&MarkdownTextEdit::isExist, _1, filePath));

	if (iter != markdownTextEdits_.end()){
		ui.tabWidgetEditor_->setCurrentWidget(*iter);
	}else{
		MarkdownTextEdit* textEdit = new MarkdownTextEdit(filePath, this);
		markdownTextEdits_.push_back(textEdit);
		ui.tabWidgetEditor_->insertTab(markdownTextEdits_.size()-1, textEdit, filePath);
		ui.tabWidgetEditor_->setCurrentWidget(textEdit);
		connect(textEdit, SIGNAL(textChanged())
		, this, SLOT(onEditorTextChangedSlot()));
	}
}

void MarkdownEditorWidget::onEditorTextChangedSlot()
{
	MarkdownTextEdit* textEdit = static_cast<MarkdownTextEdit*>(sender());
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
	MarkdownTextEdit* textEdit = static_cast<MarkdownTextEdit*>(
		ui.tabWidgetEditor_->currentWidget());
	if (textEdit){
		QString textPath = textEdit->getPath();
		data::DataManager::instance().writeData(textPath, textEdit->toPlainText());
	}
}


void MarkdownEditorWidget::doSave(MarkdownTextEdit* textEdit)
{
	if (!textEdit)return;

	QString textPath = textEdit->getPath();
	data::DataManager::instance().writeData(textPath);
}

