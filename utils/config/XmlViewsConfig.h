#ifndef UTILS_XMLVIEWSCONFIG_H
#define UTILS_XMLVIEWSCONFIG_H

#include <QObject>
#include "IXmlConfig.h"

namespace utils{
	
	class XmlViewsConfig : public IXmlConfig
		, public IConfigMetaObj<XmlViewsConfig>
	{
		Q_OBJECT
			Q_PROPERTY( QString  name READ name WRITE setName)
			Q_PROPERTY( long  id READ id WRITE setId)
			Q_PROPERTY( bool  visible READ visible WRITE setVisible)
			Q_PROPERTY( qint32  width READ width WRITE setWidth)

	public:
		XmlViewsConfig(){}
		~XmlViewsConfig(){}

		virtual	string getFileName(){return "applicaiton/viewsConfig.xml";}
		virtual string getRootElementName(){return "views";}

	public:
		inline QString	name() const { return name_;}
		inline void		setName(const QString& val){name_ = val;}

		inline long		id() const { return id_;}
		inline void		setId(const long& val){id_ = val;}

		inline qint32	visible() const { return visible_;}
		inline void		setVisible(const bool& val){visible_ = val;}

		inline qint32	width() const { return width_;}
		inline void		setWidth(const qint32& val){width_ = val;}

	public:
		QString	name_;
		long	id_;
		long	visible_;
		qint32	width_;
	};

	typedef shared_ptr<XmlViewsConfig> XmlViewsConfigPtr;

	class XmlViewConfigFunctor
	{

	public:
		static bool isIdMatched(XmlViewsConfigPtr viewConfig, long id){
			return (viewConfig.get() && (id == viewConfig->id())) ;
		}
	};
}


#endif // XmlViewConfig_H
