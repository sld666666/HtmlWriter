#ifndef WORKBENCH_H
#define WORKBENCH_H

#include <QMainWindow>
#include "ui_WorkBench.h"
#include "ServiceLoader.h"
#include "interface/IBundle.h"
#include "ServiceManager.h"
#include "action/ApplicationActionBarAdvisor.h"

using namespace service;

class WorkBench : public QMainWindow
{
	Q_OBJECT

public:
	WorkBench(QWidget *parent = 0);
	~WorkBench();

protected:
	bool eventFilter(QObject *obj, QEvent *ev);

private:
	void	initBundles();
	void	initSelfServices();
	void	initViewPart();
	void	initMenuBar();
	void	initToolBar();
	void	startBundle(const IBundle* bundle);
	void	appendDockWidget(IService* service);
	void	initApplicaion();


private:
	Ui::WorkBench ui;
	ApplicationActionBarAdvisor appActionAdvisor_;
};

#endif // WORKBENCH_H
