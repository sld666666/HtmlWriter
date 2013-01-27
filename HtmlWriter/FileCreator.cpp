#include <QDir>
#include "FileCreator.h"

FileCreator::FileCreator(const QString& pathInfo
						 ,QWidget *parent)
	: QDialog(parent)
	, filePath_(pathInfo)
{
	ui.setupUi(this);
	ui.labelPath_->setText(pathInfo);
	initConnect();
}

FileCreator::~FileCreator()
{

}

void FileCreator::initConnect()
{
	connect(ui.btnOk_, SIGNAL(pressed())
		, this, SLOT(onOKSlot()));

	connect(ui.btnCancel_, SIGNAL(pressed())
		, this, SLOT(onCancalSlot()));

// 	connect(ui.lineEditNewName_, SIGNAL(textChanged(const QString&))
// 		, this, SLOT(onNameChangedSlot(const QString&)));
}

void FileCreator::onOKSlot()
{
	accept();
}

void FileCreator::onCancalSlot()
{
	reject();
}

QString FileCreator::filePath()
{
	return filePath_ + QDir::separator() + ui.lineEditNewName_->text();
}

void FileCreator::onNameChangedSlot(const QString& text)
{
	//filePath_ = filePath_
}
