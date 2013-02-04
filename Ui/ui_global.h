#ifndef UI_GLOBAL_H
#define UI_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef UI_LIB
# define UI_EXPORT Q_DECL_EXPORT
#else
# define UI_EXPORT Q_DECL_IMPORT
#endif

#include <boost/shared_ptr.hpp>
using boost::shared_ptr;

#endif // UI_GLOBAL_H
