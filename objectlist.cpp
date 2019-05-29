#include "objectlist.h"
#include <QRegularExpression>

ObjectParser::ObjectParser():number("^\[\d+\]$", QRegularExpression::DotMatchesEverythingOption), objName("^[a-zA-Z0-9_-]$", QRegularExpression::DotMatchesEverythingOption) {

}

ObjectList& ObjectParser::getTheObject(const QString &str) {
  ObjectList toRet;
  toRet.isLast = false;
  QString str = strList[i].trimmed();
  if(str.contain(number)) {
    toRet.oIndex = str.mid(1, str.size() - 2);
  } else if(str.contain(objName)) {
    toRet.oIndex = str;
  } else {
    error.append("Object Identification is invalid. Only allowd text is in array only ^[0-9]$, for object name ^[a-zA-Z0-9_-]$ ");
  }
  return toRet;
}

QList<ObjectList> ObjectParser::createList(const QString &str) {
  QList<ObjectList> toRet;
  StringList strList = str.split(".");
  int length = strList.size();
  for(int i = 0; i < length - 1; i++) {
    ObjectList toAdd = getTheObject(strList[i]);
    if(!error.isEmpty()) return QList<ObjectList>();
    toRet.push_back(toAdd);
  }

  ObjectList finalObj = getTheObject(strList[length - 1]);
  finalObj.isLast = true;
  toRet.push_back(finalObj);
  return toRet;
}

const QString& ObjectParser::getError() {
  return error;
}
