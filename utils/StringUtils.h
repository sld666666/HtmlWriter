/** 
* @file         StringUtils.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-3
*/
#ifndef UTILS_UTILS_STRINGUTILS_H
#define UTILS_UTILS_STRINGUTILS_H

#include <string>
#include "utils_global.h"


namespace utils{

	class UTILS_EXPORT StringUtils
	{
	public:
		StringUtils();
		~StringUtils();

		template <typename T>
		static T  strTo(const string& str){
			stringstream ss(str);
			T rtn;
			ss >> rtn;
			return rtn;
		}
	
	};


}
#endif
