#include "jsondata.h"


JsonData::JsonData(QJsonDocument jsonDoc) {
  this->jsonDoc = jsonDoc;
}
// search example: abc.[10].def.[0]
QString JsonData::getValue(const QString &search) {
  ObjectParser obp;
  QList<ObjectList> obl = obp.createList(search);
  if(obl.isEmpty()) {
    error.append(obp.getError());
    return QString("");
  }
  // We are splitting and creating set using ObjectList. We will extract ObjectList to figure out the final value
  // #TODO
}

QVariant JsonData::getString(const QString &search) {
  QString process(search);
  QStringList stringList = process.split(".");
  int lSize = stringList.size();
  for(int i=0; i < lSize; i++) {
    getNextObject(stringList[i]);
  }
  return currentDoc.toVariant();
}

int JsonData::intToString(const QString &s) {
  bool c;
  int number = pm[1].toInt(&c, 0xA);
  if(!c) {
    error.append("Invalid number to access\n");
  }
  return number;
}

void JsonData::getNextObject(const QString s) {
  QList<QString> pm = getIdAndIndex(s);
  if(pm.size()==0) return;
  if(pm[0].isEmpty()) {
    error.append("Bad String\n");
    return;
  }
  if(currentDoc.isObject()) {
    currentDoc = QJsonDocument((currentDoc.object())[pm[0]]);// get the object
  } else if(currentDoc.isArray()) {
    currentDoc = QJsonDocument((currentDoc.array())[pm[0]]);
  }
  int number = intToString(pm[1]);
  if(!error.isEmpty()) return;
  while(true) {
    if(!l[1].isEmpty()) {
      return;
    }
    if(currentDoc.isAarray()) {
      currentDoc = currentDoc[number];
    } else {
      error.append("Array Requested but found non array\n");
      return;
    }
    
    if(pm[2].isEmpty()) {
      return;
    }
    pm = getIdAndIndex(pm[2]);
  }
}

// 0 = object
// 1 = array
// 2 = remaining
QList<QString> JsonData::getIdAndIndex(const QString &s) {
  QList<QString> toRet;
  int start = s.indexOf('[');
  int end = s.indexOf(']');

  if((start == -1 && end != -1) || (start != -1 && end == -1) || start > end) {
    error.append("Improper brackets []\n");
    return QList<QString>();
  }

  if(start != -1 && end != -1) {
    if(start != 0)
      toRet.push_back( s.mid(0, start) );
    else
      toRet.push_back( QString() );
    toRet.push_back(s.mid(start+1, end - 5));
    toRet.push_back(s.mid(end + 1, s.size()));
  }
  return toRet;
}

QString JsonData::getError() {
  return error;
}
