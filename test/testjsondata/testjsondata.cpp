#include <QtTest/QtTest>
#include <QJsonValue>
#include "jsondata.h"
#include "log.h"

class TestJasonData: public QObject
{
    Q_OBJECT

public:
 TestJasonData();
private slots:
    void testTest();
};

TestJasonData::TestJasonData() {

}


void TestJasonData::testTest()
{
  INFO("START__________________________________________________________________________________________________");
  QString jsontxt("[[10, 30, [1, 2, 3, 4]], [\"It's my life\", \"It's now or never\"], {\"Mistry\":[1, 2, 3], \"Yesterday\":{\"fish\": 10}, \"1981\":\"haha\"}]");
  QJsonDocument doc = QJsonDocument::fromJson(jsontxt.toUtf8());
  QJsonValue qjv;
  qjv = doc.array();
  JsonData jd(qjv);
  QString r = jd.getValue(QString("0.1"), ".");
  QCOMPARE(r, QString("30"));

  JsonData jd2(qjv);
  QString r2 = jd2.getValue(QString("2.\"1981\""), ".");
  QCOMPARE(r2, QString("haha"));
  INFO("END____________________________________________________________________________________________________");
}

QTEST_MAIN(TestJasonData)
#include "testjsondata.moc"

