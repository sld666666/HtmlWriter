#ifndef UIUTILS_IVIEWPART_H
#define UIUTILS_IVIEWPART_H

#include <QObject>

#include "ui_global.h"
#include "IWorkbenchPart.h"

namespace UiUtils{
	class IViewPart : public IWorkbenchPart
	{
		Q_OBJECT

	public:
		IViewPart(QObject *parent);
		~IViewPart();
	public:
		virtual void createPartControl(QWidget* parent) = 0;

	private:

	};
}



#endif // IVIEWPART_H
