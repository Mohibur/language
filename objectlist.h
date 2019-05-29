#ifndef __OBJECT_LIST_H
#define __OBJECT_LIST_H

#define <QList>
#include "objectlist.h"
class ObjectList;

class ObjectParser {
private:
  QString error;
  QRegularExpression number;
  QRegularExpression objName;

private:
  ObjectList& getTheObject(const QString &str);

public:
  QList<ObjectList> createList(const QString &str);
  const QString& getError();
}

class ObjectList {
public:
  QString oIndex;
  ObjectType oType;
  bool isLast;
public:
  enum ObjectType {
    JsonObject=0,
    JsonArray
  };

}
#endif
