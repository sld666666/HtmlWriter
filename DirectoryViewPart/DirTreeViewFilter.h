#ifndef DIRTREEVIEWFILTER_H
#define DIRTREEVIEWFILTER_H

#include <QObject>
#include <QTreeView>
#include <QFileSystemModel>

class DirTreeViewFilter : public QObject
{
	Q_OBJECT

public:
	DirTreeViewFilter(QObject *parent=NULL);
	~DirTreeViewFilter();

	void	doFilter(QTreeView* treeView, QFileSystemModel& fileModel);

private:
	QModelIndex		getModelIndexInDirPath(QTreeView* treeView, const QString& dirPath);
	QModelIndex		findChildIndex(const QAbstractItemModel* model
		, QModelIndex parentIndex, QStringList& pathCombine);
	
};

#endif // DIRTREEVIEWFILTER_H
