#include <QtTest/QtTest>
#include <QList>
#include "objectlist.h"
#include "log.h"


class TestObjectList: public QObject
{
    Q_OBJECT

public:
 TestObjectList();
private slots:
    void testCreateList();
};

TestObjectList::TestObjectList() {}

void TestObjectList::testCreateList()
{
  INFO("START_____________________________________________________");
  ObjectParser obj1;
  QList<ObjectDetails> qList = obj1.createList(QString("1.2.obj.3"));
  INFO(QString("Message: ").append(obj1.getError()));
  QCOMPARE(qList.size(), 4);
  INFO("Start Testing: 0");
  QCOMPARE(qList[0].oIndex, QString("1"));
  QCOMPARE(qList[0].oType, ObjectDetails::JsonArray);
  QCOMPARE(qList[0].isLast, false);
  INFO("End Testing: 0\nStart: Testing 1");
  QCOMPARE(qList[1].oIndex, QString("2"));
  QCOMPARE(qList[1].oType, ObjectDetails::JsonArray);
  QCOMPARE(qList[1].isLast, false);
  INFO("End Testing: 1\nStart: Testing 2");
  QCOMPARE(qList[2].oIndex, QString("obj"));
  QCOMPARE(qList[2].oType, ObjectDetails::JsonObject);
  QCOMPARE(qList[2].isLast, false);
  INFO("End Testing: 2\nStart: Testing 3");
  QCOMPARE(qList[3].oIndex, QString("3"));
  QCOMPARE(qList[3].oType, ObjectDetails::JsonArray);
  QCOMPARE(qList[3].isLast, true);
  INFO("End Testing: 3\n");

  ObjectParser obj2;
  QList<ObjectDetails> qList2 = obj2.createList(QString("ob1j.abc.obj.000001"));
  INFO(QString("Message: ").append(obj2.getError()));
  QCOMPARE(qList2.size(), 4);

  INFO("Start Testing: 0");
  QCOMPARE(qList2[0].oIndex, QString("ob1j"));
  QCOMPARE(qList2[0].oType, ObjectDetails::JsonObject);
  QCOMPARE(qList2[0].isLast, false);
  INFO("End Testing: 0\nStart Testing: 1");
  QCOMPARE(qList2[1].oIndex, QString("abc"));
  QCOMPARE(qList2[1].oType, ObjectDetails::JsonObject);
  QCOMPARE(qList2[1].isLast, false);
  INFO("End Testing: 1\nStart: Testing 2");
  QCOMPARE(qList2[2].oIndex, QString("obj"));
  QCOMPARE(qList2[2].oType, ObjectDetails::JsonObject);
  QCOMPARE(qList2[2].isLast, false);
  INFO("End Testing: 2\nStart: Testing 3");
  QCOMPARE(qList2[3].oIndex, QString("000001"));
  QCOMPARE(qList2[3].oType, ObjectDetails::JsonArray);
  QCOMPARE(qList2[3].isLast, true);
  INFO("End Testing: 3");

  ObjectParser obj3;
  QList<ObjectDetails> qList3 = obj3.createList(QString("ob1j"));
  INFO(QString("Message: ").append(obj3.getError()));
  QCOMPARE(qList3.size(), 1);
  QCOMPARE(qList3[0].oIndex, QString("ob1j"));
  QCOMPARE(qList3[0].oType, ObjectDetails::JsonObject);
  QCOMPARE(qList3[0].isLast, true);

  INFO("__TESTING_ERROR__");
  ObjectParser obj4;
  QList<ObjectDetails> qList4 = obj4.createList(QString("obj1,123"));
  INFO(QString("Message: ").append(obj4.getError()));
  QCOMPARE(qList4.size(), 0);

  
  ObjectParser obj5;
  QList<ObjectDetails> qList5 = obj5.createList(QString("1ob1j"));
  INFO(QString("Message: ").append(obj5.getError()));
  QCOMPARE(qList5.size(), 0);
  
  ObjectParser obj6;
  QList<ObjectDetails> qList6 = obj6.createList(QString("ob1j..123"));
  INFO(QString("Message: ").append(obj6.getError()));
  QCOMPARE(qList6.size(), 0);

  INFO("END_______________________________________________________");
}

QTEST_MAIN(TestObjectList)
#include "testobjectlist.moc"

