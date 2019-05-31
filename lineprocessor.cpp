#include "lineprocessor.h"
#include <QList>

LineProcessor::LineProcessor(const JsonData &jsonData, QString &separator, QString &start, QString &end) {
  this->jsonData = jsonData;
  this->separator = separator;
  tagStart = start;
  tagEnd = end;
}

QString LineProcessor::processString(const QString &proLine, const QString &separator) {
  processLine = proLine;
  ObjectParser objparser;
  if(processLine.isEmpty()) {
    return processLine;
  }
  int lastPos = 0;
  QString toRet("");
  while(true) {
    //we will keep playing untill we no more starting tag.  or no more end tag
    int startPos = proLine.indexOf(tagStart, lastPos);
    int endPos = proLine.indexOf(tagEnd, startPos + tagStart.size());
    if(startPos == -1 || endPos == -1) {
      toRet.append(processLine.mid(lastPos));
      return toRet;
    }
    if(endPos < startPos) {
      lastPos = startPos;
      continue;
    }
    #TODO WORK HERE
    toRet.append(startPos, );
    QString index = processLine.mid(startPos, endPos - startPos.length() - startPos);
    
  }
  return toRet;
}
