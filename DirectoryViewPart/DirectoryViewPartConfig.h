/** 
* @file         DirectoryViewPartConfig.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-15
*/
#ifndef DIRECTORYVIEWPARTCONFIG_H
#define DIRECTORYVIEWPARTCONFIG_H

#include <QObject>
#include "ISingleton.h"
#include "directoryviewpart_global.h"

class DirectoryViewPartConfig : public ISingleton<DirectoryViewPartConfig>
{
public:
	~DirectoryViewPartConfig();
	
	string	getValue(const string& key);

protected:
	virtual	string getFileName();

private:
	DirectoryViewPartConfig();

	friend class ISingleton<DirectoryViewPartConfig>;

	void	initConfigs();

private:
	map<string, string>		configs_;
};

namespace DirectoryViewPartConfigKey{
	const string LOCATION = "location";
}

#endif // DIRECTORYVIEWPARTCONFIG_H
