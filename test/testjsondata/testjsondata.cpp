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
  QString jsontxt("[[10, 30, [1, 2, 3, 4]], [\"It's my life\", \"It's now or never\"], {\"Mistry\":[1, 2, 3], \"Yesterday\":{\"fish\": 10}}]");
  QJsonDocument doc = QJsonDocument::fromJson(jsontxt.toUtf8());
  QJsonValue qjv;
  if(doc.isArray()) { 
    qjv = doc.array();
  }
  int a = (int)qjv.isArray();
  INFO(QString("Testing Array: ").append(QString::number(a)));
  int b  = (int)qjv.isBool();
  INFO(QString("Testing bool: ").append(QString::number(b)));
  int d = (int)qjv.isDouble();
  INFO(QString("Testing double: ").append(QString::number(d)));
  int n = (int)qjv.isNull();
  INFO(QString("Testing null: ").append(QString::number(n)));
  int o = (int)qjv.isObject();
  INFO(QString("Testing object: ").append(QString::number(o)));
  int s = (int)qjv.isString();
  INFO(QString("Testing String: ").append(QString::number(s)));
  int u = (int)qjv.isUndefined();
  INFO(QString("Testing undefined: ").append(QString::number(u)));
  INFO("__________________IS THIS WHAT IS THIS____________________");
  INFO(qjv.toString());
  
  JsonData jd(qjv, ".");
  QString r = jd.getValue(QString("0.1"));
  FATAL(QString("Messgae: ").append(jd.getError()));
  QCOMPARE(r, QString("30"));
  INFO("END____________________________________________________________________________________________________");
}

QTEST_MAIN(TestJasonData)
#include "testjsondata.moc"

