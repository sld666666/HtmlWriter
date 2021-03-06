#ifndef DIRECTORYVIEWPART_GLOBAL_H
#define DIRECTORYVIEWPART_GLOBAL_H

#include <QtCore/qglobal.h>
#include <map>
#include <string>

using std::map;
using std::string;

const string DIR_VIEW_BUNDELNAME("DirectoryViewPart.dll");
const string DIR_VIEW_SERVICENAME("DirectoryViewPart");

#ifdef DIRECTORYVIEWPART_LIB
# define DIRECTORYVIEWPART_EXPORT Q_DECL_EXPORT
#else
# define DIRECTORYVIEWPART_EXPORT Q_DECL_IMPORT
#endif

#endif // DIRECTORYVIEWPART_GLOBAL_H
