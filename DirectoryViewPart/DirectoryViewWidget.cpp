#include "StdAfx.h"
#include <QMenu>
#include <QSortFilterProxyModel>
#include "DirectoryViewWidget.h"
#include "FileCreator.h"

DirectoryViewWidget::DirectoryViewWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initCtrl();
	innitConnect();
}

DirectoryViewWidget::~DirectoryViewWidget()
{

}

void DirectoryViewWidget::initCtrl()
{
	QString test = "D:\\project\\";
	fileSystemModel_.setRootPath(test);
	QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel();
	proxyModel->setSourceModel(&fileSystemModel_);
	proxyModel->setFilterRegExp(QRegExp("d", Qt::CaseInsensitive,QRegExp::FixedString));
	proxyModel->setFilterKeyColumn(0);
	//ui.treeViewFileInfo_->setRootIndex(fileSystemModel_.index("E:\\project"));
	ui.treeViewFileInfo_->setModel(proxyModel);
	ui.treeViewFileInfo_->setAnimated(false);
	ui.treeViewFileInfo_->setIndentation(25);
	ui.treeViewFileInfo_->setSortingEnabled(true);
	ui.treeViewFileInfo_->setContextMenuPolicy(Qt::CustomContextMenu);
}

void DirectoryViewWidget::innitConnect()
{
	connect(ui.treeViewFileInfo_, SIGNAL(customContextMenuRequested(const QPoint))
		, this, SLOT(showRightMenuSlot(const QPoint)));

	connect(ui.treeViewFileInfo_, SIGNAL(doubleClicked(const QModelIndex &))
		, this, SLOT(onDoubleClickedItemSlot(const QModelIndex &)));
}

void DirectoryViewWidget::showRightMenuSlot(const QPoint point)
{
	QMenu *qMenu = new QMenu(ui.treeViewFileInfo_);

	QAction* acttionNewFolder = new QAction("&new folder",this);
	connect(acttionNewFolder, SIGNAL(triggered()), this, SLOT(newFolderSlot()));

	QAction* actionNewFile = new QAction("&new file", this);
	connect(actionNewFile, SIGNAL(triggered()), this, SLOT(newFileSlot()));

	QAction* actionDelete = new QAction("&delete", this);
	connect(actionDelete, SIGNAL(triggered()), this, SLOT(deleteSlot()));

	qMenu->addAction(acttionNewFolder);
	qMenu->addAction(actionNewFile);

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
}

QString DirectoryViewWidget::getSelectItemPath()
{
	QString itemPath("");
	QItemSelectionModel* selecitonModel = ui.treeViewFileInfo_->selectionModel();
	if (selecitonModel){
		QModelIndex modelIndex = selecitonModel->currentIndex();
		itemPath = fileSystemModel_.filePath(modelIndex); 
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
// 	QFile file(itemPath); // Read the text from a file
// 	if (file.open(QIODevice::ReadOnly)) {
// 		QTextStream stream(&file);
// 		ui.textEditText_->setText(stream.readAll());
// 	}
}



