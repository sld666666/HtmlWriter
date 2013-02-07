#ifndef DIRECTORYVIEWPART_H
#define DIRECTORYVIEWPART_H

#include <QObject>
#include "workbench/ViewPart.h"

using namespace UiUtils;

class DirectoryViewPart : public ViewPart
{
	Q_OBJECT

public:
	DirectoryViewPart(QObject *parent);
	~DirectoryViewPart();
public:
	virtual void createPartControl(QWidget* parent);
private:
	
};

#endif // DIRECTORYVIEWPART_H
