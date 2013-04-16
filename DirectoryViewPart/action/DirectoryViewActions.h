#ifndef DIRECTORYVIEWACTIONS_H
#define DIRECTORYVIEWACTIONS_H
#include "action/IAction.h"
#include "context/TableSelectionContext.h"

using UiUtils::IAction;
using UiUtils::IContext;
using UiUtils::TableSelectionContext;

class IDirectoryViewAction : public IAction
{
public:
	IDirectoryViewAction(const QString& text, QObject * parent);
	~IDirectoryViewAction();

	virtual	void	execute(IContext* context);

private:
	QString		getSelectItemPath();
protected:
	virtual	void  doExeute(const QString& filePath) = 0;

	bool		getNewFilePath(const QString& itemPath, QString& rtnPath);
	TableSelectionContext*	getContext();
	QString		convertToFolderPath(const QString& filePath);

private:
	TableSelectionContext*	selectContext_;
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
