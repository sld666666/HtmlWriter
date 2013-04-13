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

		bool	addData(const string& key);
		void	deleteData(const string& key);
		void	getString(const string& key, string& rtn);

	private:
		DataManager();
		friend class ISingleton<DataManager>;
	private:
		map<string, char*> datas_;
	};
}

#endif