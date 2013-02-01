/** 
* @file         IAction.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-1
*/
#ifndef UI_IACTION_H
#define UI_IACTION_H

#include <QObject>

namespace Ui{

}
class IAction : public QObject
{
	Q_OBJECT

public:
	IAction(QObject *parent);
	~IAction();

private:
	
};

#endif // UI_IACTION_H
