#include <QtTest/QtTest>
#include <QJsonValue>
#include "fileprocessor.h"
#include "log.h"

class TestFileProcessor: public QObject
{
    Q_OBJECT

public:
 TestFileProcessor();
private slots:
    void testOne();
};

TestFileProcessor::TestFileProcessor() {

}


void TestFileProcessor::testOne()
{
  INFO("START__________________________________________________________________________________________________");
  FileProcessor fp;
  fp.buildFromConfiguration("Just test ");

  INFO("END____________________________________________________________________________________________________");
}

QTEST_MAIN(TestFileProcessor)
#include "testfileprocessor.moc"

