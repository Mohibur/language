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
  JsonData jsonData;
public:
  LineProcessor(const JsonData &jsonData);

public:
  QString processString(const QString &line);
}
#endif
