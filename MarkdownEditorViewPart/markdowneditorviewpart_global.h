#ifndef MARKDOWNEDITORVIEWPART_GLOBAL_H
#define MARKDOWNEDITORVIEWPART_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef MARKDOWNEDITORVIEWPART_LIB
# define MARKDOWNEDITORVIEWPART_EXPORT Q_DECL_EXPORT
#else
# define MARKDOWNEDITORVIEWPART_EXPORT Q_DECL_IMPORT
#endif

#endif // MARKDOWNEDITORVIEWPART_GLOBAL_H
