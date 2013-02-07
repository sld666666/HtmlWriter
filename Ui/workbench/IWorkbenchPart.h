#ifndef UIUTILS_IWORKBENCHPART_H
#define UIUTILS_IWORKBENCHPART_H

#include <QObject>

#include "ui_global.h"
namespace UiUtils{
	class IWorkbenchPart : public QObject
	{
		Q_OBJECT

	public:
		IWorkbenchPart(QObject *parent);
		~IWorkbenchPart();

	public:
		virtual void createPartControl(QWidget* parent) = 0;

	private:

	};
}


#endif // IWORKBENCHPART_H
