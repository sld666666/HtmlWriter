/** 
* @file         DirectoryViewWidget.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-11
*/
#ifndef DIRECTORYVIEWWIDGET_H
#define DIRECTORYVIEWWIDGET_H

#include <QWidget>
#include <QFileSystemModel>

#include "ui_DirectoryViewWidget.h"
#include "directoryviewpart_global.h"

class DirectoryViewWidget : public QWidget
{
	Q_OBJECT

public:
	DirectoryViewWidget(QWidget *parent = 0);
	~DirectoryViewWidget();
	
private:
	void		initCtrl();
	void		innitConnect();

private slots:
	void		showRightMenuSlot(const QPoint point);
	void		newFolderSlot();
	void		newFileSlot();
	void		deleteSlot();
	void		onDoubleClickedItemSlot(const QModelIndex & modelIndex);

private:
	QString		getSelectItemPath();
	bool		getNewFilePath(const QString& itemPath, QString& rtnPath);

private:
	Ui::DirectoryViewWidget ui;
	QFileSystemModel fileSystemModel_;
};

#endif // DIRECTORYVIEWWIDGET_H
