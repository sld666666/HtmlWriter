/** 
* @file         WinDllCreator.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-21
*/
#ifndef SERVICE_WIN_DLL_CREATOR_H
#define SERVICE_WIN_DLL_CREATOR_H

#include <string>
#include <windows.h>

using namespace std;

namespace service{
	template <typename BaseT>

	class WinDllCreator
	{
	public:
		static BaseT* createObjectFromDll(const string &path, const string &dllName);
	};


	template <typename BaseT>
	BaseT* WinDllCreator<BaseT>::createObjectFromDll( const string &path
													 , const string &dllName)
	{
		typedef BaseT* (*DLLPROC) ();
		DLLPROC pFunc = NULL;
		ostringstream str;
		
		int pos = path.find_last_of( '/' );
		if ( pos == ( path.size() - 1 ) ){
			str << path << dllName;	
		}
		else{
			str << path << '/' << dllName;	
		}
		

		HMODULE hMod = NULL;
		try{
			string dllPath(str.str());
			wstring wDllPath = wstring(dllPath.begin(), dllPath.end());
			hMod = LoadLibrary( wDllPath.c_str() );
		}
		catch( exception &exc ){
			hMod = NULL;
			return NULL;
		}
		
		try
		{
			pFunc = ( DLLPROC ) GetProcAddress(hMod, "createObject"); 
		}
		catch( exception &exc)
		{
			pFunc = NULL;
		}

		if ( pFunc == NULL ){
			return NULL;
		}	
		return ((*pFunc)());
	}

}


#endif