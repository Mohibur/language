#ifndef _LINEPROCESSOR_H
#define _LINEPROCESSOR_H
#include <QtCore>
#include "jsondata.h"

class LineProcessor 
{
private:
	QString processLine;
	JsonData jsonData;
public:
	LineProcessor(const JsonData &jsonData);

public:
	QString processString(const QString &line);

private:
	int position(const QString &search);
}
#endif
