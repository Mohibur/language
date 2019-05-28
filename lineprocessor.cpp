#include "lineprocessor.h"

LineProcessor::LineProcessor(const JsonData &jsonData) {
  this->jsonData = jsonData;
}

QString LineProcessor::processString(const QString &line) {
  QString toRet(line);
  if(toRet.isEmpty()) return toRet;

  while(true) {
    int start = position(QString("<? "));
    if(start == -1) {
      return toRet;
    }
    int end = position(QString(" ?>"), start + 3);
    if(end == -1) {
      return toRet;
    }
    QString toFind = line.mid(start + 3, end - 6);
    QString toReplace = jsonData.getString(toFind);
    toRet.replace(start, end + 3, toReplace);
  }
  return toRet;
}



int LineProcessor::position(const QString &search) {
  return processLine.indexOf(search);
}
