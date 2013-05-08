#include <QFileDialog>
#include <QApplication>

#include "OpenAction.h"
#include "ViewServiceOperator.h"
#include "ApplicationConfig.h"

using  UiUtils::ViewServiceOperator;
OpenAction::OpenAction(QObject * parent)
	: IAction(parent)
{
	this->setShortcut(Qt::CTRL + Qt::Key_O);
}

OpenAction::~OpenAction()
{

}

void OpenAction::execute()
{
	QString fileName = QFileDialog::getOpenFileName(QApplication::activeWindow()
		, tr("Open File"),
		""
		, tr("Files (*.*)"));

	ViewServiceOperator::instance().viewReflesh("MainWindow", fileName);

}

long OpenAction::serviceId()
{
	return RegisteredSeviceID::RSI_ACTION_OPEN;
}

QString OpenAction::title()
{
	return tr("&open(ctlr+o)");
}

QIcon OpenAction::getIcon()
{
	QString image = QString::fromStdString(ApplicationConfig::instance().getIconPath())
		+ "/fileopen.png";
	return QIcon(image);
}