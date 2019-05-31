#ifndef __JSON_DATA_H_
#define __JSON_DATA_H_
#include <QtCore>
#include <QJsonValue>
#include <QList>

class JsonData {
private:
  QJsonValue jsonValue;
  QString error;
public:
  JsonData(QJsonValue jsonValue);
  QString getError();
  QString getValue(const QString &search, const QString &separator);

protected:
  int intToString(const QString &s);
  bool isValue(QJsonValue qjv);
  QString getStringValue(QJsonValue jv);
};
#endif
