#include <QMenu>
#include <QSortFilterProxyModel>
#include "DirectoryViewWidget.h"
#include "FileCreator.h"
#include "DirTreeViewFilter.h"
#include "DataManager.h"
#include "DirectoryViewPartConfig.h"

DirectoryViewWidget::DirectoryViewWidget(QWidget *parent)
	: QWidget(parent)
	, directoryTreeView_(new DirectoryTreeView(this))
{
	ui.setupUi(this);
	this->layout()->addWidget(directoryTreeView_);
	initCtrl();
	innitConnect();
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

void DirectoryViewWidget::innitConnect()
{
	connect(directoryTreeView_, SIGNAL(customContextMenuRequested(const QPoint))
		, this, SLOT(showRightMenuSlot(const QPoint)));

	connect(directoryTreeView_, SIGNAL(doubleClicked(const QModelIndex &))
		, this, SLOT(onDoubleClickedItemSlot(const QModelIndex &)));
}

void DirectoryViewWidget::showRightMenuSlot(const QPoint point)
{
	QMenu *qMenu = new QMenu(directoryTreeView_);

	QAction* acttionNewFolder = new QAction("&new folder",this);
	connect(acttionNewFolder, SIGNAL(triggered()), this, SLOT(newFolderSlot()));

	QAction* actionNewFile = new QAction("&new file", this);
	connect(actionNewFile, SIGNAL(triggered()), this, SLOT(newFileSlot()));

	QAction* actionDelete = new QAction("&delete", this);
	connect(actionDelete, SIGNAL(triggered()), this, SLOT(deleteSlot()));

	qMenu->addAction(acttionNewFolder);
	qMenu->addAction(actionNewFile);
	qMenu->addAction(actionDelete);

	qMenu->exec(QCursor::pos()); //在鼠标点击的位置显示鼠标右键菜单
}

void DirectoryViewWidget::newFolderSlot()
{
	QString newFilePath = getSelectItemPath();
	if ((!newFilePath.isEmpty()) 
		&& getNewFilePath(newFilePath, newFilePath)){
			if (!QDir().mkdir(newFilePath)){
			}	
	}	
}

void DirectoryViewWidget::newFileSlot()
{
	QString newFilePath = getSelectItemPath();
	if ((!newFilePath.isEmpty()) 
		&& getNewFilePath(newFilePath, newFilePath)){
			QFile file(newFilePath);
			if(file.open(QFile::ReadWrite|QFile::Text)){
				file.close();  
			}
	}	
}

void DirectoryViewWidget::deleteSlot()
{
	QString filePath = getSelectItemPath();
	if (QFile::exists(filePath)){
		QFile::remove(filePath);
	}
}

QString DirectoryViewWidget::getSelectItemPath()
{
	QString itemPath("");
	QItemSelectionModel* selecitonModel = directoryTreeView_->selectionModel();
	if (selecitonModel){
		if (selecitonModel->selectedRows().isEmpty()){
			QString path = QString::fromStdString(DirectoryViewPartConfig::
				instance().getValue(DirectoryViewPartConfigKey::LOCATION));
			return path;
		}
		else{
			QModelIndex modelIndex = selecitonModel->currentIndex();
			itemPath = fileSystemModel_.filePath(modelIndex); 
		}
		
	}
	return itemPath;
}

bool DirectoryViewWidget::getNewFilePath(const QString& itemPath
									, QString& rtnPath)
{
	bool rtn(false);
	rtnPath = itemPath;
	FileCreator fileCreator(rtnPath, this);
	fileCreator.show();
	if (QDialog::Accepted == fileCreator.exec()){
		rtnPath = fileCreator.filePath();
	 		rtn = true;
	}

	return rtn;
}

void DirectoryViewWidget::onDoubleClickedItemSlot(const QModelIndex & modelIndex)
{
	QString itemPath = fileSystemModel_.filePath(modelIndex); 
	DirTreeViewFilter().doFilter(directoryTreeView_, fileSystemModel_);
	data::DataManager::instance().addData(itemPath.toStdString());
}

void DirectoryViewWidget::filterFileDirs()
{
	DirTreeViewFilter().doFilter(directoryTreeView_, fileSystemModel_);
}



