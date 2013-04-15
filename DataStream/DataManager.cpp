#include <fstream>
#include <iosfwd>
#include "DataManager.h"

using std::fstream;

namespace data{

	DataManager::DataManager()
	{
	}

	DataManager::~DataManager()
	{
	}

	bool DataManager::addData(const string& key)
	{	
		bool rtn(false);

		fstream stream;
		stream.open(key.c_str(), fstream::in | fstream::out);
		if (stream.is_open())
		{
			stream.seekg (0, stream.end);
			int length = stream.tellg();
			stream.seekg (0, stream.beg);

			char* text = new char[length];
			if (stream.read (text,length)){
				stream >> text;
				datas_.insert(make_pair(key, text));
				rtn = true;
			}else{
				delete[]text;
			}

			stream.close();
		}
		return rtn;
	}

	void DataManager::deleteData(const string& key)
	{

	}

	void DataManager::getString(const string& key
								, string& rtn)
	{

	}
}

