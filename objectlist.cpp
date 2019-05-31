#include "objectlist.h"

ObjectParser::ObjectParser():
  number(QString("^\\d+$")), 
  objName(QString("^[a-zA-Z0-9_-]+$|^\"[a-zA-Z0-9_-]+\"$")) {

}

ObjectDetails ObjectParser::getTheObject(const QString &pstr) {
  ObjectDetails toRet;
  toRet.isLast = false;
  QString str = pstr.trimmed();
  if(number.indexIn(str) == 0) {
    toRet.oIndex = str;
    toRet.oType = ObjectDetails::JsonArray;
  } else if(objName.indexIn(str) == 0) {
    if(str.indexOf("\"") == 0) {
      toRet.oIndex = str.mid(1, str.size() - 2);
    } else {
      toRet.oIndex = str;
    }
    toRet.oType = ObjectDetails::JsonObject;
  } else {
    error.append(QString("Object Identification is invalid. Only allowd text is in array only ^[0-9]$, for object name ^[a-zA-Z0-9_-]+$|^\"[a-zA-Z0-9_-]+\"$. Found ").append(toRet.oIndex));
    return ObjectDetails();
  }

  if(toRet.oIndex.isEmpty()) {
    error.append("Invalid item. It's empty");
    return ObjectDetails();
  }
  return toRet;
}

QList<ObjectDetails> ObjectParser::createList(const QString &str) {
  return createList(str, defaultSplit);
}

QList<ObjectDetails> ObjectParser::createList(const QString &str, const QString &split) {
  QList<ObjectDetails> toRet;
  QStringList strList = str.split(split);
  int length = strList.size();
  for(int i = 0; i < length - 1; i++) {
    ObjectDetails toAdd = getTheObject(strList[i]);
    if(!error.isEmpty()) return QList<ObjectDetails>();
    toRet.push_back(toAdd);
  }

  ObjectDetails finalObj = getTheObject(strList[length - 1]);
  if(!error.isEmpty()) return QList<ObjectDetails>();
  finalObj.isLast = true;
  toRet.push_back(finalObj);
  return toRet;
}

const QString ObjectParser::getError() {
  return error;
}

const QString ObjectParser::defaultSplit(".");

ObjectDetails& ObjectDetails::operator=(const ObjectDetails& other) {
  if (this != &other) {
    this->oIndex = other.oIndex;
    this->oType = other.oType;
    this->isLast = other.isLast;
  }

  return *this;
}
