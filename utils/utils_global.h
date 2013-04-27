#ifndef UTILS_GLOBAL_H
#define UTILS_GLOBAL_H

#include <QtCore/qglobal.h>
#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;
using std::stringstream;

#ifdef UTILS_LIB
# define UTILS_EXPORT Q_DECL_EXPORT
#else
# define UTILS_EXPORT Q_DECL_IMPORT
#endif

#endif // UTILS_GLOBAL_H
