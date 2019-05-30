#ifndef __OBJECT_LIST_H
#define __OBJECT_LIST_H

#include <QList>

class ObjectDetails;

class ObjectParser {
public:
  ObjectParser();
private:
  static const QString defaultSplit;
  QString error;
  QRegExp number;
  QRegExp objName;

private:
  ObjectDetails getTheObject(const QString &str);

public:
  QList<ObjectDetails> createList(const QString &str);
  QList<ObjectDetails> createList(const QString &str, const QString &split);
  const QString getError();
};

class ObjectDetails {
public:
  enum ObjectType {
    JsonObject = 0,
    JsonArray
  };

public:
  QString oIndex;
  ObjectType oType;
  bool isLast;
  
public:
  ObjectDetails& operator=(const ObjectDetails& other);
};
#endif
