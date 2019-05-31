#ifndef __JSON_DATA_H_
#define __JSON_DATA_H_
#include <QtCore>
#include <QJsonValue>
#include <QList>

class JsonData {
private:
  QJsonValue jsonValue;
  QString separator;
  QString error;
public:
  JsonData(QJsonValue jsonValue, const QString &separator);
  QString getError();
  QString getValue(const QString &search);

protected:
  int intToString(const QString &s);
  bool isValue(QJsonValue qjv);
};
#endif
