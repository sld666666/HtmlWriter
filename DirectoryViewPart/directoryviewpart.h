#ifndef DIRECTORYVIEWPART_H
#define DIRECTORYVIEWPART_H

#include "directoryviewpart_global.h"
#include "workbench/ViewPart.h"
#include "DirectoryViewWidget.h"

using namespace UiUtils;

class   DirectoryViewPart : public QObject
{
	Q_OBJECT
public:
	DirectoryViewPart();
	~DirectoryViewPart();

public:
	virtual void createPartControl(QWidget* parent);

private:
	DirectoryViewWidget*	directoryViewWidget_;

};

#endif // DIRECTORYVIEWPART_H
