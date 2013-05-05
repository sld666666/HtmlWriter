#ifndef ACTIONSREGISTER_H
#define ACTIONSREGISTER_H

#include <QObject>

class ActionsRegister : public QObject
{
	Q_OBJECT

public:
	ActionsRegister(QObject *parent);
	~ActionsRegister();
	
	void	registerActions();
	
private:
	
};

#endif // ACTIONSREGISTER_H
