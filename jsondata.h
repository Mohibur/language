#ifndef __JSON_DATA_H_
#define __JSON_DATA_H_
#include <QtCore>


class JsonData {
private:
  JsonDocument jsonDoc;
  QStrig error;
public:
  JsonData(JsonDocument jsonDoc);
  QString getString(const QString &search);
  const QString getError();

protected:
  QString []getIdAndIndex(const QString &s);
}
#endif