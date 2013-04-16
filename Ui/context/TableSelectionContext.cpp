#include "TableSelectionContext.h"

namespace UiUtils{

	TableSelectionContext::TableSelectionContext(const QAbstractItemView* itemView)
		: itemView_(itemView)
	{

	}

	TableSelectionContext::~TableSelectionContext()
	{

	}

	const QAbstractItemView* TableSelectionContext::getItemView() 
	{
		return itemView_;
	}
}