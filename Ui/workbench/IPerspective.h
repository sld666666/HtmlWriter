#ifndef UIUTILS_IPERSPECTIVE_H
#define UIUTILS_IPERSPECTIVE_H

#include <QObject>
#include <QGridLayout>

#include "ui_global.h"

namespace UiUtils{
	class UI_EXPORT IPerspective : public QObject
	{
		Q_OBJECT

	public:
		IPerspective(QObject *parent);
		~IPerspective();

	public:
		virtual void createInitialLayout(QGridLayout layout) = 0;

	private:

	};
}


#endif // IPERSPECTIVE_H
