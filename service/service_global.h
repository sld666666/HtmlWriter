#ifndef SERVICE_GLOBAL_H
#define SERVICE_GLOBAL_H

#include <QtCore/qglobal.h>
#include <string>
#include <vector>
#include <list>

using namespace std;

#ifdef SERVICE_LIB
# define SERVICE_EXPORT Q_DECL_EXPORT
#else
# define SERVICE_EXPORT Q_DECL_IMPORT
#endif

#endif // SERVICE_GLOBAL_H
