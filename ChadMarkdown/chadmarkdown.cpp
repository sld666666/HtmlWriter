#include <fstream>
#include <sstream>

#include "chadmarkdown.h"
#include "markdown.h"


ChadMarkdown::ChadMarkdown()
{

}

ChadMarkdown::~ChadMarkdown()
{

}

QString ChadMarkdown::makedownToHtml(const QString& input)
{
	markdown::Document doc;
	doc.read(input.toStdString());
	std::stringstream out;
	doc.write(out);

	std::string str;

	//	out << out.rdbuf();
	str = out.str();

	return QString::fromStdString(str);
}