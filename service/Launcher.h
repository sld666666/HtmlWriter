/** 
* @file         Launcher.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-7
*/
#ifndef SERVICE_BUNDLECONFIGURATION_H
#define SERVICE_BUNDLECONFIGURATION_H

namespace service{
	class Launcher
	{
	public:
		Launcher();
		~Launcher();

	private:
		void	doStart(const BundleConfiguration& bundleConfig);
	};
}


#endif