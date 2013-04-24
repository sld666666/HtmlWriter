#ifndef WORKBENCH_H
#define WORKBENCH_H

#include <QMainWindow>
#include "ui_WorkBench.h"
#include "ServiceLoader.h"
#include "interface/IBundle.h"

using namespace service;

class WorkBench : public QMainWindow
{
	Q_OBJECT

public:
	WorkBench(QWidget *parent = 0);
	~WorkBench();

private:
	void	initBundles();
	void	initActionBar();
	void	appendDockWidget(const IBundle* bundle);

private:
	Ui::WorkBench ui;
};

#endif // WORKBENCH_H
