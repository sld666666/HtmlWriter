#include <QTextStream>
#include <QFile>
#include <utility>
#include "DataManager.h"

using std::fstream;

namespace data{

	DataManager::DataManager()
	{
	}

	DataManager::~DataManager()
	{
	}

	bool DataManager::addData(const QString& key)
	{	
		bool rtn(false);

		QFile file(key);
		if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
			QTextStream in(&file);
			in.setCodec("UTF-8");
			QString data = in.readAll();
			datas_.insert(std::make_pair(key, data));

			file.close();
		}
		return rtn;
	}

	bool DataManager::writeData(const QString& key)
	{	
		bool rtn(false);

		QFile file(key);
		if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
			QTextStream out(&file);
			out.setCodec("UTF-8");
			out << datas_[key];

			file.close();
		}
		return rtn;
	}

	void DataManager::deleteData(const QString& key)
	{

	}

	void DataManager::getString(const QString& key
								, QString& rtn)
	{
		if (datas_.find(key) == datas_.end()){
			addData(key);
		}

		rtn =  datas_[key];
	}

	void DataManager::insert(const QString& key
							, const QString& value)
	{

		if (datas_.find(key) == datas_.end()){
			datas_.insert(std::make_pair(key, value));
		}else{
			datas_[key] = value;
		}
	}
}

