#include "jsondata.h"
#include "objectlist.h"
#include "test/log.h"
#include <QJsonDocument>

JsonData::JsonData(QJsonValue jsonValue, const QString &separator) {
  this->jsonValue = jsonValue;
  this->separator = separator;
  
}
// search example: abc.[10].def.[0]
QString JsonData::getValue(const QString &search) {
  if(search.isEmpty()) {
    return QString("");
  }
  QJsonValue currentJson = jsonValue;
  ObjectParser objparser;
  QList<ObjectDetails> list = objparser.createList(search, separator);
  if(!objparser.getError().isEmpty()) {
    this->error.append(objparser.getError());
    return QString("");
  };

  QString requstedObject = "";
  for(int i = 0; i < list.size(); i++) {
    if(!requstedObject.isEmpty()) {
      requstedObject.append(" > ");
    }
    requstedObject.append(list[i].oIndex);

    if(list[i].isLast && !currentJson.isArray() && !currentJson.isObject()) {
      error = QString("Last index does not point to a value but an array or an object.\nIndex: ").append(requstedObject);
      return QString("");
    } else if (!list[i].isLast && currentJson.isArray()) {
      QJsonArray qjArray = currentJson.toArray();
      int index = intToString(list[i].oIndex);
      if(qjArray.size() <= index) {
        error = QString("Integer index is bigger than available index. Max is ").append(qjArray.size() - 1).append("\nIndex: ").append(requstedObject);
        return QString("");
      }
      currentJson = qjArray[index];
      if(isValue(currentJson)) {
        error = QString("Unexpected current value, expecting to be array/object.").append("\nIndex: ").append(requstedObject);
        return QString("");
      }
      continue;
    } else if(!list[i].isLast && currentJson.isObject()) {
      QJsonObject qjObject = currentJson.toObject();
      if(!qjObject.contains(list[i].oIndex)) {
        error = QString("Requsted object is not found.\nIndex: ").append(requstedObject);
        return QString("");
      }
      currentJson = qjObject[list[i].oIndex];
      if(isValue(currentJson)) {
        error = QString("Unexpected current value, expecting to be array/object.").append("\nIndex: ").append(requstedObject);
        return QString("");
      }
      continue;
    } else if(list[i].isLast && currentJson.isArray()) {
      /*We reached to bottom as array*/
      QJsonArray qjArray = currentJson.toArray();
      int index = intToString(list[i].oIndex);
      if(qjArray.size() <= index) {
        error = QString("Integer index is bigger than available index. Max is ").append(qjArray.size() - 1).append("\nIndex: ").append(requstedObject);
        return QString("");
      }
      QJsonValue qv = qjArray[index];
      
      if(qv.isArray() || qv.isObject() || qv.isNull()) {
        error = QString("We are expecting value but found Array/Object/NULL. ").append(qjArray.size() - 1).append("\nIndex: ").append(requstedObject);
        return QString("");
      }
      INFO(QString(">>>>>>>>>>>>>>>").append(qv.toString()));
      return getStringValue(qv);
    } else if(list[i].isLast && currentJson.isObject()) {
      /*We reached to bottom as object*/
      QJsonObject qjObject = currentJson.toObject();
      if(!qjObject.contains(list[i].oIndex)) {
        error = QString("Requsted object is not found.\nIndex: ").append(requstedObject);
        return QString("");
      }
      QJsonValue qv = qjObject[list[i].oIndex];
      if(qv.isArray() || qv.isObject() || qv.isNull()) {
        error = QString("We are expecting value but found Array/Object/NULL. ").append("\nIndex: ").append(requstedObject);
        return QString("");
      }
      return getStringValue(qv);
    } else {
      error = QString("This is supposed to be an unreachable point. WTF?\nIndex: ").append(requstedObject);
      return QString("");
    }
  }
  
  return QString("");
}

int JsonData::intToString(const QString &s) {
  bool c;
  int number = s.toInt(&c, 0xA);
  if(!c) {
    error.append("Invalid number to access\n");
  }
  return number;
}
bool JsonData::isValue(QJsonValue qjv) {
  return !qjv.isArray() && !qjv.isObject();
}

QString JsonData::getError() {
  return error;
}

QString JsonData::getStringValue(QJsonValue jv) {
  if(jv.isBool()) {
    
  } else if(jv.isDouble()) {
    return QString::number(jv.toDouble());
  } else if(jv.isString()) {
    return jv.toString();
  }
  return QString("");
}
