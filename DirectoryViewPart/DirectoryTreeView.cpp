#include "DirectoryTreeView.h"

DirectoryTreeView::DirectoryTreeView(QWidget *parent)
	: QTreeView(parent)
{
	initControls();
}

DirectoryTreeView::~DirectoryTreeView()
{

}

void DirectoryTreeView::focusOutEvent(QFocusEvent *event)
{
	selectionModel()->clear();
}

void DirectoryTreeView::initControls()
{
	this->setAnimated(false);
	this->setIndentation(25);
	this->setSortingEnabled(true);
	this->setContextMenuPolicy(Qt::CustomContextMenu);
	this->setColumnHidden(1, true);
	this->setColumnHidden(2, true);
	this->setColumnHidden(3, true);
}
