/** 
* @file         DataManager.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-13
*/
#ifndef DATA_DATAMANAGER_H
#define DATA_DATAMANAGER_H
#include "ISingleton.h"
#include "datastream_global.h"

namespace data{
	class DATASTREAM_EXPORT DataManager : public ISingleton<DataManager>
	{
	public:
		~DataManager();

		bool	addData(const QString& key);
		void	insert(const QString& key, const QString& value);
		void	deleteData(const QString& key);
		void	getString(const QString& key, QString& rtn);
		bool	writeData(const QString& key);	
		bool	writeData(const QString& key, const QString& datas);

	private:
		DataManager();
		friend class ISingleton<DataManager>;
	private:
		map<QString, QString> datas_;
	};
}

#endif