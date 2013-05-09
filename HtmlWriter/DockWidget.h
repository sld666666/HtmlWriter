/** 
* @file         DockWidget.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-5-9
*/
#ifndef DOCKWIDGET_H
#define DOCKWIDGET_H

#include <QDockWidget>
#include <QMainWindow>
#include <QEvent>
#include "interface/IService.h"
#include "UiHelper.h"
#include "config/XmlConfigManager.h"

using namespace service;
using namespace utils;

class DockWidget : public QDockWidget
{
	Q_OBJECT

public:
	DockWidget(IService* serivce, QMainWindow *parent = 0);

	~DockWidget();
public slots:
	void returnToOldMaxMinSizes();

protected:
	bool eventFilter(QObject *obj, QEvent *ev);
private:
	void initDockWidget( IService* service, QMainWindow * parent);
	void adaptSize();
	void setDockSize(int width, int height);
	XmlViewsConfigPtr getXmlViewsConfig(long id);
private:
	long	curServiceId_;
	QWidget* widget_;
	QSize oldMaxSize_;
	QSize oldMinSize_;
};

#endif // DOCKWIDGET_H
