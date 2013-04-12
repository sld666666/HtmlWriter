#ifndef FILECREATOR_H
#define FILECREATOR_H

#include <QDialog>
#include "ui_FileCreator.h"

class FileCreator : public QDialog
{
	Q_OBJECT

public:
	FileCreator(const QString& pathInfo, QWidget *parent = 0);
	~FileCreator();

	QString filePath();

private slots:
	void	onOKSlot();
	void	onCancalSlot();
	void	onNameChangedSlot(const QString& text);

private:
	void	initConnect();

private:
	Ui::FileCreator ui;
	QString			filePath_;
};

#endif // FILECREATOR_H
