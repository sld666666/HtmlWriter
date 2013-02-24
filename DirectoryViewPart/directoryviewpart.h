#ifndef DIRECTORYVIEWPART_H
#define DIRECTORYVIEWPART_H

#include "directoryviewpart_global.h"
#include "workbench/ViewPart.h"

using namespace UiUtils;
class DIRECTORYVIEWPART_EXPORT DirectoryViewPart : public ViewPart
{
	Q_OBJECT
public:
	DirectoryViewPart();
	~DirectoryViewPart();

public:
	virtual void createPartControl(QWidget* parent);

private:

};

#endif // DIRECTORYVIEWPART_H
