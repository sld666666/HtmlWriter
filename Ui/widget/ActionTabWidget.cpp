#include <QTabBar>
#include "TextEdit.h"
#include "ActionTabWidget.h"
#include "EditorTabWidgetRightMenu.h"

namespace UiUtils{
	ActionTabWidget::ActionTabWidget(QWidget *parent)
		: QTabWidget (parent)
		, tabRightMenu_(new EditorTabWidgetRightMenu(this))
	{
		initConnect();
	}

	ActionTabWidget::~ActionTabWidget()
	{

	}

	void ActionTabWidget::initConnect()
	{
		QTabBar* tabBar = this->tabBar();
		if (tabBar){
			tabBar->setContextMenuPolicy(Qt::CustomContextMenu);
			connect(tabBar, SIGNAL(customContextMenuRequested(const QPoint))
				, this, SLOT(onShowRightMenuSlot(const QPoint)));
		}
	}

	void ActionTabWidget::onShowRightMenuSlot(const QPoint point)
	{
		if (tabRightMenu_.get()){
			tabRightMenu_->exec(QCursor::pos()); 
		}
	}

	void ActionTabWidget::addTextEditor(TextEdit* textEditor)
	{
		textEditors_.push_back(textEditor);
	}

	vector<TextEdit*> ActionTabWidget::getTextEditors()
	{
		return textEditors_;
	}

	void ActionTabWidget::removeCurTab()
	{
		TextEdit*curEditor = static_cast<TextEdit*>( this->currentWidget());
		if (curEditor){
			vector<TextEdit*>::iterator iter = std::find(textEditors_.begin(), textEditors_.end()
				, curEditor);
			if (iter != textEditors_.end()){
				textEditors_.erase(iter);
			}

			this->removeTab(this->currentIndex());
		}
	}

	void ActionTabWidget::removeExceptCurTab()
	{
		TextEdit*curEditor = static_cast<TextEdit*>( this->currentWidget());
		if (curEditor){
			vector<TextEdit*>::iterator iter = textEditors_.begin();
			while (iter != textEditors_.end())
			{
				if (curEditor != (*iter)){
					TextEdit* removedEditor = (*iter);
					iter = textEditors_.erase(iter);
					this->removeTab(this->indexOf(removedEditor));
				}else{
					++iter;
				}
			}
		}
	}
}

