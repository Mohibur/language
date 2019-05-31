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
  ObjectParser obj_r1;
  QList<ObjectDetails> qList_r1 = obj_r1.createList(QString("1.2.obj.3"));
  INFO(QString("Message: ").append(obj_r1.getError()));
  QCOMPARE(qList_r1.size(), 4);
  INFO("Start Testing: 0");
  QCOMPARE(qList_r1[0].oIndex, QString("1"));
  QCOMPARE(qList_r1[0].oType, ObjectDetails::JsonArray);
  QCOMPARE(qList_r1[0].isLast, false);
  INFO("End Testing: 0\nStart: Testing 1");
  QCOMPARE(qList_r1[1].oIndex, QString("2"));
  QCOMPARE(qList_r1[1].oType, ObjectDetails::JsonArray);
  QCOMPARE(qList_r1[1].isLast, false);
  INFO("End Testing: 1\nStart: Testing 2");
  QCOMPARE(qList_r1[2].oIndex, QString("obj"));
  QCOMPARE(qList_r1[2].oType, ObjectDetails::JsonObject);
  QCOMPARE(qList_r1[2].isLast, false);
  INFO("End Testing: 2\nStart: Testing 3");
  QCOMPARE(qList_r1[3].oIndex, QString("3"));
  QCOMPARE(qList_r1[3].oType, ObjectDetails::JsonArray);
  QCOMPARE(qList_r1[3].isLast, true);
  INFO("End Testing: 3\n");

  ObjectParser obj_r2;
  QList<ObjectDetails> qList_r2 = obj_r2.createList(QString("ob1j.abc.obj.000001"));
  INFO(QString("Message: ").append(obj_r2.getError()));
  QCOMPARE(qList_r2.size(), 4);

  INFO("Start Testing: 0");
  QCOMPARE(qList_r2[0].oIndex, QString("ob1j"));
  QCOMPARE(qList_r2[0].oType, ObjectDetails::JsonObject);
  QCOMPARE(qList_r2[0].isLast, false);
  INFO("End Testing: 0\nStart Testing: 1");
  QCOMPARE(qList_r2[1].oIndex, QString("abc"));
  QCOMPARE(qList_r2[1].oType, ObjectDetails::JsonObject);
  QCOMPARE(qList_r2[1].isLast, false);
  INFO("End Testing: 1\nStart: Testing 2");
  QCOMPARE(qList_r2[2].oIndex, QString("obj"));
  QCOMPARE(qList_r2[2].oType, ObjectDetails::JsonObject);
  QCOMPARE(qList_r2[2].isLast, false);
  INFO("End Testing: 2\nStart: Testing 3");
  QCOMPARE(qList_r2[3].oIndex, QString("000001"));
  QCOMPARE(qList_r2[3].oType, ObjectDetails::JsonArray);
  QCOMPARE(qList_r2[3].isLast, true);
  INFO("End Testing: 3");

  ObjectParser obj_r3;
  QList<ObjectDetails> qList_r3 = obj_r3.createList(QString("ob1j"));
  INFO(QString("Message: ").append(obj_r3.getError()));
  QCOMPARE(qList_r3.size(), 1);
  QCOMPARE(qList_r3[0].oIndex, QString("ob1j"));
  QCOMPARE(qList_r3[0].oType, ObjectDetails::JsonObject);
  QCOMPARE(qList_r3[0].isLast, true);
  
  ObjectParser obj_r4;
  QList<ObjectDetails> qList_r4 = obj_r4.createList(QString("1.\"abc\".\"000001\""));
  INFO(QString("Message: ").append(obj_r4.getError()));
  QCOMPARE(qList_r4.size(), 3);
  QCOMPARE(qList_r4[0].oIndex, QString("1"));
  QCOMPARE(qList_r4[0].oType, ObjectDetails::JsonArray);
  QCOMPARE(qList_r4[0].isLast, false);
  QCOMPARE(qList_r4[1].oIndex, QString("abc"));
  QCOMPARE(qList_r4[1].oType, ObjectDetails::JsonObject);
  QCOMPARE(qList_r4[1].isLast, false);
  QCOMPARE(qList_r4[2].oIndex, QString("000001"));
  QCOMPARE(qList_r4[2].oType, ObjectDetails::JsonObject);
  QCOMPARE(qList_r4[2].isLast, true);


  INFO("__TESTING_ERROR__");
  ObjectParser obj1;
  QList<ObjectDetails> qList1 = obj1.createList(QString("obj1,123"));
  INFO(QString("Message: ").append(obj1.getError()));
  QCOMPARE(qList1.size(), 0);

  
  ObjectParser obj2;
  QList<ObjectDetails> qList2 = obj2.createList(QString("ob1j..123"));
  INFO(QString("Message: ").append(obj2.getError()));
  QCOMPARE(qList2.size(), 0);

  INFO("END_______________________________________________________");
}

QTEST_MAIN(TestObjectList)
#include "testobjectlist.moc"

