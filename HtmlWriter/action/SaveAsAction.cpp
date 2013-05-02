#include <QFileDialog>
#include <QApplication>
#include "SaveAsAction.h"
#include "ViewServiceOperator.h"

using  UiUtils::ViewServiceOperator;

SaveAsAction::SaveAsAction(QObject * parent)
	: IAction(parent)
{

}

SaveAsAction::~SaveAsAction()
{

}


void SaveAsAction::execute()
{
	QString fileName = QFileDialog::getSaveFileName(QApplication::activeWindow()
		, tr("Save File"),
		""
		, tr("Files (*.*)"));

	ViewServiceOperator::instance().saveAsEditor(fileName);
}

long SaveAsAction::serviceId()
{
	return RegisteredSeviceID::RSI_ACTION_SAVEAS;
}

QString SaveAsAction::title()
{
	return tr("&saveAs");
}