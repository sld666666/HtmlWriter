/** 
* @file         ActionHelper.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-28
*/
#ifndef UIUTILS_ACTIONHELPER_H
#define UIUTILS_ACTIONHELPER_H

#include "IAction.h"
#include "ui_global.h"

using namespace service;

namespace UiUtils{
	class UI_EXPORT ActionHelper
	{
	public:
		ActionHelper();
		~ActionHelper();

		static vector<IAction*>	getActions(vector<long>ids);
		static IAction*	getAction(long id);
	};
}


#endif // UIUTILS_ACTIONHELPER_H
