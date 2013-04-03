#include <QDir>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <sstream>

#include "htmlwriter.h"
#include "FileCreator.h"
#include "markdown/markdown-tokens.h"
#include "action/ActionConfigurer.h"
#include "ServiceLoader.h"

using namespace Ui;

HtmlWriter::HtmlWriter(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	initFileInfoCtrl();
	innitConnect();

	QString test = this->objectName();
	service::ServiceLoader serviceLoader;
	serviceLoader.loadPlugins();

	ActionConfigurerPtr actionConfig(new ActionConfigurer((ui.menuBar)));
	appActionBarAdvisor_ = (ApplicationActionBarAdvisorPtr(
		new ApplicationActionBarAdvisor(actionConfig)));
}

HtmlWriter::~HtmlWriter()
{
}
void HtmlWriter::setObjectName(const QString &name)
{

}
void HtmlWriter::initFileInfoCtrl()
{
	QString test = QDir::currentPath();
	model_.setRootPath(QDir::currentPath());
	ui.treeViewFileInfo->setRootIndex(model_.index("E:\\project"));
	ui.treeViewFileInfo->setModel(&model_);
	ui.treeViewFileInfo->setAnimated(false);
	ui.treeViewFileInfo->setIndentation(20);
	ui.treeViewFileInfo->setSortingEnabled(true);
	ui.treeViewFileInfo->setContextMenuPolicy(Qt::CustomContextMenu);
}

void HtmlWriter::innitConnect()
{
	connect(ui.treeViewFileInfo, SIGNAL(customContextMenuRequested(const QPoint))
		, this, SLOT(showRightMenuSlot(const QPoint)));

	connect(ui.treeViewFileInfo, SIGNAL(doubleClicked(const QModelIndex &))
		, this, SLOT(onDoubleClickedItemSlot(const QModelIndex &)));

	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(onSaveSlot()));
	connect(ui.textEditText_, SIGNAL(textChanged()), this, SLOT(onTextEditChangedSlot()));	
}

void HtmlWriter::showRightMenuSlot(const QPoint point)
{
	QMenu *qMenu = NULL;

	qMenu = new QMenu(ui.treeViewFileInfo);

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

void HtmlWriter::newFolderSlot()
{
	QString newFilePath = getSelectItemPath();
	if ((!newFilePath.isEmpty()) 
		&& getNewFilePath(newFilePath, newFilePath)){
		if (!QDir().mkdir(newFilePath)){
		}	
	}	
}

QString HtmlWriter::getSelectItemPath()
{
	QString itemPath("");
	QItemSelectionModel* selecitonModel = ui.treeViewFileInfo->selectionModel();
	if (selecitonModel){
		QModelIndex modelIndex = selecitonModel->currentIndex();
		itemPath = getFullPath(modelIndex); 
	}
	return itemPath;
}

void HtmlWriter::newFileSlot()
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

bool HtmlWriter::getNewFilePath(const QString& itemPath
								, QString& rtnPath)
{
	bool rtn(false);
// 	rtnPath = itemPath;
// 	FileCreator fileCreator(rtnPath, this);
// 	fileCreator.show();
// 	if (QDialog::Accepted == fileCreator.exec()){
// 		rtnPath = fileCreator.filePath();
// 		rtn = true;
// 	}

	return rtn;
}

QString HtmlWriter::getFullPath(const QModelIndex& modelIndx)
{
	Q_ASSERT(modelIndx.isValid());
	return model_.filePath(modelIndx);

	QString path("");

	const QAbstractItemModel* model = modelIndx.model();
	if (model){
		path = model->data(modelIndx).toString();
		QModelIndex parentIndex = modelIndx.parent();
		if (parentIndex.isValid()){
			path = QDir::separator() + path;
			path = getFullPath(parentIndex)+path;
		}
	}
	return path;
}

void HtmlWriter::deleteSlot()
{

}

void HtmlWriter::onDoubleClickedItemSlot(const QModelIndex & modelIndex)
{
	QString itemPath = model_.filePath(modelIndex); 
	workingItemPath_ = itemPath;
	QFile file(itemPath); // Read the text from a file
	if (file.open(QIODevice::ReadOnly)) {
		QTextStream stream(&file);
		ui.textEditText_->setText(stream.readAll());
	}
}

void HtmlWriter::onSaveSlot()
{
	if (!workingItemPath_.isEmpty()){
		QString text = ui.textEditText_->toPlainText();
		QFile file(workingItemPath_); 
		if (file.open(QIODevice::WriteOnly)) {
			QTextStream stream(&file);
			stream<<text;
		}
	}
}

QString HtmlWriter::makeDownToHtml(const QString& input)
{
	markdown::Document doc;
	doc.read(input.toStdString());
	std::stringstream out;
	doc.write(out);
	
	std::string str;
	
//	out << out.rdbuf();
	str = out.str();

	return QString::fromStdString(str);
}

void HtmlWriter::onTextEditChangedSlot()
{
	QString text = ui.textEditText_->toPlainText();
	QString html = makeDownToHtml(text);
	ui.webViewHtml_->setHtml(html.toAscii());
}

void HtmlWriter::initControls()
{

}
