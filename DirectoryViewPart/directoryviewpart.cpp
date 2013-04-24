#include "DirectoryViewPart.h"

DirectoryViewPart::DirectoryViewPart()
: directoryViewWidget_(NULL)
{

}

DirectoryViewPart::~DirectoryViewPart()
{

}

void DirectoryViewPart::createPartControl(QWidget* parent)
{
	if (!parent)return;

	directoryViewWidget_ = new DirectoryViewWidget(parent);
	parent->layout()->addWidget(directoryViewWidget_);
}

void DirectoryViewPart::reflesh(const QString& filePath)
{

}
