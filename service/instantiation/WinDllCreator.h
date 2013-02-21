#ifndef WIN_DLL_CREATOR_H
#define WIN_DLL_CREATOR_H

#include <string>
#include <windows.h>

#include "../../util/logging/Logger.h"
#include "../../util/logging/LoggerFactory.h"
#include "../ObjectCreationException.h"

using namespace std;

using namespace sof::instantiation;
using namespace sof::util::logging;

namespace sof { namespace instantiation { namespace win {

/**
 * The <code>WinDllCreator</code> class implements the creation policy which
 * is used by the <code>ObjectCreator</code> class (see 
 * {@link sof::framework::instantiation::ObjectCreator::createObjectFromDll}) 
 * in order to create objects from a DLL.<br>
 * The <code>WinDllCreator</code> is only able to create objects from a Windows
 * DLL.
 *
 * @author magr74
 */
template <typename BaseT>
class WinDllCreator
{
	public:

		/**
		 * Creates an object from a Windows DLL.
		 *
		 * @param path
		 *			The path where the Windows DLL is located.
		 * @param dllName
		 *			The name of the Windows DLL.
		 * @param className
		 *			The name of the class an object is created from.
		 * @return
		 *			The pointer to the created object.
		 */
		static BaseT* createObjectFromDll( const string &path, const string &dllName, const string &className );
		
		/**
		 * Returns a logger instance.
		 *
		 * @return
		 *		Returns an instance of class <code>Logger</code>.
		 */
		static Logger& getLogger();
};

template <typename BaseT>
Logger& WinDllCreator<BaseT>::getLogger()
{
	static Logger& logger = LoggerFactory::getLogger( "ObjectCreation" );
	return logger;
}

template <typename BaseT>
BaseT* WinDllCreator<BaseT>::createObjectFromDll( const string &path, const string &dllName, const string &className )
{
	typedef BaseT* (*DLLPROC) ( const string& );

	DLLPROC pFunc = NULL;

	ostringstream str;
	
	int pos = path.find_last_of( '/' );
	if ( pos == ( path.size() - 1 ) )
	{
		str << path << dllName;	
	}
	else
	{
		str << path << '/' << dllName;	
	}
	

	HMODULE hMod = NULL;
	try
	{
		hMod = LoadLibrary( str.str().c_str() );
	}
	catch( exception &exc )
	{
		hMod = NULL;
	}

	if ( hMod == NULL )
	{
		ObjectCreationException exc( "Error during loading DLL." );
		throw exc;
	}
	
	try
	{
		pFunc = ( DLLPROC ) GetProcAddress(hMod, "createObject"); 
	}
	catch( exception &exc)
	{
		pFunc = NULL;
	}

	if ( pFunc == NULL )
	{
		ObjectCreationException exc( "Error during loading object from DLL." );
		throw exc;
	}	
	return ((*pFunc)(className));
}

}}}
#endif