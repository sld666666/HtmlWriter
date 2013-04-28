#ifndef DIRECTORYVIEWACTIONS_H
#define DIRECTORYVIEWACTIONS_H
#include <QAbstractItemView>
#include "action/IAction.h"

using UiUtils::IAction;

class IDirectoryViewAction : public IAction
{
public:
	IDirectoryViewAction(QObject * parent);
	~IDirectoryViewAction();

	virtual	void	execute();
	virtual	long	serviceId();

private:
	QString		getSelectItemPath();
protected:
	virtual	void  doExeute(const QString& filePath) = 0;

	bool		getNewFilePath(const QString& itemPath, QString& rtnPath);
	QAbstractItemView*	parentItemView();
	QString		convertToFolderPath(const QString& filePath);

private:
	QAbstractItemView*	parentItemView_;;
};


class NewFolderAction : public IDirectoryViewAction
{
public:
	NewFolderAction(QObject * parent)
		: IDirectoryViewAction(parent){}

	~NewFolderAction(){}

	virtual QString title();

protected:
	virtual	void  doExeute(const QString& filePath);
};

class NewFileAction : public IDirectoryViewAction
{
public:
	NewFileAction(QObject * parent)
		: IDirectoryViewAction(parent){}

	~NewFileAction(){}

	virtual QString title() ;

protected:
	virtual	void  doExeute(const QString& filePath);
};

class DeleteAction : public IDirectoryViewAction
{
public:
	DeleteAction(QObject * parent)
		: IDirectoryViewAction(parent){}

	~DeleteAction(){}

	virtual QString title();

protected:
	virtual	void  doExeute(const QString& filePath);

private:
	bool	removeDir(const QString & dirName);
};




#endif // DIRECTORYVIEWACTIONS_H
