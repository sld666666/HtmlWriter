#include <QFileDialog>
#include <QApplication>

#include "OpenAction.h"
#include "ViewServiceOperator.h"

using  UiUtils::ViewServiceOperator;
OpenAction::OpenAction(QObject * parent)
	: IAction(parent)
{

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
	return tr("&open");
}