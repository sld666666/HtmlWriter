/** 
* @file         BundleContext.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-2-7
*/

#ifndef SERVICE_BUNDLECONTEXT_H 
#define SERVICE_BUNDLECONTEXT_H

namespace service{
	class BundleContext
	{
	public:
		BundleContext()
			: parent_(0)
		{}

		~BundleContext(){}

		void		setParent(void* parent){parent_ = parent;}
		void*		getParent(){return parent_;}

	private:
		void*	parent_;
	};
}

#endif