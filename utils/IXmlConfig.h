/** 
* @file         FunctionUtils.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-3
*/
#ifndef UTILS_UTILS_FunctionUtils_H
#define UTILS_UTILS_FunctionUtils_H

#include <string>
#include "utils_global.h"


namespace utils{

	enum ReadWriteType
	{
		RW_ReadOnly = 0,
		RW_ReadWrite
	};

	class  IXmlConfig
	{
	public:
		IXmlConfig();
		~IXmlConfig();

	protected:
		virtual	string getFileName() = 0;

	};

}
#endif