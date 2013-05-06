#include "RichEditorWidget.h"
#include "DataManager.h"
#include "ViewServiceOperator.h"

using namespace data;

RichEditorWidget::RichEditorWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.tabWidgetEditor_->clear();
}

RichEditorWidget::~RichEditorWidget()
{

}

void RichEditorWidget::reflesh(const QString& filePath)
{
	vector<TextEdit*>::iterator iter =  std::find_if(
		textEdits_.begin(), textEdits_.end()
		, bind(&TextEdit::isExist, _1, filePath));

	if (iter != textEdits_.end()){
		ui.tabWidgetEditor_->setCurrentWidget(*iter);
	}else{
		TextEdit* textEdit = new TextEdit(filePath, this);
		QString data;
		data::DataManager::instance().getString(filePath, data);
		textEdit->setText(data);
		textEdits_.push_back(textEdit);
		ui.tabWidgetEditor_->insertTab(textEdits_.size()-1, textEdit, filePath);
		ui.tabWidgetEditor_->setCurrentWidget(textEdit);
		connect(textEdit, SIGNAL(textChanged())
			, this, SLOT(onEditorTextChangedSlot()));
	}
}

void RichEditorWidget::save()
{
	for_each(textEdits_.begin(), textEdits_.end()
		, bind(&RichEditorWidget::doSave, this, _1));
}

void RichEditorWidget::saveAs(const QString& targetPath)
{
	TextEdit* textEdit = static_cast<TextEdit*>(
		ui.tabWidgetEditor_->currentWidget());
	if (textEdit){
		QString textPath = textEdit->getPath();
		data::DataManager::instance().writeData(textPath, textEdit->toPlainText());
	}
}

void RichEditorWidget::onEditorTextChangedSlot()
{
	TextEdit* textEdit = static_cast<TextEdit*>(sender());
	if (textEdit){
		QString textPath = textEdit->getPath();
		data::DataManager::instance().insert(textPath, textEdit->toPlainText());
		UiUtils::ViewServiceOperator::instance().viewReflesh(
			QString::fromStdString(RICHEDITORBUNDELNAME), textPath);
	}
}

void RichEditorWidget::doSave(TextEdit* textEdit)
{
	if (!textEdit)return;

	QString textPath = textEdit->getPath();
	data::DataManager::instance().writeData(textPath);
}

TextEdit* RichEditorWidget::getCurrentEditor()
{
	TextEdit* textEdit = static_cast<TextEdit*>(
		ui.tabWidgetEditor_->currentWidget());
	return textEdit;
}
