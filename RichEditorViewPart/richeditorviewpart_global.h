#ifndef RICHEDITORVIEWPART_GLOBAL_H
#define RICHEDITORVIEWPART_GLOBAL_H

#include <QtCore/qglobal.h>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <boost/bind.hpp>
#include <string>

using boost::shared_ptr;
using std::vector;
using boost::bind;
using std::string;

const string RICHEDITORBUNDELNAME("RichEditorViewBundle.dll");

#ifdef RICHEDITORVIEWPART_LIB
# define RICHEDITORVIEWPART_EXPORT Q_DECL_EXPORT
#else
# define RICHEDITORVIEWPART_EXPORT Q_DECL_IMPORT
#endif

#endif // RICHEDITORVIEWPART_GLOBAL_H
