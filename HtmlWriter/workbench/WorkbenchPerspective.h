#ifndef WORKBENCHPERSPECTIVE_H
#define WORKBENCHPERSPECTIVE_H

#include <QObject>
#include "workbench/IPerspective.h"

using UiUtils::IPerspective;

class WorkbenchPerspective : public IPerspective
{
	Q_OBJECT

public:
	WorkbenchPerspective(QObject *parent);
	~WorkbenchPerspective();

	virtual void createInitialLayout(QGridLayout layout);
private:
	
};

#endif // WORKBENCHPERSPECTIVE_H
