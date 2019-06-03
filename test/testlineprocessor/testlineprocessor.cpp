#include <QtTest/QtTest>
#include <QJsonValue>
#include "lineprocessor.h"
#include "log.h"

class TestLineProcessor: public QObject
{
    Q_OBJECT

public:
 TestLineProcessor();
private slots:
    void testTest();
};

TestLineProcessor::TestLineProcessor() {

}

void TestLineProcessor::testTest()
{
  INFO("START__________________________________________________________________________________________________");
  QString jsontxt("[[10, 30, [1, 2, 3, 4]], [\"It's my life\", \"It's now or never\"], {\"Mistry\":[1, 2, 3], \"Yesterday\":{\"fish\": 100}, \"1981\":\"haha\"}]");
  QJsonDocument doc = QJsonDocument::fromJson(jsontxt.toUtf8());
  QJsonValue qjv;
  qjv = doc.array();
  JsonData jd(qjv);
  LineProcessor lp(&jd, QString("."), QString("<?") , QString("?>"));
  /*----------------------------------------*/
  QString qs1("The price of the tomato is 100");
  QString output1 = lp.processString(qs1);
  QCOMPARE(output1, QString("The price of the tomato is 100"));
  /*----------------------------------------*/
  QString qs2("The price of the lemon is <?");
  QString output2 = lp.processString(qs2);
  QCOMPARE(output2, QString("The price of the lemon is <?"));
  /*----------------------------------------*/
  QString qs3("The price of the potato is ?>");
  QString output3 = lp.processString(qs3);
  QCOMPARE(output3, QString("The price of the potato is ?>"));
  /*----------------------------------------*/
  QString qs4("The price of the icecream is <\?\?>");
  QString output4 = lp.processString(qs4);
  QCOMPARE(output4, QString(""));
  QCOMPARE(lp.getError(), QString("<\?\?> combination found. Throwing this as error."));
  /*----------------------------------------*/
  QString qs5("The price of the potato is <?0.1?> dollar. But the price of the fish is <?2.Yesterday.fish?> dollar. <?2.\"1981\"?>. This will be as it is ?> without change <?ding");
  QString output5 = lp.processString(qs5);
  QCOMPARE(output5, QString("The price of the potato is 30 dollar. But the price of the fish is 100 dollar. haha. This will be as it is ?> without change <?ding"));
  /*----------------------------------------*/
  QString qs6("<?1.0?><?1.1?>");
  QString output6 = lp.processString(qs6);
  QCOMPARE(output6, QString("It's my lifeIt's now or never"));
  /*----------------------------------------*/
  
  INFO("END____________________________________________________________________________________________________");
}

QTEST_MAIN(TestLineProcessor)
#include "testlineprocessor.moc"

