
#include "DirTreeViewFilter.h"

DirTreeViewFilter::DirTreeViewFilter(QObject *parent)
	: QObject(parent)
{

}

DirTreeViewFilter::~DirTreeViewFilter()
{

}

void DirTreeViewFilter::doFilter(QTreeView* treeView
								 , QFileSystemModel& fileModel)
{
	if (!treeView)return;
	QString path = "D:\\temp";
	fileModel.setRootPath(path);
	fileModel.sort(0);
	QModelIndex curIndex = getModelIndexInDirPath(treeView, path);
	treeView->setRootIndex(curIndex);
 }

QModelIndex DirTreeViewFilter::getModelIndexInDirPath(QTreeView* treeView
													  , const QString& dirPath)
{
	QModelIndex rtnIndex;

	QStringList pathCombine = dirPath.split("\\");
	const QAbstractItemModel* model =  treeView->model();
	if (model){
		rtnIndex = findChildIndex(model, QModelIndex(), pathCombine);
	}

	return rtnIndex;
}

QModelIndex DirTreeViewFilter::findChildIndex(const QAbstractItemModel* model
											  , QModelIndex parentIndex
											  , QStringList& pathCombine)
{
	int rowCounts = model->rowCount(parentIndex); 
	QModelIndex rtnIndex(parentIndex);
	for (int i = 0; i < rowCounts; ++i)
	{
		QModelIndex modelIndx = model->index(i, 0, parentIndex);
		QString name = model->data(modelIndx).toString();
		if (!pathCombine.isEmpty()){
			bool found = (name == pathCombine.at(0));
			//as : IT(D:)
			if (!parentIndex.parent().isValid()){
				found = name.contains(pathCombine.at(0));
			}
			if (found){
				rtnIndex = modelIndx;
				pathCombine.removeFirst();
				rtnIndex = findChildIndex(model, rtnIndex, pathCombine);
			}
		}
	}

	return rtnIndex;
}



