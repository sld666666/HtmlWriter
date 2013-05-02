/** 
* @file         IEditorPart.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-6
*/
#ifndef UIUTILS_IEDITORPART_H
#define UIUTILS_IEDITORPART_H

#include <QObject>

#include "ui_global.h"
#include "IWorkbenchPart.h"

namespace UiUtils{
	class UI_EXPORT IEditorPart : public IWorkbenchPart
	{
	public:
		IEditorPart();
		~IEditorPart();

		virtual void doSave() = 0;
		virtual void doSaveAs(const QString& targetPath) = 0;

	};
}



#endif // IEDITORPART_H
