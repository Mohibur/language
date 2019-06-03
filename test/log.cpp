#include "log.h"
#include <QDateTime>

void TestLog::log(const QString &s, const QString &info) {
  QTextStream(stdout) << QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")  << info << " "<< s << "\n" << endl;
}

