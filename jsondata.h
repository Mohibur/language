#ifndef __JSON_DATA_H_
#define __JSON_DATA_H_
#include <QtCore>
#include <QJsonDocument>
#include <QList>

class JsonData {
private:
  QJsonDocument jsonDoc;
  QJsonDocument currentDoc;
  QString error;
public:
  JsonData(QJsonDocument jsonDoc);
  QString getError();
  QString getValue(const QString &search);

protected:
  void getNextObject(const QString s);
  QVariant getString(const QString &search);
  int intToString(const QString &s);
  QList<QString> getIdAndIndex(const QString &s);
};
#endif
