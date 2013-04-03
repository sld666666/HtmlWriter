/** 
* @file         ObjectCreator.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-21
*/
#ifndef SYSTEMOERATION_H
#define SYSTEMOERATION_H


namespace service{

	template<typename BaseT,template <class> class creation>
	class SystemOperation
	{
	public:
		static BaseT* createObjectFromDll( const string &path
									, const string &dllName
									, const string &className )
		{
			return creation<BaseT>::createObjectFromDll( path
				, dllName
				, className );
		}
	};

}


#endif