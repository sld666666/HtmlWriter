#ifndef UIUTILS_VIEWPART_H
#define UIUTILS_VIEWPART_H

#include <QObject>
#include "ui_global.h"
#include "IViewPart.h"

namespace UiUtils{
	class UI_EXPORT ViewPart : public IViewPart
	{

	public:
		ViewPart();
		~ViewPart();

	protected:
		virtual void createPartControl(QWidget* parent);

	private:

	};
}


#endif // VIEWPART_H
