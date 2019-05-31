#include "lineprocessor.h"
#include <QList>

LineProcessor::LineProcessor(const JsonData &jsonData) {
  this->jsonData = jsonData;
}

QString LineProcessor::processString(const QString &line, const QString &separator) {
  QString toRet(line);
  ObjectParser objparser;
  QList<ObjectDetails> list = objparser.createList(line, separator);
  if(toRet.isEmpty()) {
    this->error.append(objparser.geError());
    return toRet;
  };

  for(int i = 0; i < list.size(); i++) {
    if(list[i].isLast && currentDocument) {
      
    }
  }
  return toRet;
}
