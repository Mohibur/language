#include <QtTest/QtTest>
#include "testqstring.h"

void TestQString::toUpper()
{
    QString str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
}

QTEST_MAIN(TestQString)
#include "testqstring.moc"

