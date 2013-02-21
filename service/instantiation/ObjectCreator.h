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

using std::string;

namespace service{

}
template<typename BaseT, template <class> class CreationPolicy>
class ObjectCreator
{		

	private:					
		bool localSearch_;
		string path_;
		string dllName_;

	public:		
		ObjectCreator();

		ObjectCreator( bool localSearch, const string &path, const string &dllName );

		void setSearchConfiguration( bool localSearch, const string &path, const string &dllName );

		BaseT* createObject( const string &key );	

		static BaseT* createObjectFromDll( const string &path, const string &dllName, const string &className );	
};


template<typename BaseT, template <class> class CreationPolicy>
ObjectCreator<BaseT>::ObjectCreator() 
	: localSearch_( true )
	, path_( "" )
	, dllName_( "" )
{	
}

template<typename BaseT, template <class> class CreationPolicy>
void ObjectCreator<BaseT>::setSearchConfiguration(bool searchLocal
												  , const string &pathName
												  , const string &libName)
{
	this->localSearch_ = searchLocal;
	this->path_ = pathName;
	this->dllName_ = libName;
}

template<typename BaseT, template <class> class CreationPolicy>
ObjectCreator<BaseT>::ObjectCreator( bool doLocalSearch
									, const string &dllPath
									, const string &dll ) 
		: localSearch_( doLocalSearch )
		, path_( dllPath )
		, dllName_( dll )
{
}




template<typename BaseT, template <class> class CreationPolicy>
BaseT* ObjectCreator<BaseT>::createObject( const string &key )
{	
	return createObjectFromDll( this->path_, this->dllName_, key );	
}


template<typename BaseT, template <class> class CreationPolicy>
BaseT* ObjectCreator<BaseT>::createObjectFromDll( const string &path
												 , const string &dllName
												 , const string &className )
{	
	return CreationPolicy<BaseT>::createObjectFromDll( path, dllName, className );
}

#endif