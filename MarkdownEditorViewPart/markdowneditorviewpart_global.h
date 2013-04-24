#ifndef MARKDOWNEDITORVIEWPART_GLOBAL_H
#define MARKDOWNEDITORVIEWPART_GLOBAL_H

#include <QtCore/qglobal.h>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <boost/bind.hpp>
#include <string>

using boost::shared_ptr;
using std::vector;
using boost::bind;
using std::string;

const string BUNDELNAME("MarkdownEditorViewPart.dll");
#ifdef MARKDOWNEDITORVIEWPART_LIB
# define MARKDOWNEDITORVIEWPART_EXPORT Q_DECL_EXPORT
#else
# define MARKDOWNEDITORVIEWPART_EXPORT Q_DECL_IMPORT
#endif

#endif // MARKDOWNEDITORVIEWPART_GLOBAL_H
