#ifndef UTILS_XMLAPPLICATIONCONFIG_H
#define UTILS_XMLAPPLICATIONCONFIG_H

#include <QObject>
#include "IXmlConfig.h"

namespace utils{
	class UTILS_EXPORT  XmlApplicationConfig : public IXmlConfig
		, public IConfigMetaObj<XmlApplicationConfig>
	{
		Q_OBJECT

			Q_PROPERTY( qint32  isMax READ isMax WRITE setIsMax)
			Q_PROPERTY( qint32  width READ width WRITE setWidth)
			Q_PROPERTY( qint32  height READ height WRITE setHeight)

	public:
		XmlApplicationConfig(){}
		~XmlApplicationConfig(){}

		virtual	string getFileName(){return "applicaiton/applicaitonConfig.xml";}
		virtual string getRootElementName(){return "application";}

	public:
		inline qint32	isMax() const { return isMax_;}
		inline void		setIsMax(const qint32& val){isMax_ = val;}

		inline qint32	width() const { return width_;}
		inline void		setWidth(const qint32& val){width_ = val;}

		inline qint32	height() const { return height_;}
		inline void		setHeight(const qint32& val){height_ = val;}

	public:
		qint32	isMax_;
		qint32	width_;
		qint32	height_;
	};

	typedef shared_ptr<XmlApplicationConfig> XmlApplicationConfigPtr;
}


#endif // XmlViewConfig_H
