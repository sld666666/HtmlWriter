#ifndef UI_GLOBAL_H
#define UI_GLOBAL_H

#include <QtCore/qglobal.h>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <algorithm>
#include <boost/bind.hpp>

using boost::shared_ptr;
using std::vector;
using boost::bind;

#ifdef UI_LIB
# define UI_EXPORT Q_DECL_EXPORT
#else
# define UI_EXPORT Q_DECL_IMPORT
#endif



#endif // UI_GLOBAL_H
