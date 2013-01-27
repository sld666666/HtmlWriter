/** 
* @file         htmlwriter.h 
* @Synopsis       
* @author         sld666666@gmail.com 
* @version     1.0.0
* @date         27:1:2013  
*/
#ifndef HTMLWRITER_H
#define HTMLWRITER_H

#include <QFileSystemModel>
#include <QtGui/QMainWindow>
#include "ui_htmlwriter.h"

class HtmlWriter : public QMainWindow
{
	Q_OBJECT

public:
	HtmlWriter(QWidget *parent = 0, Qt::WFlags flags = 0);
	~HtmlWriter();

private slots:
	void	showRightMenuSlot(const QPoint point);
	void	newFolderSlot();
	void	newFileSlot();
	void	deleteSlot();
	void	onDoubleClickedItemSlot(const QModelIndex & modelIndex);
	void	onSaveSlot();

private:
	void	initFileInfoCtrl();
	void	innitConnect();
	QString getFullPath(const QModelIndex& modelIndx);
	bool	getNewFilePath(const QString& itemPath, QString& rtnPath);
	QString getSelectItemPath();
	QString makeDownToHtml(const QString& input);
private:
	Ui::HtmlWriterClass ui;
	QFileSystemModel model_;
	QString	workingItemPath_;
};

#endif // HTMLWRITER_H
