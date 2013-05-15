#include "MarkdownEditorWidget.h"
#include "ViewServiceOperator.h"
#include "DataManager.h"
#include "widget/TextEdit.h"
#include "config/MarkdownViewPartConfig.h"

MarkdownEditorWidget::MarkdownEditorWidget(QWidget *parent)
	: QWidget(parent)
	, tabWidgetEditor_(new ActionTabWidget(this))
{
	ui.setupUi(this);
	this->layout()->addWidget(tabWidgetEditor_);
	this->installEventFilter(this);
	tabWidgetEditor_->clear();
	markdownViewPartConfigs_ = MarkdownViewPartConfig::readListConfig();
	for_each(markdownViewPartConfigs_.begin(), markdownViewPartConfigs_.end()
		, bind(&MarkdownEditorWidget::configOpen, this, _1));
}

MarkdownEditorWidget::~MarkdownEditorWidget()
{
	saveConfig();
}

void MarkdownEditorWidget::configOpen(const MarkdownViewPartConfigPtr config)
{
	if (!config)return;

	QString filePath = config->opened();
	reflesh(filePath);
}

void MarkdownEditorWidget::reflesh(const QString& filePath)
{
	vector<TextEdit*> markdownTextEdits = tabWidgetEditor_->getTextEditors();

	vector<TextEdit*>::iterator iter =  std::find_if(
		markdownTextEdits.begin(), markdownTextEdits.end()
		, bind(&TextEdit::isExist, _1, filePath));

	if (iter != markdownTextEdits.end()){
		tabWidgetEditor_->setCurrentWidget(*iter);
	}else{
		TextEdit* textEdit = new TextEdit(filePath, this);
		QString data;
		data::DataManager::instance().getString(filePath, data);
		textEdit->setText(data);
		tabWidgetEditor_->addTextEditor(textEdit);
		tabWidgetEditor_->insertTab(markdownTextEdits.size()-1, textEdit, filePath);
		tabWidgetEditor_->setCurrentWidget(textEdit);
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
	vector<TextEdit*> markdownTextEdits = tabWidgetEditor_->getTextEditors();
	for_each(markdownTextEdits.begin(), markdownTextEdits.end()
		, bind(&MarkdownEditorWidget::doSave, this, _1));
}

void MarkdownEditorWidget::saveAs(const QString& targetPath)
{
	TextEdit* textEdit = static_cast<TextEdit*>(
		tabWidgetEditor_->currentWidget());
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

TextEdit* MarkdownEditorWidget::getCurTextEditor()
{
	TextEdit* textEdit = static_cast<TextEdit*>(
		tabWidgetEditor_->currentWidget());

	return textEdit;
}


void MarkdownEditorWidget::saveConfig()
{
	vector<TextEdit*> markdownTextEdits = tabWidgetEditor_->getTextEditors();
	markdownViewPartConfigs_.clear();
	foreach(TextEdit* textEditor, markdownTextEdits){
		MarkdownViewPartConfigPtr config(new MarkdownViewPartConfig);
		config->setOpened(textEditor->getPath());
		markdownViewPartConfigs_.push_back(config);
	}
	MarkdownViewPartConfig::writeListConfig(markdownViewPartConfigs_);
}