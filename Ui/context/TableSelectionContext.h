/** 
* @file         TableSelectionContext.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-16
*/
#ifndef UIUTILS_TABLESELECTIONCONTEXTS_H
#define UIUTILS_TABLESELECTIONCONTEXTS_H
#include <QAbstractItemView>

#include "IContext.h"

namespace UiUtils{

	class UI_EXPORT TableSelectionContext : public IContext
	{

	public:
		TableSelectionContext(const QAbstractItemView* itemView);
		~TableSelectionContext();
		
		const QAbstractItemView* getItemView() ;
	public:
		const QAbstractItemView*		itemView_;
	};

}


#endif // UIUTILS_TABLESELECTIONCONTEXTS_H
