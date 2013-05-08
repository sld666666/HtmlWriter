/** 
* @file         IXmlConfig.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-3
*/
#ifndef UTILS_IXMLCONFIG_H
#define UTILS_IXMLCONFIG_H

#include <string>
#include <QObject>
#include "utils_global.h"
#include "IConfigMetaObj.h"


namespace utils{

	enum ReadWriteType
	{
		RW_ReadOnly = 0,
		RW_ReadWrite
	};

	class  IXmlConfig : public QObject
	{
	public:
		IXmlConfig();
		~IXmlConfig();

	public:
		virtual	string getFileName() = 0;
		virtual string getRootElementName() = 0;

	};

	typedef shared_ptr<IXmlConfig> IXmlConfigPtr;

}
#endif