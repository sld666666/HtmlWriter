/** 
* @file         ObjectCreator.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-21
*/
#ifndef SYSTEMOERATION_H
#define SYSTEMOERATION_H

#include "service_global.h"

namespace service{

	template<typename BaseT,template <class> class creation>
	class SystemOperation
	{
	public:
		static BaseT* createObjectFromDll( const string &path
									, const string &dllName)
		{
			return creation<BaseT>::createObjectFromDll( path
				, dllName);
		}
	};

}


#endif