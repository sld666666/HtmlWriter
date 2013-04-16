#ifndef UIUTILS_IVIEWPART_H
#define UIUTILS_IVIEWPART_H

#include <QObject>

#include "ui_global.h"
#include "IWorkbenchPart.h"

namespace UiUtils{
	class UI_EXPORT IViewPart : public IWorkbenchPart
	{
	public:
		IViewPart();
		~IViewPart();
	protected:
		virtual void createPartControl(QWidget* parent) = 0;

	private:

	};
}



#endif // IVIEWPART_H
