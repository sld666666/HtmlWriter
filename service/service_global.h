#ifndef SERVICE_GLOBAL_H
#define SERVICE_GLOBAL_H

#include <QtCore/qglobal.h>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>

using namespace std;
using boost::bind;
using boost::shared_ptr;
using boost::function;

#ifdef SERVICE_LIB
# define SERVICE_EXPORT Q_DECL_EXPORT
#else
# define SERVICE_EXPORT Q_DECL_IMPORT
#endif

#endif // SERVICE_GLOBAL_H
