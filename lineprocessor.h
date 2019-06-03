#ifndef _LINEPROCESSOR_H
#define _LINEPROCESSOR_H
#include <QtCore>
#include "jsondata.h"

class LineProcessor
{
private:
  QString processLine;
  QString separator;
  QString tagStart;
  QString tagEnd;
  JsonData *jsonData;
  QString error ;
public:
  LineProcessor(JsonData *jsonData,const QString &separator,const QString &start,const QString &end);

public:
  QString processString(const QString &proLine);
  QString getError();
};

#endif
