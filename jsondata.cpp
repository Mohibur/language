#include "jsondata.h"
#include "objectlist.h"


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
      return currentJson.toVariant().toString();
    } else if(list[i].isLast && (currentJson.isArray() || currentJson.isObject())) {
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
      continue;
    } else if(!list[i].isLast && currentJson.isObject()) {
      QJsonObject qjObject = currentJson.toObject();
      if(!qjObject.contains(list[i].oIndex)) {
        error = QString("Requsted object is not found.\nIndex: ").append(requstedObject);
        return QString("");
      }
      currentJson = qjObject[list[i].oIndex];
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
