#include <QFileSystemModel>
#include <QDir>

#include "DirectoryViewActions.h"
#include "DirectoryViewPartConfig.h"
#include "FileCreator.h"
#include "ServiceManager.h"
#include "../DirectoryViewPart.h"

IDirectoryViewAction::IDirectoryViewAction(QObject * parent)
	: IAction(parent)
{
}

IDirectoryViewAction::~IDirectoryViewAction()
{

}

long IDirectoryViewAction::serviceId()
{
	return RegisteredSeviceID::RSI_UNREGISTER;
}

void IDirectoryViewAction::execute()
{
	IService* service = ServiceManager::instance().find(DIR_VIEW_SERVICENAME);
	DirectoryViewPart* dirViewPart = static_cast<DirectoryViewPart*>(service);
	if (dirViewPart){
		parentItemView_ = dirViewPart->getDirectoryViewWidget()->getItemView();
		if (parentItemView_){
			QString filePath = getSelectItemPath(); 
			doExeute(filePath);
		}
	}
}

QAbstractItemView*	IDirectoryViewAction::parentItemView()
{
	return parentItemView_;
}

QString IDirectoryViewAction::getSelectItemPath()
{
	QString itemPath("");
	QItemSelectionModel* selecitonModel = parentItemView()->selectionModel();
	if (selecitonModel){
		if (selecitonModel->selectedRows().isEmpty()){
			QString path = QString::fromStdString(DirectoryViewPartConfig::
				instance().getValue(DirectoryViewPartConfigKey::LOCATION));
			return path;
		}
		else{
			QModelIndex modelIndex = selecitonModel->currentIndex();
			QFileSystemModel* fileSystemModel = static_cast<QFileSystemModel*>(
				parentItemView()->model());
			if (fileSystemModel){
				itemPath = fileSystemModel->filePath(modelIndex); 
			}	
		}
	}
	return itemPath;
}

bool IDirectoryViewAction::getNewFilePath(const QString& itemPath
										 , QString& rtnPath)
{
	bool rtn(false);
	rtnPath = itemPath;
	FileCreator fileCreator(rtnPath, parentItemView()->parentWidget());

	fileCreator.show();
	if (QDialog::Accepted == fileCreator.exec()){
		rtnPath = fileCreator.filePath();
		rtn = true;
	}

	return rtn;
}

QString IDirectoryViewAction::convertToFolderPath(const QString& filePath)
{
	QString rtn(filePath);
	QFileInfo fileInfo(filePath);
	if (!fileInfo.isDir()){
		rtn.remove("/"+fileInfo.fileName());
	}
	return rtn;
}

QString NewFolderAction::title()
{
	return tr("&new folder");
}

QString NewFileAction::title()
{
	return tr("&new file");
}

QString DeleteAction::title()
{
	return tr("&delete");
}

void NewFolderAction::doExeute(const QString& filePath)
{
	QString newFilePath = convertToFolderPath(filePath);
	if ((!newFilePath.isEmpty()) 
		&& getNewFilePath(newFilePath, newFilePath)){
			if (!QDir().mkdir(newFilePath)){
			}	
	}	
}

void NewFileAction::doExeute(const QString& filePath)
{
	QString newFilePath = convertToFolderPath(filePath);
	if ((!newFilePath.isEmpty()) 
		&& getNewFilePath(newFilePath, newFilePath)){
			QFile file(newFilePath);
			if(file.open(QFile::ReadWrite|QFile::Text)){
				file.close();  
			}
	}	
}

void DeleteAction::doExeute(const QString& filePath)
{
	if (QFile::exists(filePath)){
		QFileInfo fileInfo(filePath);
		if (!fileInfo.isDir()){
			QFile::remove(filePath);
		}else{
			removeDir(filePath);
		}
		
	}
}

bool DeleteAction::removeDir(const QString & dirName)
{
	bool result;
	QDir dir(dirName);

	if (dir.exists(dirName)) {
		Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot|QDir::System|QDir::Hidden  
			| QDir::AllDirs | QDir::Files
			, QDir::DirsFirst)) {

			if (info.isDir()) {
				result = removeDir(info.absoluteFilePath());
			}
			else {
				result = QFile::remove(info.absoluteFilePath());
			}

			if (!result) {
				return result;
			}
		}
		result = dir.rmdir(dirName);
	}
	return result;
}