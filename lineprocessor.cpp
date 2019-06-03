#include <QList>
#include "lineprocessor.h"
#include "objectlist.h"

LineProcessor::LineProcessor(JsonData *jsonData,const QString &separator,const QString &start,const QString &end) {
  this->jsonData = jsonData;
  this->separator = separator;
  tagStart = start;
  tagEnd = end;
}

QString LineProcessor::processString(const QString &proLine) {
  // reset error feild
  error = "";
  ObjectParser objparser;
  if(proLine.isEmpty()) {
    return proLine;
  }
  int lastPos = 0;
  QString toRet("");
  while(true) {
    //we will keep playing untill we no more starting tag.  or no more end tag
    int startPos = proLine.indexOf(tagStart, lastPos);
    int endPos = proLine.indexOf(tagEnd, startPos + tagStart.size());
    if(startPos == -1 || endPos == -1) {
      toRet.append(proLine.mid(lastPos));
      return toRet;
    }
    if(endPos < startPos) {
      lastPos = startPos;
      continue;
    }
    if(endPos - startPos - tagStart.length() == 0) {
      error = tagStart + tagEnd + " combination found. Throwing this as error.";
      return QString("");
    }
    if(startPos - lastPos != 0) {
      toRet.append(proLine.mid(lastPos, startPos - lastPos));
    }
    // extact index
    QString index = proLine.mid(startPos + tagStart.length(), endPos - startPos - tagStart.length());
    // search index value
    QString res = jsonData->getValue(index, separator);
    if(!jsonData->getError().isEmpty()) {
      error = jsonData->getError();
      return QString("");
    }
    toRet.append(res);
    lastPos = endPos + tagEnd.length();
  }
  return toRet;
}


QString LineProcessor::getError() {
  return error;
}