#ifndef UIUTILS_IWORKBENCHPART_H
#define UIUTILS_IWORKBENCHPART_H

#include <QObject>
#include "ui_global.h"
#include "interface/IService.h"

using namespace service;
namespace UiUtils{
	class UI_EXPORT IWorkbenchPart : public IService
	{
	public:
		IWorkbenchPart();
		~IWorkbenchPart();

		virtual void	reflesh(const QString& filePath) = 0;

		virtual void	createPartControl(QWidget* parent) = 0;

	private:

	};
}


#endif // IWORKBENCHPART_H
