/** 
* @file         FunctionUtils.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-3
*/
#ifndef UTILS_UTILS_FUNCTIONUTILS_H
#define UTILS_UTILS_FUNCTIONUTILS_H

#include <string>
#include "utils_global.h"


namespace utils{

	template <typename T>
	static bool	isZore(T val){
		bool rtn = (0 == val);
		return rtn;
	}

}
#endif
