#ifndef DIRECTORYVIEWPART_GLOBAL_H
#define DIRECTORYVIEWPART_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef DIRECTORYVIEWPART_LIB
# define DIRECTORYVIEWPART_EXPORT Q_DECL_EXPORT
#else
# define DIRECTORYVIEWPART_EXPORT Q_DECL_IMPORT
#endif

#endif // DIRECTORYVIEWPART_GLOBAL_H