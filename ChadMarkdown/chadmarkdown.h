#ifndef CHADMARKDOWN_H
#define CHADMARKDOWN_H
#include <QString>
#include "chadmarkdown_global.h"


class CHADMARKDOWN_EXPORT ChadMarkdown
{
public:
	ChadMarkdown();
	~ChadMarkdown();

	QString makedownToHtml(const QString& input);
private:

};

#endif // CHADMARKDOWN_H
