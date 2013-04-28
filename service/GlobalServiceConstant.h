#ifndef GLOBALSERVICECONSTANT_H
#define GLOBALSERVICECONSTANT_H

namespace RegisteredSeviceID
{
	const long RSI_UNREGISTER = -1;
	//view; 1000
	const long RSI_VIEW_HTMLPREVIEW = 1001;
	const long RSI_VIEW_DIRECTORYVIEW = 1002;
	
	//editor 2000
	const long RSI_EDITOR_MARKDOWNEDITORVIEW = 2001;
	//menu	3000
	const long RSI_MENU_EDITOR = 3001;
	const long RSI_MENU_FILE = 3002;
	const long RSI_MENU_VIEW = 3003;
	const long RSI_MENU_TOOL = 3004;
	const long RSI_MENU_HELP = 3005;

	//action 4000
	const long RSI_ACTION_OPEN = 4001;
	const long RSI_ACTION_SAVE = 4002;
	const long RSI_ACTION_SAVEAS = 4003;


}

#endif // GLOBALSERVICECONSTANT_H
