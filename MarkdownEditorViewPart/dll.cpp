#include "stdafx.h"
#include <windows.h>
#include "interface/IBundle.h"
#include "instantiation/ObjectCreator.h"
#include "MarkdownEditorViewBundle.h"

#define DLL extern "C" __declspec(dllexport)

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{				
	return TRUE;
}

DLL service::IBundle* createObject()
{	
	return new MarkdownEditorViewBundle();
}

