#ifndef WORKBENCH_H
#define WORKBENCH_H

#include <QMainWindow>
#include "ui_WorkBench.h"
#include "ServiceLoader.h"
#include "interface/IBundle.h"
#include "ServiceManager.h"

using namespace service;

class WorkBench : public QMainWindow
{
	Q_OBJECT

public:
	WorkBench(QWidget *parent = 0);
	~WorkBench();

private:
	void	initBundles();
	void	initSelfServices();
	void	initViewPart();
	void	initMenuBar();
	void	initToolBar();
	void	startBundle(const IBundle* bundle);
	void	appendDockWidget(IService* service);
	void	appendMenuBar(IService* service);

private:
	Ui::WorkBench ui;
};

#endif // WORKBENCH_H
