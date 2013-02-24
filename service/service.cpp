#include <QCoreApplication>
#include <QDir>

#include "service.h"

namespace service
{
	service::service()
	{

	}

	service::~service()
	{

	}

	void service::registerAll()
	{
		QString pluginPath = QCoreApplication::applicationDirPath() + "plugin";
		QDir dir(pluginPath);
		if (dir.exists()){
			dir.setFilter(QDir::Files); 

			QFileInfoList list = dir.entryInfoList(); 
			if(list.size()< 1 )
				return;


		}
	}
}

