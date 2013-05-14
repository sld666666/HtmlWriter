#include "IContextMenu.h"

namespace UiUtils{
	IContextMenu::IContextMenu(IContextPtr context, const QString& title, QWidget * parent)
		: QMenu(title, parent)
		, context_(context)
	{
		initConnect();
	}


	IContextMenu::IContextMenu(QWidget * parent)
			: QMenu(parent)
	{
		initConnect();
	}

	IContextMenu::~IContextMenu()
	{
	}

	void  IContextMenu::initConnect()
	{
		connect(this, SIGNAL(aboutToShow()), this, SLOT(onAboutToShowSlot()));
	}

	void IContextMenu::add(IContextAction* action)
	{
		if (action){
			action->setText(action->title());
			this->addAction(action);
			connect(action, SIGNAL(triggered(bool))
				, this, SLOT(actionTriggeredSlot(bool)));
		}
	}

	void IContextMenu::actionTriggeredSlot(bool checked)
	{
		IContextAction* action = dynamic_cast<IContextAction*> (sender());
		if(action && context_.get())
		{
			action->execute(context_);
		}					
	}

	void IContextMenu::onAboutToShowSlot()
	{
		if (actions_.empty()){
			actions_ = getActions();
			for_each(actions_.begin(), actions_.end(), 
				bind(&IContextMenu::add, this, _1));
		}
	}
}