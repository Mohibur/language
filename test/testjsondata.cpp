#include <QtTest/QtTest>
#include "jsondata.h"

class TestJasonData: public QObject, public JsonData
{
    Q_OBJECT

public:
 TestJasonData();
private slots:
    void testGetIdAndIndex();
};

TestJasonData::TestJasonData():JsonData(QJsonDocument()) {

}


void TestJasonData::testGetIdAndIndex()
{
    QString str = "bingo[100][20][2]";
    QStringList arr = this->getIdAndIndex(str);
    QCOMPARE(arr[0], QString("bingo"));
    QCOMPARE(arr[1], QString("100"));
    QCOMPARE(arr[2], QString("[20][2]"));
}

QTEST_MAIN(TestJasonData)
#include "testjsondata.moc"

