#include "jsondata.h"


JsonData::JsonData(JsonDocument jsonDoc) {
  this->jsonDoc = jsonDoc;
}

QString JsonData::getString(const QString &search) {
  QStringList list;
  list = str.split('.');
  for ( const auto& index : list  ) {
    if()
  }
}


// 0 = object
// 1 = array
// 2 = remaining
QString[] JsonData::getIdAndIndex(const QString &s) {
  QString toRet[3];
  int start = s.indexOf('[');
  int end = s.indexOf(']');

  if((start == -1 && end != -1) || (start != -1 && end == -1)) {
    error.append("Improper brackets []");
  }

  if(start != -1 && end != -1) {
    toRet[0] = s.mid(0, start);
    toRet[1] = s.mid(start + 1, end - 4);
    toRet[2] = s.mid(end + 1, s)
  }
}


QString JsonData::getError() {
  return error;
}