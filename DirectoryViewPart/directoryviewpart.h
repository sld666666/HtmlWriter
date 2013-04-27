#ifndef DIRECTORYVIEWPART_H
#define DIRECTORYVIEWPART_H

#include "directoryviewpart_global.h"
#include "workbench/IViewPart.h"
#include "DirectoryViewWidget.h"

using namespace UiUtils;
using namespace service;

class   DirectoryViewPart : public IViewPart
{
public:
	DirectoryViewPart();
	~DirectoryViewPart();

	virtual long serviceId();

	virtual void reflesh(const QString& filePath);

	virtual void createPartControl(QWidget* parent);

public:
	DirectoryViewWidget*	getDirectoryViewWidget() const ;

private:
	DirectoryViewWidget*	directoryViewWidget_;

};

#endif // DIRECTORYVIEWPART_H
