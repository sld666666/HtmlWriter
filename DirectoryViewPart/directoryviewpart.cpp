#include "stdafx.h"
#include "DirectoryViewPart.h"

DirectoryViewPart::DirectoryViewPart()
:QObject(NULL)
, directoryViewWidget_(NULL)
{

}

DirectoryViewPart::~DirectoryViewPart()
{

}

void DirectoryViewPart::createPartControl(QWidget* parent)
{
	if (!parent)return;

	directoryViewWidget_ = new DirectoryViewWidget(parent);
}
