/** 
* @file         ObjectCreator.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-21
*/
#ifndef OBJECT_CREATOR_H
#define OBJECT_CREATOR_H
#include <string>
#include "SystemOperation.h"
#include "WinDllCreator.h"

using std::string;

namespace service{
	template<typename BaseT>
	class ObjectCreator
	{

	public:		
		ObjectCreator();

		ObjectCreator( const string &path, const string &dllName );

		void setSearchConfiguration( const string &path, const string &dllName );

		BaseT* createObject( const string &key );	

		static BaseT* createObjectFromDll( const string &path, const string &dllName, const string &className );	


	private:					
		string path_;
		string dllName_;
	};


	template<typename BaseT>
	ObjectCreator<BaseT>::ObjectCreator() 
		: path_( "" )
		, dllName_( "" )
	{	
	}

	template<typename BaseT>
	void ObjectCreator<BaseT>::setSearchConfiguration(
		 const string &pathName
		, const string &libName)
	{
		this->path_ = pathName;
		this->dllName_ = libName;
	}

	template<typename BaseT>
	ObjectCreator<BaseT>::ObjectCreator( const string &dllPath
		, const string &dll ) 
		: path_( dllPath )
		, dllName_( dll )
	{
	}




	template<typename BaseT>
	BaseT* ObjectCreator<BaseT>::createObject( const string &key )
	{	
		return createObjectFromDll( this->path_, this->dllName_, key );	
	}


	template<typename BaseT>
	BaseT* ObjectCreator<BaseT>::createObjectFromDll( const string &path
		, const string &dllName
		, const string &className )
	{	
		return SystemOperation<BaseT, WinDllCreator>::createObjectFromDll( path
			, dllName
			, className );
	}
}


#endif