#include "UiHelper.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

namespace UiUtils{
	UiHelper::UiHelper(QObject *parent)
		: QObject(parent)
	{

	}

	UiHelper::~UiHelper()
	{

	}

	void UiHelper::updateWidgetWithHLayout(QWidget* widget)
	{
		QHBoxLayout* layout=new QHBoxLayout(widget);

		widget->setContentsMargins(0,0,0,0);
		layout->setContentsMargins(0,0,0,0);

		widget->setLayout(layout);
	}

	void UiHelper::updateWidgetWithVLayout(QWidget* widget)
	{
		QVBoxLayout* layout=new QVBoxLayout(widget);

		widget->setContentsMargins(0,0,0,0);
		layout->setContentsMargins(0,0,0,0);

		widget->setLayout(layout);
	}

}
