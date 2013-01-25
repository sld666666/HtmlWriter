#ifndef HTMLWRITER_H
#define HTMLWRITER_H

#include <QtGui/QMainWindow>
#include "ui_htmlwriter.h"

class HtmlWriter : public QMainWindow
{
	Q_OBJECT

public:
	HtmlWriter(QWidget *parent = 0, Qt::WFlags flags = 0);
	~HtmlWriter();

private:
	Ui::HtmlWriterClass ui;
};

#endif // HTMLWRITER_H
