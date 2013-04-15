#ifndef DIRECTORYTREEVIEW_H
#define DIRECTORYTREEVIEW_H

#include <QTreeView>

class DirectoryTreeView : public QTreeView
{
	Q_OBJECT

public:
	DirectoryTreeView(QWidget *parent);
	~DirectoryTreeView();

	void		onlyShowFisrtColumn();

protected:
	virtual		void focusOutEvent(QFocusEvent *event);
private:
	void		initControls();
	
};

#endif // DIRECTORYTREEVIEW_H
