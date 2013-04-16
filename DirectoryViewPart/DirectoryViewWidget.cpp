#include <QMenu>
#include <QSortFilterProxyModel>
#include "DirectoryViewWidget.h"
#include "DirTreeViewFilter.h"
#include "DataManager.h"
#include "context/TableSelectionContext.h"
#include "action/DirectoryViewActions.h"

using UiUtils::TableSelectionContext;

DirectoryViewWidget::DirectoryViewWidget(QWidget *parent)
	: QWidget(parent)
	, directoryTreeView_(new DirectoryTreeView(this))
	, tableMenu_(new Menu(new TableSelectionContext(directoryTreeView_), this))
{
	ui.setupUi(this);
	this->layout()->addWidget(directoryTreeView_);
	initCtrl();
	innitConnect();
	initTableMenu();
}

DirectoryViewWidget::~DirectoryViewWidget()
{

}

void DirectoryViewWidget::initCtrl()
{
	directoryTreeView_->setModel(&fileSystemModel_);
	directoryTreeView_->onlyShowFisrtColumn();
	filterFileDirs();
}

void DirectoryViewWidget::initTableMenu()
{
	if (tableMenu_){
		tableMenu_->add(new NewFolderAction("&new folder",this));
		tableMenu_->add(new NewFileAction("&new file",this));
		tableMenu_->add(new DeleteAction("&delete",this));
	}
}

void DirectoryViewWidget::innitConnect()
{
	connect(directoryTreeView_, SIGNAL(customContextMenuRequested(const QPoint))
		, this, SLOT(showRightMenuSlot(const QPoint)));

	connect(directoryTreeView_, SIGNAL(doubleClicked(const QModelIndex &))
		, this, SLOT(onDoubleClickedItemSlot(const QModelIndex &)));
}

void DirectoryViewWidget::showRightMenuSlot(const QPoint point)
{
	tableMenu_->exec(QCursor::pos()); //在鼠标点击的位置显示鼠标右键菜单
}

void DirectoryViewWidget::onDoubleClickedItemSlot(const QModelIndex & modelIndex)
{
	QString itemPath = fileSystemModel_.filePath(modelIndex); 
	data::DataManager::instance().addData(itemPath.toStdString());
}

void DirectoryViewWidget::filterFileDirs()
{
	DirTreeViewFilter().doFilter(directoryTreeView_, fileSystemModel_);
}



