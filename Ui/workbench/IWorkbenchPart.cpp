#include "IWorkbenchPart.h"

namespace UiUtils{
	IWorkbenchPart::IWorkbenchPart()
	{

	}

	IWorkbenchPart::~IWorkbenchPart()
	{

	}

	void IWorkbenchPart::sartService(BundleContext* context)
	{
		QWidget* parent = static_cast<QWidget*>(context->getParent());
		if (parent)createPartControl(parent);
	}
}


