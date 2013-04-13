#ifndef DATASTREAM_GLOBAL_H
#define DATASTREAM_GLOBAL_H

#include <QtCore/qglobal.h>
#include <map>
#include <string>

using std::map;
using std::string;

#ifdef DATASTREAM_LIB
# define DATASTREAM_EXPORT Q_DECL_EXPORT
#else
# define DATASTREAM_EXPORT Q_DECL_IMPORT
#endif

#endif // DATASTREAM_GLOBAL_H
