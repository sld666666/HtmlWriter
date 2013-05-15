#ifndef UTILS_XMLVIEWSCONFIG_H
#define UTILS_XMLVIEWSCONFIG_H

#include <QObject>
#include "config/IXmlConfig.h"

using namespace utils;
class MarkdownViewPartConfig : public IXmlConfig
	, public IConfigMetaObj<MarkdownViewPartConfig>
{
	Q_OBJECT
		Q_PROPERTY( QString  opened READ opened WRITE setOpened)

public:
	MarkdownViewPartConfig(){}
	~MarkdownViewPartConfig(){}

	virtual	string getFileName(){return "plugins/markdownViewPartConfig.xml";}
	virtual string getRootElementName(){return "openeds.opened";}

public:
	inline QString	opened() const { return opened_;}
	inline void		setOpened(const QString& val){opened_ = val;}

public:
	QString	opened_;
};

typedef shared_ptr<MarkdownViewPartConfig> MarkdownViewPartConfigPtr;


#endif // XmlViewConfig_H
