#ifndef DIRECTORYVIEWACTIONS_H
#define DIRECTORYVIEWACTIONS_H
#include <QAbstractItemView>
#include "action/IAction.h"

using UiUtils::IAction;

class IDirectoryViewAction : public IAction
{
public:
	IDirectoryViewAction(const QString& text, QObject * parent);
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
	NewFolderAction(const QString& text, QObject * parent)
		: IDirectoryViewAction(text, parent){}

	~NewFolderAction(){}

protected:
	virtual	void  doExeute(const QString& filePath);
};

class NewFileAction : public IDirectoryViewAction
{
public:
	NewFileAction(const QString& text, QObject * parent)
		: IDirectoryViewAction(text, parent){}

	~NewFileAction(){}

protected:
	virtual	void  doExeute(const QString& filePath);
};

class DeleteAction : public IDirectoryViewAction
{
public:
	DeleteAction(const QString& text, QObject * parent)
		: IDirectoryViewAction(text, parent){}

	~DeleteAction(){}

protected:
	virtual	void  doExeute(const QString& filePath);

private:
	bool	removeDir(const QString & dirName);
};




#endif // DIRECTORYVIEWACTIONS_H
