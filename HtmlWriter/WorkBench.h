#ifndef WORKBENCH_H
#define WORKBENCH_H

#include <QMainWindow>
#include "ui_WorkBench.h"

class WorkBench : public QMainWindow
{
	Q_OBJECT

public:
	WorkBench(QWidget *parent = 0);
	~WorkBench();

private:
	void	appendDockWidget(const QString& name);

private:
	Ui::WorkBench ui;
};

#endif // WORKBENCH_H
